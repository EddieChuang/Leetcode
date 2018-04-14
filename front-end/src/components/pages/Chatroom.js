import React, { Component } from 'react'
import {withRouter} from 'react-router-dom';
import ChatApp from '../ui/ChatApp'
import Websocket from 'react-websocket'
// require('../../style/message.scss')
// require('../../style/chatroom.scss')

class Chatroom extends Component {
    constructor(props) {
        super(props)
        this.state = this.props.location.state
    }
    
    render() {
        return <ChatApp user={this.state.user} label={this.state.label} onUnread={this.props.onUnread}/>
    }

}

export default withRouter(Chatroom)