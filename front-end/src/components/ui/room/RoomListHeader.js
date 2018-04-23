import React from 'react'
import {CreateRoomModal} from '.'

class RoomListHeader extends React.Component {

  constructor(props){
    super(props)
    this.state = {
      show: false,
    }

    this.search = this.search.bind(this)
    this.openCreateRoom = this.openCreateRoom.bind(this)
    this.closeCreateRoom = this.closeCreateRoom.bind(this)
  }

  openCreateRoom(){
    this.setState({show: true})
  }

  closeCreateRoom(){
    this.setState({show: false})
  }

  search(e){

    let keyword = e.target.value.trim()
    if(keyword === ""){
      this.props.onSearch(this.props.rooms)
      return;
    }
        
    let matchedRooms = this.props.rooms.filter((room, i, arr) => {
      console.log(room, i, arr)
      if(room.game.indexOf(keyword) !== -1){ // match room's game
        return true
      } else if(room.teacher.indexOf(keyword) !== -1){ // match room's teacher
        return true
      } else if(room.teams.indexOf(keyword) !== -1){ // match room's teams
        return true
      }
      return false
    })
    this.props.onSearch(matchedRooms)
  }



  render(){
    return (

      <div className="item-list-header">
        <input type="text" placeholder="搜尋遊戲" onKeyUp={this.search}/>
        <button className="btn btn-xs" onClick={this.openCreateRoom}>建立遊戲</button> 
        <CreateRoomModal 
          show={this.state.show} 
          closeCreateRoom={this.closeCreateRoom}
          onUpdateRooms={this.props.onUpdateRooms} />
      </div>
      
    )
  }

}

export default RoomListHeader