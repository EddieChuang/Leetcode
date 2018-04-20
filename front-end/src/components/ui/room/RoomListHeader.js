import React from 'react'
import {CreateRoomModal} from '.'

class RoomListHeader extends React.Component {

  constructor(props){
    super(props)
    this.state = {
      show: false
    }
    this.openCreateRoom = this.openCreateRoom.bind(this)
  }

  openCreateRoom(){
    this.setState({show: true})
  }



  render(){
    return (
      <div className="item-list-header">
        <input type="text" placeholder="搜尋遊戲" />
        <button className="btn btn-xs" onClick={this.openCreateRoom}>建立遊戲</button> {/*flipmove*/}
        <CreateRoomModal show={this.state.show} handleUpdateRooms={this.props.handleUpdateRooms} />
      </div>
      
    )
  }

}

export default RoomListHeader