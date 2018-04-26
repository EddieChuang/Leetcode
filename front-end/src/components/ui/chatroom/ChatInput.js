
import React, { Component } from 'react'
import axios from 'axios'
// require('font-awesome/scss/font-awesome.scss')
// url
import {URL_UPLOADFILE} from '../../../constants/url'

class ChatInput extends Component {
    constructor(props) {
        super(props)
        this.state = { 
          label: this.props.label,
          user: this.props.user,
          chatInput: '',
          image: undefined
        }
    }
    
    onSubmit = e => {
        e.preventDefault()
        this.setState({ chatInput: '' })
        let text = this.state.chatInput
        let image = this.state.image

        // send file
        if(typeof image !== 'undefined'){
            this.uploadImage(image)
        }
        
        // send text
        if(text.trim() !== "")
            this.props.onSend(text)
    }

    textChangeHandler = e => {
      this.setState({ chatInput: e.target.value })
    }

    uploadImage = (image) => {
      console.log('uploadImage', image)
      let data = new FormData()
      data.append("file", image)
      data.append("label", this.state.label)
      data.append("fileType", "image")
      axios.post(URL_UPLOADFILE, data)
        .then( res => {
          console.log(res)
          this.props.onSendImage(res.data.url)
        })
        .catch( err => {
          console.log(err.response)
        })
    }

    onSelectImage = () => {
      console.log('onSelectFile')
      this.refs.imageid.click()

    }

    onChangeImage = e => {
        console.log("onChangeImage", e.target.files[0])
        let image = e.target.files[0]
        this.setState({image})
        this.refs.imageName.innerText = 
          typeof image !== 'undefined' ? image.name : ""
        
    }

    render() {
        return (
          <form className="chat-input" onSubmit={this.onSubmit}>
            {/* <div className="input"> */}
              <div style={{display:'inline-block'}} className="fa fa-2x fa-image" onClick={this.onSelectImage}>
                <input 
                  ref="imageid" 
                  type="file" 
                  accept="image/*"
                  onChange={this.onChangeImage}
                  style={{display:'none'}}
                  hidden 
                />
              </div>
              <label style={{fontSize:"14px"}} ref="imageName"></label>
              <input type="text"
                className="input-msg"
                onChange={this.textChangeHandler}
                value={this.state.chatInput}
                placeholder="輸入訊息 ..."
                required>
                
              </input>
              {/* <button> */}
              <div 
                className="fa fa-2x fa-arrow-circle-right" 
                onClick={this.onSubmit}
                style={{position:'relative', top:'4px'}}
                />
              {/* </button> */}
            {/* </div> */}
        </form>
        )
    }
}
export default ChatInput