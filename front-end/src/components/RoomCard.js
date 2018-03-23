"use strict"
import React from 'react'
import ReactDOM from 'react-dom'
import axios from 'axios'
import {withRouter} from 'react-router-dom'

import {MenuItem, Form, Well, Col, Row, Grid, Panel, Modal, InputGroup, HelpBlock, FormControl, FormGroup, DropdownButton, Image, ControlLabel, SplitButton} from 'react-bootstrap'
import {Card, CardImg, CardText, CardBody, CardTitle, CardSubtitle, CardImgOverlay, CardDeck, Button} from 'reactstrap'
class RoomCard extends React.Component {

  constructor(props){
      super(props)
      this.state = {
         rooms: null,
        //  teacherVal: null,
        //  labelVal: null,
         gameErrMsg: "",
        //  teacherErrMsg: "",
        //  labelErrMsg: "",
         game: "選擇遊戲",
         show: false,
         isActive: this.props.roomInfo!==null ? this.props.roomInfo.isActive : null
      }
      this.open  = this.open.bind(this)
      this.close = this.close.bind(this)
      this.enter = this.enter.bind(this)
      this.toggleActive = this.toggleActive.bind(this)
      this.handleCreate = this.handleCreate.bind(this)
      this.handleSelect = this.handleSelect.bind(this)
      this.resetValidationState = this.resetValidationState.bind(this)
      
      console.log("constructor", "RoomCard")
  }

  componentWillMount(){
    console.log("componentWillMount", "RoomCard")
    
  }

  componentDidMount(){
    console.log("componentDidMount", "RoomCard")
  }

  componentWillUnmount(){
    console.log("componentWillUnmount", "RoomCard")
  }

  close(){
      // ReactDOM.findDOMNode(this.refs.teacher).value = ""
      // ReactDOM.findDOMNode(this.refs.label).value = ""
      this.setState({
        show: false,
        game: "選擇遊戲",
        // teacherVal: null,
        // labelVal: null,
        // teacherErrMsg: "",
        // labelErrMsg: "",
        gameErrMsg: ""
      })
  }

  open(){
      this.setState({show: true})
  }

  toggleActive(){
      let active = this.state.isActive
      let comfirmMsg = active ? "關閉遊戲" : "開啟遊戲"
      if(confirm(comfirmMsg)){
          this.setState({isActive: !active})
          let roomInfo = new FormData()
          roomInfo.append("label", this.props.roomInfo.label)
          roomInfo.append("isActive", !active)
          axios.post("http://localhost:8000/updateRoom/", roomInfo)
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

  handleSelect(eventKey){
      this.setState({
        gameErrMsg: "",
        game: eventKey
      })
  }

  handleCreate(event){
    // store room in database
    console.log(this)
    
    let teacher = this.props.teacher.name
    let game = this.state.game

    if(this.validate(game)){
        return
    }

    let roomInfo = new FormData()
    roomInfo.append("teacher", teacher)
    roomInfo.append("game", game)

    axios.post("http://localhost:8000/new/", roomInfo)
      .then((response) => {
        console.log(response)
        // if(response.data === 'label already exists.'){
        //     this.setState({
        //       labelVal: "error",
        //       labelErrMsg: response.data,
        //     })
        //     return
        // }
        roomInfo.append("label", response.data)
        roomInfo.append("isActive", true)
        this.props.handleUpdateRooms(roomInfo)
        this.close()
      })
      .catch((err) => {
          console.log(err)
      })
    
  }

  enter(){

      let label = this.props.roomInfo.label
      this.props.history.push({
        pathname: 'http://localhost:8000/'+label
      });
      // axios.get("http://localhost:8000/"+label+"/")
      //   .then((response) => {
      //       console.log(response)
      //   })
      //   .catch((err) =>{
      //       console.log(err)
      //   })
  }

  render(){

      console.log("render", "RoomCard")
      const room = (this.props.roomInfo) ? (
        <div className="room-card">
          <Card>
            <button type="button" className="btn btn-default btn-circle btn-room-remove">
              <span className="glyphicon glyphicon-remove"></span>
            </button>
            <CardImg top width="100%" src="https://placeholdit.imgix.net/~text?txtsize=33&txt=318%C3%97180&w=318&h=180" alt="Card image cap" />
            <CardBody>
              <CardTitle style={{'fontWeight':'bold'}}>遊戲: {this.props.roomInfo.game}</CardTitle>
              {/* <CardSubtitle>老師: {this.props.roomInfo.teacher}</CardSubtitle> */}
              <CardSubtitle>玩家: {this.props.roomInfo.teacher}</CardSubtitle>
              <CardText>標籤: {this.props.roomInfo.label}</CardText>
              <CardText>狀態: <Button className={this.state.isActive ? "btn-success" : "btn-default"} onClick={this.toggleActive}>{this.state.isActive ? "遊戲進行中" : "遊戲已結束"}</Button></CardText>
              <Button className="center-align btn-primary" onClick={this.enter}>進入遊戲</Button>
            </CardBody>
          </Card>
        </div>
      ) : (
        <div className="room-card">
        <Card>
          <CardBody>
            <div className="center">
              <button onClick={this.open} type="button" className="btn btn-default btn-circle btn-room-create"><i className="glyphicon glyphicon-plus"></i></button>
            </div>
          </CardBody>
        </Card>
        </div>
      )

      // const gameList = getGames()
      return(
        <div>
          {room}
          { <Modal show={this.state.show} onHide={this.close}>
            <Modal.Header closeButton>
              <Modal.Title>建立遊戲</Modal.Title>
            </Modal.Header>
            <Modal.Body>
                <FormGroup validationState={this.state.gameVal}>
                  <SplitButton componentClass={InputGroup.Button} id="split-button-basic" ref="gameBtn" title={this.state.game} onSelect={this.handleSelect} bsStyle="primary">
                    {/* {gameList} */}
                    <MenuItem ref="game1" eventKey="game1">game1</MenuItem>
                    <MenuItem ref="game2" eventKey="game2">game2</MenuItem>
                    <MenuItem ref="game3" eventKey="game3">game3</MenuItem>
                  </SplitButton>
                  {this.state.gameErrMsg !== "" && <HelpBlock><font size="14px" color="red">{this.state.gameErrMsg}</font></HelpBlock>}
                </FormGroup>
                {/* <FormGroup controlId="teacher" validationState={this.state.teacherVal}>
                  <ControlLabel>Teacher</ControlLabel>
                  <FormControl type="text" placeholder="Enter teacher" ref="teacher" onChange={()=>this.resetValidationState('teacher')}/>
                  <FormControl.Feedback />
                  {this.state.teacherErrMsg !== "" && <HelpBlock><font size="14px" color="red">{this.state.teacherErrMsg}</font></HelpBlock>}
                </FormGroup> */}
                {/* <FormGroup controlId="label" validationState={this.state.labelVal}>
                  <ControlLabel>Label</ControlLabel>
                  <FormControl type="text" placeholder="Enter label" ref="label" onChange={()=>this.resetValidationState('label')}/>
                  <FormControl.Feedback />
                  {this.state.labelErrMsg !== "" && <HelpBlock><font size="14px" color="red">{this.state.labelErrMsg}</font></HelpBlock>}
                </FormGroup> */}
            </Modal.Body>
            <Modal.Footer>
              <Button onClick={this.handleCreate}>建立</Button>
              <Button onClick={this.close}>取消</Button>
            </Modal.Footer>
          </Modal> }
        </div>
      )
  }
}

export default withRouter(RoomCard)