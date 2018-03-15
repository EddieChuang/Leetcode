"use strict"
import React from 'react';
import ReactDOM from 'react-dom';
import axios from 'axios';
import {withRouter} from 'react-router-dom';

import {MenuItem, Form, Well, Col, Row, Grid, Panel, Modal, InputGroup, FormControl, FormGroup, DropdownButton, Image, ControlLabel, SplitButton} from 'react-bootstrap';
import {Card, CardImg, CardText, CardBody, CardTitle, CardSubtitle, CardImgOverlay, CardDeck, Button} from 'reactstrap';
class RoomCard extends React.Component {

  constructor(props){
      super(props);
      this.state = {
         rooms: null,
         game: '選擇遊戲',
         show: false
      }
  }

  componentDidMount(){
    // console.log(ReactDOM.findDOMNode(this.refs.teacher));
  }

  close(){
      this.setState({show: false});
  }

  open(){
      this.setState({show: true});
  }

  handleSelect(eventKey){
      this.setState({game: eventKey});
  }

  handleCreate(event){
    // store room in database
    console.log(this);
    
    let teacher = ReactDOM.findDOMNode(this.refs.teacher).value;
    let label  = ReactDOM.findDOMNode(this.refs.label).value;
    let game = this.state.game;
    let roomInfo = new FormData();
    roomInfo.append("teacher", teacher);
    roomInfo.append("label", label);
    roomInfo.append("game", game);

    // let self = this;
    axios.post("http://localhost:8000/new/", roomInfo)
      .then(function(response){
          console.log(response);
          // self.props.history.push("/home");
      })
      .catch(function(err){
          console.log(err);
      })
    
  }

  enter(){

  }

  render(){

      const room = (this.props.roomInfo) ? (
        <Card>
          <CardImg top width="100%" src="https://placeholdit.imgix.net/~text?txtsize=33&txt=318%C3%97180&w=318&h=180" alt="Card image cap" />
          <CardBody>
            <CardTitle>{this.props.roomInfo.game}</CardTitle>
            <CardText>{this.props.roomInfo.teacher}</CardText>
            <Button onClick={this.enter.bind(this)}>進入聊天室</Button>
          </CardBody>
        </Card>
      ) : (
        <Card>
          <CardBody>
            <div className="center">
              <button onClick={this.open.bind(this)} type="button" className="btn btn-default btn-circle"><i className="glyphicon glyphicon-plus"></i></button>
            </div>
          </CardBody>
        </Card>
      );

      // const gameList = getGames();
      return(
        <div>
          {room}
          <Modal show={this.state.show} onHide={this.close.bind(this)}>
            <Modal.Header closeButton>
              <Modal.Title>建立聊天室</Modal.Title>
            </Modal.Header>
            <Modal.Body>
              {/* <Form onSubmit={this.handleCreate.bind(this)}> */}
                <FormGroup>
                  <SplitButton componentClass={InputGroup.Button} id="split-button-basic" title={this.state.game} onSelect={this.handleSelect.bind(this)} bsStyle="primary">
                    {/* {gameList} */}
                    <MenuItem ref="game1" eventKey="game1">game1</MenuItem>
                    <MenuItem ref="game2" eventKey="game2">game2</MenuItem>
                    <MenuItem ref="game3" eventKey="game3">game3</MenuItem>
                  </SplitButton>
                </FormGroup>
                <FormGroup controlId="teacher">
                  <ControlLabel>Teacher</ControlLabel>
                  <FormControl type="text" placeholder="Enter teacher" ref="teacher"/>
                  <FormControl.Feedback />
                </FormGroup>
                <FormGroup controlId="label">
                  <ControlLabel>Label</ControlLabel>
                  <FormControl type="text" placeholder="Enter label" ref="label"/>
                  <FormControl.Feedback />
                </FormGroup>
                {/* <FormGroup controlId="price" >
                  <ControlLabel>price</ControlLabel>
                  <FormControl 
                    type="text"
                    placeholder="Enter price"
                    ref="price"/>
                  <FormControl.Feedback />
                </FormGroup> */}
                {/* <Button type="submit">建立</Button> */}
                
              {/* </Form > */}
            </Modal.Body>
            <Modal.Footer>
              <Button onClick={this.handleCreate.bind(this)}>建立</Button>
              <Button onClick={this.close.bind(this)}>取消</Button>
            </Modal.Footer>
          </Modal>
        </div>
      )
  }
}

export default RoomCard;