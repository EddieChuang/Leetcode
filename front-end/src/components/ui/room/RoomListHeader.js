import React from 'react'
import {CreateRoomModal} from '.'

class RoomListHeader extends React.Component {

  constructor(props){
    super(props)
    this.state = {
      show: false
    }
    this.openCreateRoom = this.openCreateRoom.bind(this)
    this.closeCreateRoom = this.closeCreateRoom.bind(this)
  }

  openCreateRoom(){
    this.setState({show: true})
  }

  closeCreateRoom(){
    this.setState({show: false})
  }



  render(){
    return (

      <div className="item-list-header">
        <input type="text" placeholder="搜尋遊戲" />
        <button className="btn btn-xs" onClick={this.openCreateRoom}>建立遊戲</button> {/*flipmove*/}
        <CreateRoomModal 
          show={this.state.show} 
          closeCreateRoom={this.closeCreateRoom}
          onUpdateRooms={this.props.onUpdateRooms} />
      </div>
      
    )
  }

}

export default RoomListHeader