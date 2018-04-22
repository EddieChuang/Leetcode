
import React, { Component } from 'react'
// require('font-awesome/scss/font-awesome.scss')

class ChatInput extends Component {
    constructor(props) {
        super(props)
        this.state = { chatInput: '' }
    }
    
    submitHandler = e  => {
        e.preventDefault()
        this.setState({ chatInput: '' })
        this.props.onSend(this.state.chatInput);
    }

    textChangeHandler = e => {
        this.setState({ chatInput: e.target.value })
    }

    imageUpload = () => {
      this.refs.imageid.click()
    }

    handleImageChange = e => {
        // const image = await axios.post(e.target.files[0])
    }

    render() {
        return (
          <form className="chat-input" onSubmit={this.submitHandler}>
            {/* <div className="input"> */}
              {/* <div className="fa fa-2x fa-image" onClick={this.imageUpload}>
                <input 
                  ref="imageid" 
                  type="file" 
                  accept="image/*"
                  onChange={this.handleImageChange}
                  hidden 
                />
              </div> */}
              <input type="text"
                className="input-msg"
                onChange={this.textChangeHandler}
                value={this.state.chatInput}
                placeholder="輸入訊息 ..."
                required>
                
              </input>
              <div 
                className="fa fa-2x fa-arrow-circle-right" 
                onClick={this.submitHandler}
                style={{position:'relative', top:'4px'}}
                />
            {/* </div> */}
        </form>
        )
    }
}
export default ChatInput