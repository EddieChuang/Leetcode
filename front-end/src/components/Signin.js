"use strict"
import React from 'react';
import ReactDOM from 'react-dom';
import {Link} from 'react-router-dom';
import axios from 'axios';
import {Button, Well, Col, Row, Panel, Form, FormControl, FormGroup, ControlLabel, HelpBlock, Tab, Tabs, Nav, NavItem} from 'react-bootstrap';

import SigninForm from './SignForm';

class Signin extends React.Component {

    constructor(props){
        super(props);
        this.state = {
          key: 1
        }
    }


    handleSelect(key){
      this.setState({key})
    }

    render(){

        return(
          
          <div className="center">
          <Col xs={12} sm={6}>
            <Panel bsStyle="success">
              <Panel.Heading>進入桌弄</Panel.Heading>
              <Panel.Body>
              <Tabs id="tabs"  activeKey={this.state.key} onSelect={this.handleSelect.bind(this)} animation={true}>
                <Tab eventKey={1} title="Teacher">
                  <SigninForm userType='teacher'/>
                </Tab>
                <Tab eventKey={2} title="Player">
                  <SigninForm userType='player'/>
                </Tab>
              </Tabs>
            </Panel.Body>
            </Panel>
          </Col>
          </div>
          )
    }
}

export default Signin;