import React from 'react'
import {withRouter} from 'react-router-dom'
import Sidebar from 'react-sidebar'

// ui
import {Chatroom} from '../chatroom'
import {Header} from '../header'

// scss
import styles from '../../../style/share.scss'


class Game extends React.Component {

  constructor(props){
    super(props)

    this.state = {
      user: this.props.user,
      label: this.props.label,
      sidebarOpen: false,
      sidebarDocked: false,
      unread: 0
    }

    this.onSetSidebarOpen = this.onSetSidebarOpen.bind(this)    
  }

  componentWillReceiveProps(props){
    this.setState({sidebarDocked: props.sidebarDocked})
  }

  onSetSidebarOpen(open){
    this.setState({sidebarOpen: open})
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

    return(
      
      
      <Sidebar 
        sidebar={
          <Chatroom 
            onUnread={this.props.onUnread} 
            onJoin={this.props.onJoin}
            user={this.state.user}
            label={this.state.label}/>
        }
        open={this.state.sidebarOpen}
        docked={this.state.sidebarDocked}        
        onSetOpen={this.onSetSidebarOpen}
        pullRight={true}
        styles={sideBarStyles}>
        
        <h1>hi, game start</h1>
        <h2>{this.state.label}</h2>
        {/* <Chatroom/> */}
        
          

      </Sidebar>
    )


  }

}

export default withRouter(Game)