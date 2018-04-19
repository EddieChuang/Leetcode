import React from 'react'
import Sidebar from 'react-sidebar'
import {Link, withRouter} from 'react-router-dom'
import Chatroom from './Chatroom'
import Header from '../ui/Header'
import {Navbar, Nav, NavItem, Badge} from 'react-bootstrap'
import styles from '../../style/share.scss'


class Game extends React.Component {

  constructor(props){
    super(props)

    this.state = {
      user: this.props.user ? this.props.user : this.props.location.state.user,
      label :this.props.label ? this.props.label : this.props.location.state.label,
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

    // console.log(this.state)
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
        sidebar={<Chatroom onUnread={this.props.onUnread} user={this.state.user} label={this.state.label}/>}
        open={this.state.sidebarOpen}
        docked={this.state.sidebarDocked}        
        onSetOpen={this.onSetSidebarOpen}
        pullRight={true}
        styles={sideBarStyles}>

        {/* <div>
        <Navbar>
          <Navbar.Header>
            <Navbar.Brand>
              <a>桌弄</a>
            </Navbar.Brand>
            <Navbar.Toggle />
          </Navbar.Header>
          <Navbar.Collapse>
            
            <Nav pullRight>
              <NavItem eventKey={2} onClick={this.onSidebarDocked}>
                <Badge>{this.state.unread!=0 ? this.state.unread : ''}</Badge>聊天室
              </NavItem>
              <NavItem eventKey={1} onClick={this.onLeave}>
                離開遊戲
              </NavItem>
              
            </Nav>
          </Navbar.Collapse>
        </Navbar>
        </div> */}
        
        <h1>hi, game startttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt</h1>
        {/* <Chatroom/> */}
        
          

      </Sidebar>
    )


  }

}

export default withRouter(Game)