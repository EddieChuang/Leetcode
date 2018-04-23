import React, { Component } from 'react'
import Messages from './Messages'
import Websocket from 'react-websocket'

// ui
import {ChatInput} from '.'

// require('../../style/message.scss')

class ChatApp extends Component {
    constructor(props) {
        super(props)
        this.state = { 
          label: this.props.label,
          user: this.props.user,  //{'type', 'key', 'name', 'note}
          socketURL: '',
          messages: [] // [{'key', 'usertype', 'username', 'message', 'timestamp'}, ...]
        }
        this.receiveMessage = this.receiveMessage.bind(this)
    }

    componentWillMount(){
      
        let {label, user} = this.state
        let socketURL = 'ws://localhost:8000/ws/chat/' + label + '/' + user.name + '/'
        
        this.setState({label:label, user:user, socketURL:socketURL})
    }

    // send message to server
    sendHandler = text => {
        
        let {label, user} = this.state
        const socket = this.refs.socket
        socket.state.ws.send(JSON.stringify({
          'type': 'chat',
          'key': user.key,
          'usertype': user.type,
          'username': user.name,
          'text': text,
          'label': label
        }))
    }

    // receive message from server
    receiveMessage(data){

        let {label, user} = this.state
        
        data = JSON.parse(data)
        if(data.type === 'init'){
            this.setState({messages:[]})
            data.messages.forEach((msg) => {
                msg.fromMe = msg.username === user.name
                this.addMessage(msg)
            })
        } else if(data.type === 'join'){
            let msg = data.message
            this.props.onJoin(this.state.label, msg.key, msg.username)
        } else if(data.type === 'chat' || data.type === 'leave'){
            let msg = data.message
            msg.fromMe = msg.username === user.name

            if(msg.username !== user.name && data.type === 'chat'){
                this.props.onUnread(label, 1)
            }
            
            this.addMessage(msg)
        }
    }
    
    addMessage = message => {
        const { messages } = this.state
        messages.push(message)
        this.setState({ messages })
    }

    render() {
        return (
            <div className="msg-container">
              <Messages messages={this.state.messages} />
              <ChatInput onSend={this.sendHandler} />
              <Websocket 
                ref="socket"
                url={this.state.socketURL} 
                onMessage={this.receiveMessage} reconnect={true}/>
            </div>
        )
    }
}

export default ChatApp