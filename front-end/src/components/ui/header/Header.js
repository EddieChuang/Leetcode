import React from 'react'
import {withRouter} from 'react-router-dom'
import {Navbar, Nav, NavItem, Badge} from 'react-bootstrap'
import auth from '../../../utils/auth'


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
    this.setState({unread: props.unread})
  }

  showChatroom(){
    this.props.onSidebarDocked()
    this.setState({unread: 0})
  }

  logout(){
    let isTeacher = this.state.user.type==='teacher'
    let msg = isTeacher ? '確定登出嗎？' : '確定離開遊戲嗎？'
    if(confirm(msg)){
        if(isTeacher){
            auth.logout()
        } else{
            auth.leaveRoom()
        }
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

export default withRouter(Header)