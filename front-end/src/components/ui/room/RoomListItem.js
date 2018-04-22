"use strict"
import React from 'react'
import {Badge} from 'react-bootstrap'
import {Popover, PopoverHeader, PopoverBody} from 'reactstrap'
import {withRouter} from 'react-router-dom'
import Clipboard from 'react-clipboard.js';

class RoomListItem extends React.Component {

  constructor(props){
      super(props)
      this.state = {
        room: this.props.room,
        unread: 0,
        labelPopoverOpen: false
      }
      this.onEnter = this.onEnter.bind(this)
      this.onCopySuccess = this.onCopySuccess.bind(this)
      this.toggleLabelPopover = this.toggleLabelPopover.bind(this)
  }

  componentWillReceiveProps(props){
    if(props.unread.label === this.state.room.label){
        this.setState({unread: this.state.unread + props.unread.n})
    }
  }

  toggleLabelPopover(e){
    // e.stopPropagation()
    this.setState({labelPopoverOpen: !this.state.labelPopoverOpen})
  }

  onCopySuccess(){
    alert("複製到剪貼簿")
  }

  onEnter(e){
    // console.log('onEnter', this.state.room.label)
    // this.setState({unread: 0})
    this.setState({unread: 0})
    
    this.props.onEnter(this.state.room.label)
    
    // this.props.enter(localStorage.username, this.state.room.label)
  }
  

  render(){

      const keys = this.state.room!=null ? (this.state.room.keys.map((key, i)=>{
        return (
          <li key={key}>
             
            <Clipboard data-clipboard-text={key} onSuccess={this.onCopySuccess}>
              <span className="glyphicon glyphicon-copy"/>
            </Clipboard>
            {key}
          </li>
        )
      })) : null
      
      let isActive = this.state.room.label===this.props.activeLabel
      return(
        <div className={"item" + (isActive ? " item-active" : "")} onClick={this.onEnter}>
          <button type="button" id={"popover-"+this.state.room.label} className="btn btn-default btn-circle btn-room-status" onClick={this.toggleLabelPopover}>
            <span style={{"fontSize":"14px","right":"4px","top":"-3px"}} className="glyphicon glyphicon-info-sign"></span>
          </button>
          <Popover placement="right" isOpen={this.state.labelPopoverOpen} target={"popover-"+this.state.room.label} toggle={this.toggleLabelPopover}>
            <PopoverHeader style={{"fontSize":"15px", "textAlign":"center"}}>遊戲資訊</PopoverHeader>
            <PopoverBody>
              <ul >
                <li>隊伍上限: {this.state.room.nTeam}</li>
                <li>
                  金鑰: <ul style={{"paddingLeft":"5px"}}>{keys}</ul>
                </li>
              </ul>
            </PopoverBody>
          </Popover>
          <h4>{this.state.room.game}</h4>
          {this.state.unread !=0 ? (<Badge style={{color:'orange'}} >{this.state.unread}</Badge>) : ('')}
        </div>
      )
  }
}

export default withRouter(RoomListItem)