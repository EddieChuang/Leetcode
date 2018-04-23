import React from 'react'
import axios from 'axios'
import {withRouter} from 'react-router-dom'
import {RoomListItem, RoomListHeader} from '.'
import {URL_GETALLROOM} from '../../../constants/url'
import FlipMove from 'react-flip-move'

class RoomList extends React.Component{
  constructor(props){
    super(props)
    this.state = {
      rooms: this.props.rooms,
      matchedRooms: this.props.rooms,
      user: this.props.user,
      unread: this.props.unread
    }

    this.onUpdateRooms = this.onUpdateRooms.bind(this)
    this.getAllRooms = this.getAllRooms.bind(this)
    this.renderRoomItem = this.renderRoomItem.bind(this)
    this.onSearch = this.onSearch.bind(this)
  }

  componentDidMount(){
    // get all rooms
    // this.getAllRooms()
    
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
  
  componentWillReceiveProps(props){    
    this.setState({
      unread: props.unread,
      rooms: props.rooms,
      matchedRooms: props.rooms
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

    if(indexToUpdate === -1){
        this.setState({rooms: [newRoom, ...roomsToUpdate], unread: {}})
    } else{
        this.setState({rooms: [...roomsToUpdate.slice(0, indexToUpdate), newRoom, ...roomsToUpdate.slice(indexToUpdate+1)], unread: {}})
    }
  }

  onSearch(matchedRooms){
    this.setState({matchedRooms: matchedRooms})
  }

  renderRoomItem(){
    return this.state.matchedRooms.map((room) => (
      // <h3 key={room.label}>{room.label}</h3>
      <RoomListItem 
        key={room.label} 
        room={room} 
        onEnter={this.props.onEnter} 
        unread={this.state.unread}
        activeLabel={this.props.activeLabel}
      />
    ))
  }


  render(){
    console.log('render')
    
    // const roomList = this.state.rooms.map((room) => (
    //   <RoomListItem 
    //     key={room.label} 
    //     room={room} 
    //     onEnter={this.props.onEnter} 
    //     onClick={this.enter}
    //     unread={this.state.unread}
    //     activeLabel={this.props.activeLabel}
    //   />
    // ))
    // console.log(this.state)
    return (
      <div>
        <RoomListHeader 
          onUpdateRooms={this.onUpdateRooms} 
          onSearch={this.onSearch} 
          rooms={this.state.rooms}
        />
        <div className="item-list">
          
          <FlipMove> 
            {this.renderRoomItem()}
           </FlipMove>     
        </div>
      </div>
    )
  }
}
export default withRouter(RoomList)