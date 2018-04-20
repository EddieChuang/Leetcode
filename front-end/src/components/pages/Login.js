"use strict"
import React from 'react';
import ReactDOM from 'react-dom';
import {Panel, Form, Tab, Tabs} from 'react-bootstrap';

// ui
import {LoginForm} from '../ui/login';

class Login extends React.Component {

    constructor(props){
        super(props);
        this.state = {
          key: 1
        }
        this.handleSelect = this.handleSelect.bind(this)
    }

    handleSelect(key){
      this.setState({key})
    }

    render(){
        return(
          
          <div className="boxed-view">
            <Panel className="boxed-view-loginForm" bsStyle="success">
              <Panel.Heading>進入桌弄</Panel.Heading>
              <Panel.Body>
              <Tabs id="tabs"  activeKey={this.state.key} onSelect={this.handleSelect} animation={true}>
                <Tab eventKey={1} title="老師">
                  <LoginForm userType='teacher'/>
                </Tab>
                <Tab eventKey={2} title="玩家">
                  <LoginForm userType='player'/>
                </Tab>
              </Tabs>
            </Panel.Body>
            </Panel>
          </div>
          )
    }
}

export default Login;