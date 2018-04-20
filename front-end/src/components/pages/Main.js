"use strict"
import React from 'react'
import {withRouter} from 'react-router-dom'

// ui
import {Game} from '../ui/game'
import {Header} from '../ui/header'

class Main extends React.Component {

  constructor(props){
      super(props)
      this.state = {
        user: this.props.location.state.user,
        label: this.props.location.state.label,
        sidebarDocked: false,
        unread: 0
      }

      this.onUnread = this.onUnread.bind(this)
      this.onSidebarDocked = this.onSidebarDocked.bind(this)
  }

  onUnread(label, n){
    console.log('onUnread', label, n)
    if(!this.state.sidebarDocked)
        this.setState({unread: this.state.unread + n})
  }

  onSidebarDocked(){
    this.setState({sidebarDocked: !this.state.sidebarDocked})
    this.setState({unread: 0})
  }


  
  render(){

    return(
      <div>
        <Header user={this.state.user} onSidebarDocked={this.onSidebarDocked} unread={this.state.unread}/>
        <div className="page-content">
          <div className="page-content-main">
            <Game 
              user={this.state.user} 
              label={this.state.label} 
              sidebarDocked={this.state.sidebarDocked}
              onUnread={this.onUnread}
              />
          </div>
        </div>
      </div>

    )
  }
}

export default withRouter(Main)