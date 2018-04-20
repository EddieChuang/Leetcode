"use strict"
import React from 'react'
import ReactDOM from 'react-dom'
import axios from 'axios'
import {withRouter} from 'react-router-dom'

import {MenuItem, Form, Well, Col, Row, Grid, Panel, Modal, InputGroup, 
  HelpBlock, FormControl, FormGroup, Image, ControlLabel, SplitButton, DropdownButton} from 'react-bootstrap'
import {Card, CardImg, CardText, CardBody, CardTitle, CardSubtitle, 
  CardImgOverlay, CardDeck, Button, Popover, PopoverHeader, PopoverBody} from 'reactstrap'
import Clipboard from 'react-clipboard.js';

class RoomCard extends React.Component {

  constructor(props){
      super(props)
      this.state = {
        rooms: null,
        labelPopoverOpen: false,
        isActive: this.props.roomInfo!==null ? this.props.roomInfo.isActive : null,
        
        teams: []
      }

      this.open  = this.open.bind(this)
      this.enter = this.enter.bind(this)
      this.onCopySuccess = this.onCopySuccess.bind(this)
      this.closeGame = this.closeGame.bind(this)
      this.showTeams = this.showTeams.bind(this)
      this.toggleLabelPopover = this.toggleLabelPopover.bind(this)
      this.resetValidationState = this.resetValidationState.bind(this)     
       
  }

  onCopySuccess(){
      alert("複製到剪貼簿")
  }

  

  open(){
      this.setState({show: true})
  }

  toggleLabelPopover(){
      this.setState({labelPopoverOpen: !this.state.labelPopoverOpen})
  }

  closeGame(){
      let comfirmMsg = "關閉遊戲後將無法重啟，確定關閉遊戲？"
      if(confirm(comfirmMsg)){
          this.setState({isActive: false})
          let roomInfo = new FormData()
          roomInfo.append("label", this.props.roomInfo.label)
          roomInfo.append("isActive", false)
          axios.post("http://localhost:8000/chat/updateRoom/", roomInfo)
            .then((response) => {
                console.log(response)
            })
            .catch((response) => {
                console.log(response)
            })
      }
  }

  resetValidationState(type){
    
      switch(type){
        case 'teacher':
            this.setState({
              teacherVal: null,
              teacherErrMsg: ""
            })
            break
        case 'label':
            this.setState({
              labelVal: null,
              labelErrMsg: ""
            })
            break
        default:
            console.log("error type:", type)
            break
      }
    }

  
    validate(/*teacher, label, */game){
      
      this.setState({
        // teacherVal: teacher === "" ? 'error' : null,
        // labelVal: label === "" ? 'error' : null,
        // teacherErrMsg: teacher === "" ? '請輸入名稱' : "",
        // labelErrMsg: label === "" ? '請輸入標籤' : "",
        gameErrMsg: game === "選擇遊戲" ? "請選擇遊戲" : ""
      })


      return /*teacher === "" || label === "" || */game === "選擇遊戲"
  }

  

  showTeams(){

      // let label = this.props.roomInfo.label
      // let req  = new FormData()
      // req.append("label", label)
      // axios.post('http://localhost:8000/chat/getTeams/', req)
      //   .then((res) => {
      //       console.log(res)
      //       this.setState({teams: res.data.teams})
      //   })
      //   .catch((err) => {
      //       console.log(err)
      //   })

  }

  



  enter(){

      let label = this.props.roomInfo.label
      let name  = this.props.teacher.name
      let user  = {'type':'teacher', 'key':'', 'name':name, 'note':''}
      this.props.history.replace({
        pathname:'/chat',
        state: {'label':label, 'user':user}
      })

     
  }

  render(){

      console.log("render", "RoomCard")
      const teamsMenuItem = null//this.state.teams.map(function(team, i){
      //   return (
      //     <MenuItem eventKey={i} key={i}>
      //       <span className="glyphicon glyphicon-remove"></span>
      //       {team.name}
      //     </MenuItem>
      //   )
      // })
      // console.log(this.props)
      const keys = this.props.roomInfo!=null ? (this.props.roomInfo.keys.map((key, i)=>{
        return (
          <li key={key}>
            {key} 
            <Clipboard data-clipboard-text={this.props.roomInfo.label} onSuccess={this.onCopySuccess}>
              複製
            </Clipboard>
          </li>
        )
      })) : null

      const room = (
        <div className="room-card">
          <Card>
            <button type="button" id={"popover-"+this.props.roomInfo.label} className="btn btn-default btn-circle btn-room-status" onClick={this.toggleLabelPopover}>
              <span style={{"fontSize":"17px","right":"3px","top":"-2px"}} className="glyphicon glyphicon-info-sign"></span>
            </button>
            <Popover placement="right" isOpen={this.state.labelPopoverOpen} target={"popover-"+this.props.roomInfo.label} toggle={this.toggleLabelPopover}>
              <PopoverHeader style={{"fontSize":"15px", "textAlign":"center"}}>遊戲資訊</PopoverHeader>
              <PopoverBody>
                <ul style={{"padding":"0px 20px"}}>
                  <li>隊伍上限: {this.props.roomInfo.nTeam}</li>
                  <li>
                    金鑰: <ul>{keys}</ul>
                  </li>
                </ul>
              </PopoverBody>
            </Popover>
            
            <CardImg top width="100%" src="https://placeholdit.imgix.net/~text?txtsize=33&txt=318%C3%97180&w=318&h=180" alt="Card image cap" />
            <CardBody>
              <CardTitle style={{'fontWeight':'bold'}}>{this.props.roomInfo.game}</CardTitle>
              <DropdownButton style={{"marginBottom":"5px"}} title="隊伍" 
                id="team-dropdown" disabled={!this.state.isActive} onClick={this.showTeams}>
                {teamsMenuItem}
              </DropdownButton>
              <CardText><Button className={this.state.isActive ? "btn-success" : "btn-default"} onClick={this.closeGame} disabled={!this.state.isActive}>{this.state.isActive ? "遊戲進行中" : "遊戲已結束"}</Button></CardText>
              <Button className="center-align btn-primary" disabled={!this.state.isActive} onClick={this.enter}>進入遊戲</Button>
            </CardBody>
          </Card>
        </div>
      )

      return(
        <div>
          {room}
        </div>
      )
  }
}

export default withRouter(RoomCard)