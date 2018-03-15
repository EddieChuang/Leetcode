"use strict"
import React from 'react';
import axios from 'axios';
import ReactDOM from 'react-dom';
import {Well, Col, Row, Grid, Panel} from 'react-bootstrap';
import {Card, CardImg, CardText, CardBody, CardTitle, CardSubtitle, CardImgOverlay, Button} from 'reactstrap';

import RoomCard from './RoomCard';

class Home extends React.Component {

  constructor(props){
      super(props);
      this.state = {
         rooms: []
      }
  }

  componentWillMount(){
    // get all rooms

    
    let self = this;
    axios.get('http://localhost:8000/getAllRooms/')
      .then(function(response){
          console.log(response);
          self.setState({rooms:response.data.rooms});
          
      })
      .catch(function(err){
          console.log(err);
      })

    // this.setState({
    //   rooms: [
    //     {
    //       roomId: 1,
    //       game: 'operating system',
    //       teacher: 'chiamin',
    //       player: 'chiamin'
    //     },
    //     {
    //       roomId: 2,
    //       game: 'algorithm',
    //       teacher: 'chiamin',
    //       player: 'chiamin'
    //     },
    //     {
    //       roomId: 3,
    //       game: 'react.js',
    //       teacher: 'chiamin',
    //       player: 'chiamin'
    //     }
    //   ]
    // });
  }

  componentDidMount(){
    console.log(ReactDOM.findDOMNode(this.refs.xxx));
  }

  render(){

    const roomList = this.state.rooms.map(function(room){
        return (
          <Col xs={4} md={3} md={2}  key={room.label}>
            <RoomCard roomInfo={room}/>
          </Col>
        )
    });

    return(
      <Panel bsStyle="success">
        <Panel.Heading>桌弄</Panel.Heading>
        <Panel.Body>
          <Grid>
            <Row>
              {roomList}
              <Col xs={4} md={3} md={2} >
                <RoomCard ref="xxx" roomInfo={null}/>
              </Col>
            </Row>
          </Grid>
        </Panel.Body>
      </Panel>
      
    )
  }
}

export default Home;