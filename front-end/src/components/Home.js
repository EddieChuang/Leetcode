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
      this.handleUpdateRooms = this.handleUpdateRooms.bind(this);
  }

  componentWillMount(){
    // get all rooms
    console.log("componentWillMount", "Home");
    let location = this.props.location;
    if(location.state === undefined || !location.state.logined){
        this.props.history.push('/');
    } else{

        let username = location.state.username;
        let userInfo = new FormData();
        userInfo.append("username", username);
        this.setState({username: username})
        axios.post('http://localhost:8000/getAllRooms/', userInfo)
          .then((response) => {
              console.log(response);
              this.setState({rooms:response.data.rooms});
          })
          .catch((err) => {
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
    if (!confirm('登出')) 
        return;
    axios.get('http://localhost:8000/accounts/logout/')
      .then((response) => {
          console.log(response);
          this.setState({username:''});
          this.props.history.push('/');
      })
      .catch((err) => {
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
          this.setState({rooms: [newRoom, ...roomsToUpdate]});
      } else{
          this.setState({rooms: [...roomsToUpdate.slice(0, indexToUpdate), newRoom, ...roomsToUpdate.slice(indexToUpdate+1)]})
      }
  }

  render(){

    let teacher = {name: this.state.username};
    const roomList = this.state.rooms.map((room) => (
        
        <Col xs={4} md={3} md={2} key={room.label}>
          <RoomCard teacher={teacher} roomInfo={room} handleUpdateRooms={this.handleUpdateRooms}/>
        </Col>
      ));

    return(
      <Panel bsStyle="success">
        <Panel.Heading>桌弄    Hi, {this.state.username}  
          <Button style={{"float":"right", "width":"50px", "height":"25px", "padding":"0px", "backgroundColor":"#ffcccc"}} onClick={this.logout}>登出</Button>
        </Panel.Heading>
        <Panel.Body>
          <Grid>
            <Row>
              {roomList}
              <Col xs={4} md={3} md={2} >
                <RoomCard teacher={teacher} roomInfo={null} handleUpdateRooms={this.handleUpdateRooms}/>
              </Col>
            </Row>
          </Grid>
        </Panel.Body>
      </Panel>
      
    )
  }
}

export default withRouter(Home);