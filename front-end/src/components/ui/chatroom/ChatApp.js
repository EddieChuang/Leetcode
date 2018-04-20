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
          label: '',
          user: null,  //{'type', 'key', 'name', 'note}
          socketURL: '',
          messages: [] 
        }
        this.receiveMessage = this.receiveMessage.bind(this)
    }

    componentWillMount(){
      
        let {label, user} = this.props
        let socketURL = 'ws://localhost:8000/ws/chat/' + label + '/'
        
        this.setState({label:label, user:user, socketURL:socketURL})
        // console.log(label, user)
    }

    // send message to server
    sendHandler = message => {
        
        const socket = this.refs.socket
        socket.state.ws.send(JSON.stringify({
          'type': 'chat',
          'key': this.state.user.key,
          'username': this.state.user.name,
          'message': message,
          'label': this.state.label
        }))
    }

    // receive message from server
    receiveMessage(data){
      
        data = JSON.parse(data)
        // console.log(data)
        if(data.type === 'init'){
            this.setState({messages:[]})
            data.messages.forEach((msg) => {
                msg.fromMe = msg.username === this.state.user.name
                this.addMessage(msg)
            })
        } else if(data.type === 'chat' || data.type === 'leave'){
            let msg = {
              'username': data.username,
              'key': data.key,
              'message':  data.message,
              'timestamp': data.timestamp,
              'fromMe':   data.username === this.state.user.name
            }
            console.log(data.username, this.state.user.name)
            if(data.username !== this.state.user.name){
                this.props.onUnread(this.state.label, 1)
            }

            this.addMessage(msg)
        }
    }
    
    addMessage = message => {
        const { messages } = this.state
        messages.push(message)
        this.setState({ messages })
    }

    componentWillUnmount(){
      
      console.log('chatApp unmount')
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