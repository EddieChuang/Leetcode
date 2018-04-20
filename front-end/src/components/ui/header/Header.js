import React from 'react'
import {Navbar, Nav, NavItem, Badge} from 'react-bootstrap'

class Header extends React.Component {

  constructor(props){
    super(props)
    this.state = {
      user: this.props.user,
      unread: this.props.unread
    }
    this.showChatroom = this.showChatroom.bind(this)
    this.logout = this.logout.bind(this)
  }

  componentWillReceiveProps(props){
    // console.log(props)
    this.setState({unread: props.unread})
  }

  showChatroom(){
    this.props.onSidebarDocked()
    this.setState({unread: 0})
  }

  logout(){
    if(confirm(this.state.user.type==='teacher' ? '確定登出嗎？' : '確定離開遊戲嗎？')){
        auth.logout()
        this.props.history.replace('/')
    }
  }

  render(){

    let user = this.state.user
    return (

      <Navbar>
        <Navbar.Header>
          <Navbar.Brand>
            <a>桌弄</a>
          </Navbar.Brand>
          <Navbar.Toggle />
        </Navbar.Header>
        <Navbar.Collapse>
          
          <Nav pullRight>
            <NavItem eventKey={2} onClick={this.showChatroom}>
              {this.state.unread > 0 ? (<Badge style={{color:'orange'}}>{this.state.unread}</Badge>) : ('')}聊天室
            </NavItem>
            <NavItem eventKey={1} onClick={this.logout}>
              {user.type==='teacher' ? '登出' : '離開遊戲'}
            </NavItem>
          </Nav>
        </Navbar.Collapse>
      </Navbar>
      // <div className="header">
      //   <div className="header-content">
      //     <h1 className="header-title">桌弄</h1>
      //     <button>聊天室</button>
      //     <button>登出</button>
      //   </div>
      // </div>
    )
  }

}

export default Header