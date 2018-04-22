"use strict"
import React from 'react'
import axios from 'axios'
import {withRouter} from 'react-router-dom'
import Sidebar from 'react-sidebar'

// ui
import {RoomList, CreateRoomModal} from '../ui/room'
import {Game} from '../ui/game'
import {Header} from '../ui/header'

// constants
import {URL_GETALLROOM} from '../../constants/url'


class Home extends React.Component {

  constructor(props){
      super(props)
      this.state = {
        activeLabel: '',
        show: false,
        rooms: [],
        user: JSON.parse(sessionStorage.user),
        unread:{},
        sidebarDocked: false
      }

      this.onEnter = this.onEnter.bind(this)
      this.onUnread = this.onUnread.bind(this)
      this.getAllRooms = this.getAllRooms.bind(this)
      this.openCreateRoom = this.openCreateRoom.bind(this)
      this.onUpdateRooms = this.onUpdateRooms.bind(this)
      this.onSidebarDocked = this.onSidebarDocked.bind(this)
  }

  componentDidMount(){
    this.getAllRooms()
  }

  openCreateRoom(){
    this.setState({show: true})
  }

  getAllRooms(){
    let userInfo = new FormData()
    userInfo.append("username", this.state.user.name)
    axios.post(URL_GETALLROOM, userInfo)
      .then((response) => {
          this.setState({rooms:response.data.rooms})
      })
      .catch((err) => {
          console.log(err)
      })
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
      if(this.state.activeLabel !== label){ 
        this.setState({unread: {label:label, n:n}})
      }
    }

    onSidebarDocked(){
      this.setState({sidebarDocked: !this.state.sidebarDocked})
    }
  
    render(){

      const gameList = this.state.rooms.map((room) => (
      <div 
        key={room.label} 
        id={room.label} 
        className={this.state.activeLabel==room.label?'active-game':'inactive-game'}
      >
        <Game 
          user={this.state.user} 
          label={room.label} 
          onUnread={this.onUnread} 
          sidebarDocked={this.state.sidebarDocked}/>
      </div>
      ))

    return(<div>

      <Header user={this.state.user} onSidebarDocked={this.onSidebarDocked}/>
      <div className="page-content">
        <div className="page-content-sidebar">
          <RoomList 
            onEnter={this.onEnter}
            user={this.state.user} 
            rooms={this.state.rooms}
            unread={this.state.unread}
            activeLabel={this.state.activeLabel}
            />
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