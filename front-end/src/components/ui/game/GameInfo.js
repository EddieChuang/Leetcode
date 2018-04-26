import React from 'react'
import {withRouter} from 'react-router-dom'
import axios from 'axios'
import Sidebar from 'react-sidebar'
import Clipboard from 'react-clipboard.js';
import {Button} from 'react-bootstrap'

// ui
import {Game} from './'
import {Chatroom} from '../chatroom'
import {Header} from '../header'

// url
import {URL_CLOSEGAME, URL_CHATROOM} from '../../../constants/url'

// scss
import styles from '../../../style/share.scss'


class GameInfo extends React.Component {

  constructor(props){
    super(props)

    this.state = {
      user: this.props.user,
      room: this.props.room,
      sidebarOpen: false,
      sidebarDocked: false,
      unread: 0
    }

    this.enter = this.enter.bind(this)
    this.close = this.close.bind(this)
    this.onSetSidebarOpen = this.onSetSidebarOpen.bind(this)    
    this.onCopySuccess = this.onCopySuccess.bind(this)
  }

  componentWillReceiveProps(props){
    this.setState({sidebarDocked: props.sidebarDocked})
  }

  onSetSidebarOpen(open){
    this.setState({sidebarOpen: open})
  }

  onCopySuccess(){
    alert("複製到剪貼簿")
  }

  close(){
    let comfirmMsg = "遊戲關閉後將無法重啟，確定關閉遊戲？"
    if(confirm(comfirmMsg)){
        
        let room = new FormData()
        room.append("label", this.state.room.label)
        axios.post(URL_CLOSEGAME, room)
          .then((response) => {
              this.setState({room: {...this.state.room, isActive: false}})
              console.log(this)
              console.log(response)
          })
          .catch((response) => {
              console.log(response)
          })
    }
  }


  enter(){
    
    sessionStorage.label = this.state.room.label
    window.open(URL_CHATROOM)
    
  }


  render(){

    let sideBarStyles = {
      root: {
        position: 'relative',
        width: '100%',//styles.pageContentMainWidth,
        height: '100%'//styles.pageContentHeight,
      },
      sidebar: {overflowY: 'hidden'},
      content:{overflowY: 'hidden'}
    }

    let room = this.state.room
    let keys = room.keys.map((key, i)=>{
      // console.log(room)
      return (
        <li key={key}>
          <Clipboard data-clipboard-text={key} onSuccess={this.onCopySuccess}>
            <span className="glyphicon glyphicon-copy"/>
          </Clipboard>
          {key + ':' + room.keyToTeam[key].name}
        </li>
      )
    })

    
    return(
      
     
      <Sidebar 
        sidebar={
          <Chatroom 
            onUnread={this.props.onUnread} 
            onJoin={this.props.onJoin}
            user={this.state.user} 
            label={room.label}
          />
        }
        open={this.state.sidebarOpen}
        docked={this.state.sidebarDocked}        
        onSetOpen={this.onSetSidebarOpen}
        pullRight={true}
        styles={sideBarStyles}>
        
        <h1>hi, game start</h1>
        <h2>房間編號: {room.label}</h2>
        <h4>遊戲名稱: {room.game}</h4>
        <h4>建立老師: {room.teacher}</h4>
        {keys}
        <Button className="btn-primary" onClick={this.close} disabled={!room.isActive}>關閉遊戲</Button>
        <Button className="btn-primary" onClick={this.enter} disabled={!room.isActive}>進入遊戲</Button>
        {/* <Chatroom/> */}
        
          

      </Sidebar>
    )


  }

}

export default withRouter(GameInfo)