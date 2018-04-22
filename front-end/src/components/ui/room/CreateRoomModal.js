"use strict"
import React from 'react'
import axios from 'axios'
import {MenuItem, Modal, InputGroup, Button,
  HelpBlock, FormGroup, SplitButton} from 'react-bootstrap'
import {URL_CREATEROOM} from '../../../constants/url'

class CreateRoomModal extends React.Component{

  constructor(props){
    super(props)
    this.state = {
      show: false,
      game: "選擇遊戲",
      gameErrMsg: "",
      nTeam: "選擇隊伍上限"
    }
    
    this.close = this.close.bind(this)
    this.onSelectGame = this.onSelectGame.bind(this)
    this.onSelectNTeam = this.onSelectNTeam.bind(this)
    this.onCreate = this.onCreate.bind(this)
  }

  componentWillReceiveProps(nextProps){
    this.setState(nextProps)
  }

  close(){
    
    this.setState({
      show: false,
      game: "選擇遊戲",
      gameErrMsg: "",
      nTeam: "選擇隊伍上限"
    })
    this.props.closeCreateRoom();
  }

  onSelectGame(eventKey){
    this.setState({
      gameErrMsg: "",
      game: eventKey
    })
  }

  onSelectNTeam(eventKey){
    this.setState({
      nTeam: eventKey
    })
  }

  validate(game){
    
    this.setState({
      gameErrMsg: game === "選擇遊戲" ? "請選擇遊戲" : ""
    })


    return game === "選擇遊戲"
  }

  onCreate(event){
    // store room in database
    
    let teacher = localStorage.username//this.props.teacher.name
    let game = this.state.game
    let nTeam = this.state.nTeam

    if(this.validate(game)){
        return
    }

    let roomInfo = new FormData()
    roomInfo.append("teacher", teacher)
    roomInfo.append("game", game)
    roomInfo.append("nTeam", nTeam)

    axios.post(URL_CREATEROOM, roomInfo)
      .then((response) => {
        let newRoom = {...response.data, 'isActive':true}
        this.props.onUpdateRooms(newRoom)
        this.close()
      })
      .catch((err) => {
          console.log(err)
      })
    
    }


  render(){
      // const gameList = getGames()
    return (
      <Modal show={this.state.show} onHide={this.close}>
        <Modal.Header closeButton>
          <Modal.Title>建立遊戲</Modal.Title>
        </Modal.Header>
        <Modal.Body>
          <FormGroup>
            <SplitButton componentClass={InputGroup.Button} id="split-button-basic" ref="gameBtn" title={this.state.game} onSelect={this.onSelectGame} bsStyle="primary">
              {/* {gameList} */}
              <MenuItem ref="game1" eventKey="game1">game1</MenuItem>
              <MenuItem ref="game2" eventKey="game2">game2</MenuItem>
              <MenuItem ref="game3" eventKey="game3">game3</MenuItem>
            </SplitButton>
            {this.state.gameErrMsg !== "" && <HelpBlock><font size="14px" color="red">{this.state.gameErrMsg}</font></HelpBlock>}
          </FormGroup>
          <FormGroup >
            <SplitButton componentClass={InputGroup.Button} id="split-button-num" ref="btnNTeam" title={this.state.nTeam} onSelect={this.onSelectNTeam} bsStyle="primary">
              <MenuItem ref="oneTeams" eventKey="1">1</MenuItem>
              <MenuItem ref="twoTeams" eventKey="2">2</MenuItem>
              <MenuItem ref="threeTeams" eventKey="3">3</MenuItem>
              <MenuItem ref="fourTeams" eventKey="4">4</MenuItem>
              <MenuItem ref="fiveTeams" eventKey="5">5</MenuItem>
            </SplitButton>
          </FormGroup>
        </Modal.Body>
        <Modal.Footer>
          <Button onClick={this.onCreate}>建立</Button>
          <Button onClick={this.close}>取消</Button>
        </Modal.Footer>
      </Modal>
    )
  }
}
export default CreateRoomModal