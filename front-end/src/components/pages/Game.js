import React from 'react'
import Sidebar from 'react-sidebar'
import Chatroom from './Chatroom'
import {Navbar, Nav, NavItem, Badge} from 'react-bootstrap'



class Game extends React.Component {

  constructor(props){
    super(props)

    this.state = {
      sidebarOpen: false,
      sidebarDocked: false,
      unread: 0
    }

    this.onSetSidebarOpen = this.onSetSidebarOpen.bind(this)
    this.onSidebarDocked = this.onSidebarDocked.bind(this)
    this.onLeave = this.onLeave.bind(this)
    this.onUnread = this.onUnread.bind(this)
    


  }

  onSetSidebarOpen(open){
    this.setState({sidebarOpen: open})
  }

  onSidebarDocked(){
    this.setState({sidebarDocked: !this.state.sidebarDocked})
    this.setState({unread: 0})
  }

  onLeave(){
  }

  onUnread(n){
    console.log('onUnread', n)
    if(this.state.sidebarDocked === false)
        this.setState({unread: n==0 ? 0 : this.state.unread+n})
  }

  render(){
    let styles = {
      content:{overflowY: 'hidden'}
    }
    return(
      <div>
      
      <Sidebar sidebar={<Chatroom onUnread={this.onUnread}/>}
        open={this.state.sidebarOpen}
        docked={this.state.sidebarDocked}        
        onSetOpen={this.onSetSidebarOpen}
        pullRight={true}
        styles={styles}>

        <div>
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
        </div>
        <h1>hi, game start</h1>
        {/* <Chatroom/> */}
        
          

      </Sidebar>
      </div>
    )


  }

}

export default Game