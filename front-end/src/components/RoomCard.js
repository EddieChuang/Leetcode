"use strict"
import React from 'react';
import ReactDOM from 'react-dom';
import axios from 'axios';
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

  close(){
      this.setState({show: false});
  }

  open(){
      this.setState({show: true});
  }

  handleSelect(eventKey){
      this.setState({game: eventKey});
  }

  create(){
    // store room in database
  }

  getGames(){
    // get games from database
  }

  render(){

      const room = (this.props.roomInfo) ? (
        <Card>
          <CardImg top width="100%" src="https://placeholdit.imgix.net/~text?txtsize=33&txt=318%C3%97180&w=318&h=180" alt="Card image cap" />
          <CardBody>
            <CardTitle>{this.props.roomInfo.game}</CardTitle>
            <CardText>{this.props.roomInfo.teacher}</CardText>
            <Button>進入聊天室</Button>
          </CardBody>
        </Card>
      ) : (
        <Card>
          <CardBody>
            <div className="center">
            <button onClick={this.open.bind(this)}type="button" className="btn btn-default btn-circle"><i className="glyphicon glyphicon-plus"></i></button>
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
              <Form >
                  <FormGroup>
                    <SplitButton componentClass={InputGroup.Button} id="split-button-basic" title={this.state.game} onSelect={this.handleSelect.bind(this)} bsStyle="primary">
                      {/* {gameList} */}
                      <MenuItem ref="game1" eventKey="game1">game1</MenuItem>
                      <MenuItem ref="game2" eventKey="game2">game2</MenuItem>
                      <MenuItem ref="game3" eventKey="game3">game3</MenuItem>
                    </SplitButton>
                  </FormGroup>
                        <FormGroup controlId="owner">
                            <ControlLabel>Owner</ControlLabel>
                            <FormControl 
                                type="text"
                                placeholder="Enter name"
                                ref="owner"/>
                            <FormControl.Feedback />
                        </FormGroup>
                        <FormGroup controlId="description">
                            <ControlLabel>description</ControlLabel>
                            <FormControl 
                                type="text"
                                placeholder="Enter description"
                                ref="description"/>
                            <FormControl.Feedback />
                        </FormGroup>
                        <FormGroup controlId="price" >
                            <ControlLabel>price</ControlLabel>
                            <FormControl 
                                type="text"
                                placeholder="Enter price"
                                ref="price"/>
                            <FormControl.Feedback />
                        </FormGroup>
              </Form >
            </Modal.Body>
            <Modal.Footer>
              <Button onClick={this.create.bind(this)}>建立</Button>
              <Button onClick={this.close.bind(this)}>取消</Button>
            </Modal.Footer>
          </Modal>
        </div>
      )
  }
}

export default RoomCard;