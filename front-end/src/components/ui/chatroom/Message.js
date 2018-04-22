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
          <div className="message-text">
            { this.props.text }
          </div>
          {/* <br/> */}
          <div className={fromMe?'time-left':'time-right'}>
            {this.props.timestamp}
          </div>
            
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