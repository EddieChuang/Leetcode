import React from 'react'
import axios from 'axios'
import RoomListItem from './RoomListItem'
import RoomListHeader from './RoomListHeader'
import {withRouter} from 'react-router-dom'
import {URL_GETALLROOM} from '../../utils/url'
import {StickyContainer, Sticky} from 'react-sticky'
import FlipMove from 'react-flip-move'

class RoomList extends React.Component{
  constructor(props){
    super(props)
    this.state = {
      rooms: [],
      unread: this.props.unread
    }
    this.handleUpdateRooms = this.handleUpdateRooms.bind(this)
  }

  componentDidMount(){
    // get all rooms
    let username = localStorage.username
    let userInfo = new FormData()
    userInfo.append("username", username)
    this.setState({username: username})
    axios.post(URL_GETALLROOM, userInfo)
      .then((response) => {
          console.log(response)
          this.setState({rooms:response.data.rooms})
      })
      .catch((err) => {
          console.log(err)
      })
  }
  
  componentWillReceiveProps(props){
    console.log('roomList', props)
    this.setState({unread: props.unread})
  }

  handleUpdateRooms(newRoom){
    
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


  render(){
    
    const roomList = this.state.rooms.map((room) => (
      <RoomListItem 
        key={room.label} 
        room={room} 
        onEnter={this.props.onEnter} 
        onClick={this.enter}
        unread={this.state.unread}
      />
    ))

    return (
      <div>
        <RoomListHeader handleUpdateRooms={this.handleUpdateRooms}/>
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