"use strict"
import React from 'react'
import axios from 'axios'
import ReactDOM from 'react-dom'
import {withRouter} from 'react-router-dom'
import {Well, Col, Row, Grid, Panel, Navbar, Button, Nav, NavItem} from 'react-bootstrap'
import {Card, CardImg, CardText, CardBody, CardTitle, CardSubtitle, CardImgOverlay} from 'reactstrap'

import RoomList from '../ui/RoomList'
import CreateRoomModal from '../ui/CreateRoomModal'
import auth from '../../utils/auth'
import {URL_GETALLROOM} from '../../utils/url'
import Sidebar from 'react-sidebar'
import Game from './Game'
import Header from '../ui/Header'

class Home extends React.Component {

  constructor(props){
      super(props)
      this.state = {
        activeLabel: '',
        show: false,
        rooms: [],
        username: '',
        unread:{},
        sidebarDocked: false
      }

      this.onEnter = this.onEnter.bind(this)
      this.onUnread = this.onUnread.bind(this)
      this.openCreateRoom = this.openCreateRoom.bind(this)
      this.onUpdateRooms = this.onUpdateRooms.bind(this)
      this.onSidebarDocked = this.onSidebarDocked.bind(this)
  }

  componentWillMount(){
      // get all rooms
      // console.log("componentWillMount", "Home")
      let username = localStorage.username
      let userInfo = new FormData()
      userInfo.append("username", username)
      this.setState({username: username})
      axios.post(URL_GETALLROOM, userInfo)
        .then((response) => {
            // console.log(response)
            this.setState({rooms:response.data.rooms})
        })
        .catch((err) => {
            console.log(err)
        })
  }

  

  openCreateRoom(){
    this.setState({show: true})
  }

  onUpdateRooms(newRoom){
    
    // let newRoom = {}
    // room.forEach(function(value, key){
    //     newRoom[key] = value
    // })
    let roomsToUpdate = this.state.rooms
    let indexToUpdate = roomsToUpdate.findIndex(function(room_){
        return newRoom.label === room_.label
    })
    // console.log('newRoom: ', newRoom)
    if(indexToUpdate === -1){
        this.setState({rooms: [newRoom, ...roomsToUpdate]})
    } else{
        this.setState({rooms: [...roomsToUpdate.slice(0, indexToUpdate), newRoom, ...roomsToUpdate.slice(indexToUpdate+1)]})
    }
  }

    onEnter(label){
    
      // this.props.history.replace({
      //   pathname:'/chat',
      //   state: {'label':label, 'user':user}
      // })

      this.setState({activeLabel: label, unread:{}})
    }

    onUnread(label, n){
      console.log('onUnread', label, n)
      if(this.state.activeLabel !== label){
        this.setState({unread: {label:label, n:n}})
      }
    }

    onSidebarDocked(){
      this.setState({sidebarDocked: !this.state.sidebarDocked})
    }
  
    render(){

      let user  = {'type':'teacher', 'key':'', 'name':this.state.username, 'note':''}
      const gameList = this.state.rooms.map((room) => (
      <div 
        key={room.label} 
        id={room.label} 
        className={this.state.activeLabel==room.label?'active-game':'inactive-game'}
      >
        <Game user={user} label={room.label} onUnread={this.onUnread} sidebarDocked={this.state.sidebarDocked}/>
      </div>
      ))

    return(<div>

      <Header user={user} onSidebarDocked={this.onSidebarDocked}/>
      <div className="page-content">
        <div className="page-content-sidebar">
          <RoomList onEnter={this.onEnter} unread={this.state.unread}/>
        </div>
        <div className="page-content-main">
          {gameList}
        </div>
        </div>
      </div>

    )
  }
}

export default withRouter(Home)