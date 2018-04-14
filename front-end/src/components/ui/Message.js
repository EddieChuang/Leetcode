import React, { Component } from 'react'

class Message extends Component {


  parseMessage(){



  }

  render() {
    const fromMe = this.props.fromMe ? 'from-me' : ''
    // const text   = 
    // let msgbody  = this.props.fromMe ? (
    //   <div className='message-body'>
    //     { this.props.message }
    //   </div>
    //   <font>{this.props.timestamp}</font>) : ()


    return (
      <div className={`message ${fromMe}`}>
        <div className='username'>
          { this.props.username }
        </div>
        
        <div className="message-box">
          <div style={{'maxWidth':'90%'}}>{ this.props.message }</div>
          <br/>
          <span className={fromMe?'time-right':'time-left'}>
            {this.props.timestamp}
          </span>
        </div>
        
        {/* <div className='message-body'> */}
          
          {/* <div className='message-body-text'> */}
            {/* { this.props.message } */}
          {/* </div> */}
          {/* <div className='message-body-time' >
            <font >{this.props.timestamp}</font>
          </div> */}
        {/* </div> */}
        
      </div>
    )
  }
}

export default Message