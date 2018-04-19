"use strict"
import React from 'react'
import {Button, Badge} from 'react-bootstrap'
import {Card, CardImg, CardBody, CardTitle, Popover, PopoverHeader, PopoverBody} from 'reactstrap'
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
    console.log('componentWillReceiveProps', props)
    if(props.unread.label === this.state.room.label){
        console.log('aaa', this.state.unread + props.unread.n)
        this.setState({unread: this.state.unread + props.unread.n})
    }
  }

  toggleLabelPopover(){
    this.setState({labelPopoverOpen: !this.state.labelPopoverOpen})
  }

  onCopySuccess(){
    alert("複製到剪貼簿")
  }

  onEnter(){
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
            {key} 
            <Clipboard data-clipboard-text={key} onSuccess={this.onCopySuccess}>
              複製
            </Clipboard>
          </li>
        )
      })) : null
      
      console.log(this.state)
      return(
        <div className="item" onClick={this.onEnter}>
          <button type="button" id={"popover-"+this.state.room.label} className="btn btn-default btn-circle btn-room-status" onClick={this.toggleLabelPopover}>
            <span style={{"fontSize":"14px","right":"4px","top":"-3px"}} className="glyphicon glyphicon-info-sign"></span>
          </button>
          <Popover placement="right" isOpen={this.state.labelPopoverOpen} target={"popover-"+this.state.room.label} toggle={this.toggleLabelPopover}>
            <PopoverHeader style={{"fontSize":"15px", "textAlign":"center"}}>遊戲資訊</PopoverHeader>
            <PopoverBody>
              <ul style={{"padding":"0px 20px"}}>
                <li>隊伍上限: {this.state.room.nTeam}</li>
                <li>
                  金鑰: <ul>{keys}</ul>
                </li>
              </ul>
            </PopoverBody>
          </Popover>
          <h4>{this.state.room.game}</h4>
          {this.state.unread !=0 ? (<Badge style={{color:'orange'}} >{this.state.unread}</Badge>) : ('')}
          {/* <CardImg top width="100%" src="https://placeholdit.imgix.net/~text?txtsize=33&txt=318%C3%97180&w=318&h=180" alt="Card image cap" /> */}
          {/* <CardBody> */}
            {/* <CardTitle style={{'fontWeight':'bold'}}>{this.state.room.game}</CardTitle>               */}
            {/* <Button className="center-align btn-primary" onClick={this.props.enter}>進入遊戲</Button> */}
          {/* </CardBody> */}
        </div>
      )
  }
}

export default withRouter(RoomListItem)