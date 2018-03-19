"use strict"
import React from 'react';
import axios from 'axios';
import ReactDOM from 'react-dom';
import {withRouter} from 'react-router-dom';
import {Well, Col, Row, Grid, Panel} from 'react-bootstrap';
import {Card, CardImg, CardText, CardBody, CardTitle, CardSubtitle, CardImgOverlay, Button} from 'reactstrap';

import RoomCard from './RoomCard';

class Home extends React.Component {

  constructor(props){
      super(props);
      this.state = {
         rooms: [],
         username: '',
      }
      this.logout = this.logout.bind(this);
  }

  componentWillMount(){
    // get all rooms
    console.log("componentWillMount", "Home");

    let location = this.props.location;
    if(location.state === undefined || !location.state.logined){
        this.props.history.push('/');
    } else{

        this.setState({username: location.state.username})
        let self = this;
        axios.get('http://localhost:8000/getAllRooms/')
          .then(function(response){
              console.log(response);
              self.setState({rooms:response.data.rooms});
          })
          .catch(function(err){
              console.log(err);
          })
    }
  }
  componentDidMount(){
    console.log("componentDidMount", "Home");
  }

  componentWillUnmount(){
    console.log("componentWillUnmount", "Home");
  }

  logout(){

    let self = this;
    axios.get('http://localhost:8000/accounts/logout/')
      .then(function(response){
          self.setState({username:''});
          self.props.history.push('/');
      })
      .catch(function(err){
          console.log(err);
      })

  }

  handleUpdateRooms(room){

      let newRoom = {};
      room.forEach(function(value, key){
          newRoom[key] = value;
      })
      let roomsToUpdate = this.state.rooms;
      let indexToUpdate = roomsToUpdate.findIndex(function(room_){
          return newRoom.label === room_.label;
      });
      if(indexToUpdate === -1){
          this.setState({rooms: [...roomsToUpdate, newRoom]});
      } else{
          this.setState({rooms: [...roomsToUpdate.slice(0, indexToUpdate), newRoom, ...roomsToUpdate.slice(indexToUpdate+1)]})
      }
  }

  render(){

    const self = this;
    const roomList = this.state.rooms.map(function(room){
        return (
          <Col xs={4} md={3} md={2} key={room.label}>
            <RoomCard roomInfo={room} handleUpdateRooms={self.handleUpdateRooms.bind(self)}/>
          </Col>
        )
    });

    return(
      <Panel bsStyle="success">
        <Panel.Heading>桌弄    Hi, {this.state.username}  
          <Button onClick={this.logout}>登出</Button>
        </Panel.Heading>
        <Panel.Body>
          <Grid>
            <Row>
              {roomList}
              <Col xs={4} md={3} md={2} >
                <RoomCard ref="xxx" roomInfo={null} handleUpdateRooms={this.handleUpdateRooms.bind(this)}/>
              </Col>
            </Row>
          </Grid>
        </Panel.Body>
      </Panel>
      
    )
  }
}

export default withRouter(Home);