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
      user: this.props.user,
      unread: this.props.unread
    }
    this.onUpdateRooms = this.onUpdateRooms.bind(this)
    this.getAllRooms = this.getAllRooms.bind(this)
  }

  componentDidMount(){
    // get all rooms
    this.getAllRooms()
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
    this.setState({unread: props.unread})
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


  render(){
    
    const roomList = this.state.rooms.map((room) => (
      <RoomListItem 
        key={room.label} 
        room={room} 
        onEnter={this.props.onEnter} 
        onClick={this.enter}
        unread={this.state.unread}
        activeLabel={this.props.activeLabel}
      />
    ))

    return (
      <div>
        <RoomListHeader onUpdateRooms={this.onUpdateRooms}/>
        <div className="item-list">
          
          {/* <FlipMove duration={750} easing="ease-out">  */}
            {roomList}
           {/* </FlipMove>      */}
        </div>
      </div>
    )
  }
}
export default withRouter(RoomList)