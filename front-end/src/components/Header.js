"use strict"
import React from 'react';
import ReactDOM from 'react-dom';
import {Link} from 'react-router-dom';
import axios from 'axios';
import {Nav, NavItem, Navbar, Modal, Button, Well, Col, Row, Panel, Form, FormControl, FormGroup, ControlLabel, HelpBlock} from 'react-bootstrap';



class Header extends React.Component {

    constructor(props){
        super(props);
        this.state = {
            show: false,
            usernameVal: null,
            emailVal: null,
            passwordVal: null,
            confirmPwdVal: null,
            usernameErrMsg: "",
            emailErrMsg: "",
            passwordErrMsg: "",
            confirmPwdErrMsg: ""
        }
        
    }

    open(){
        this.setState({show: true})
    }

    close(){
        this.setState({show: false})
    }

    resetValidationState(type){

      switch(type){
        case 'username':
          this.setState({usernameVal: null});
          this.setState({usernameErrMsg: ""});
          break;
        case 'email':
          this.setState({emailVal: null});
          this.setState({emailErrMsg: ""});
          
          break;
        case 'password':
          this.setState({passwordVal: null});
          this.setState({passwordErrMsg: ""});
          break;
        case 'confirmPwd':
          this.setState({confirmPwdVal: null});
          this.setState({confirmPwdErrMsg: ""});
          break;
        default:
          console.log("error type:", type);
          break;
      }

    }

    handleSignin(){
      console.log("handleSignin", this);
      
      let username = ReactDOM.findDOMNode(this.refs.usernameSignin).value;
      let password = ReactDOM.findDOMNode(this.refs.passwordSignin).value;
      let userInfo = new FormData();
      userInfo.append("username", username);
      userInfo.append("password", password);

      console.log(userInfo);
      const config = {headers: {'Content-Type': 'multipart/form-data'}}
      axios.post('http://localhost:8000/accounts/login/', userInfo, config)
        .then(function(response){
            console.log(response);
        })
        .catch(function(error){
            console.log(error);
        })

      
      

    }

    handleSignup(){
        console.log("handleSignup", this);
        let username = ReactDOM.findDOMNode(this.refs.username).value;
        let email = ReactDOM.findDOMNode(this.refs.email).value;
        let password = ReactDOM.findDOMNode(this.refs.password).value;
        let confirmPwd = ReactDOM.findDOMNode(this.refs.confirmPwd).value;
        
        console.log(username, email, password)
        
        // data validation
        let valid = true;
        if(username === '' || email === '' || password === '' || confirmPwd === ''){
            this.setState({usernameVal: (username==='') ? ('error') : (null)});
            this.setState({emailVal: (email==='') ? ('error') : (null)});
            this.setState({passwordVal: (password==='') ? ('error') : (null)});
            this.setState({confirmPwdVal: (confirmPwd==='') ? ('error') : (null)});
            return;
        }
        if(email.indexOf("@") === -1 && email.length < 3) {// a@b
            this.setState({emailErrMsg: "Invalid Email format."});
            this.setState({emailVal: 'error'});                    
            valid = false;
        }
        if(password.length < 8){
            this.setState({passwordErrMsg: "At least 8 characters."});
            this.setState({passwordVal: 'error'});                    
            valid = false;
        }
        else if(password !== confirmPwd){
            this.setState({confirmPwdErrMsg: "Does not match password."});          
            this.setState({confirmPwdVal: 'error'});
            valid = false;
        }
        if(!valid)
            return;
        // end data validation
        
        let userInfo = new FormData();        
        userInfo.append("username", username);
        userInfo.append("email", email);
        userInfo.append("password", password);
        
        // cannot use: localhost:8000/accounts/addUser
        const config = {headers: {'Content-Type': 'multipart/form-data'}}
        axios.post('http://localhost:8000/accounts/addUser/', userInfo, config)
          .then((response) => {
              console.log(response);            
              if(response.data.indexOf("帳號已存在") !== -1){
                  this.setState({usernameErrMsg: "User name is already existed."});          
                  this.setState({usernameVal: 'error'});
                  return;
              }
              
              close();
          })
          .catch((error) => {
              console.log(error);
          })

      }

    render(){
        return(
          <Navbar inverse collapseOnSelect>
            <Navbar.Header>
              <Navbar.Brand>
                <Link to='/'>Digiedu</Link>
              </Navbar.Brand>
              <Navbar.Toggle />
            </Navbar.Header>
            <Navbar.Collapse>
              <Nav>
                <NavItem eventKey={1} href="/">About</NavItem>
                {/* <NavItem eventKey={2} href="/">Contact Us</NavItem> */}
              </Nav>
              <Navbar.Form pullRight>
                <Button bsStyle="primary" onClick={this.open.bind(this)}>Sign up</Button>
                {/* <NavItem eventKey={2} onClick={this.open.bind(this)}>Sign up</NavItem> */}
              </Navbar.Form>
              <Navbar.Form pullRight>
                <FormGroup controlId="usernameSignin" validationState={this.state.usernameVal}>
                  <ControlLabel>Username</ControlLabel>
                  <FormControl 
                    type="text"
                    placeholder="Username"
                    ref="usernameSignin"/>
                  <FormControl.Feedback />
                  {/* {this.state.usernameErrMsg !== "" && <HelpBlock><font color="red">{this.state.usernameErrMsg}</font></HelpBlock>} */}
                </FormGroup>
                <FormGroup controlId="passwordSignin" validationState={this.state.emailVal}>
                  <ControlLabel>Password</ControlLabel>
                  <FormControl 
                    type="Password"
                    placeholder="Password"
                    ref="passwordSignin"/>
                  <FormControl.Feedback />
                  {/* {this.state.emailErrMsg !== "" && <HelpBlock><font color="red">{this.state.emailErrMsg}</font></HelpBlock>} */}
                </FormGroup>
                <Button bsStyle="success" onClick={this.handleSignin.bind(this)}>Sign in</Button>
                {/* <NavItem eventKey={1} onClick={this.handleSignin.bind(this)}>Sign in</NavItem> */}
              </Navbar.Form>
              
            </Navbar.Collapse>
            
            {/* pop up window */}
            <Modal show={this.state.show} onHide={this.close.bind(this)}>
              <Modal.Header closeButton>
                <Modal.Title>Sign up</Modal.Title>
              </Modal.Header>
              <Modal.Body>
                <Well>
                  <Row>
                    <Col xs={12} sm={6}>
                      <Panel>
                        <FormGroup controlId="username" validationState={this.state.usernameVal}>
                          <ControlLabel>User name</ControlLabel>
                          <FormControl 
                            type="text"
                            onChange={this.resetValidationState.bind(this, 'username')}
                            placeholder="Chiamin"
                            ref="username"/>
                          <FormControl.Feedback />
                          {this.state.usernameErrMsg !== "" && <HelpBlock><font color="red">{this.state.usernameErrMsg}</font></HelpBlock>}
                        </FormGroup>
                        <FormGroup controlId="email" validationState={this.state.emailVal}>
                          <ControlLabel>Email address</ControlLabel>
                          <FormControl 
                            type="email"
                            onChange={this.resetValidationState.bind(this, 'email')}
                            placeholder="chiamin@chiamin.com"
                            ref="email"/>
                          <FormControl.Feedback />
                          {this.state.emailErrMsg !== "" && <HelpBlock><font color="red">{this.state.emailErrMsg}</font></HelpBlock>}
                        </FormGroup>
                        <FormGroup controlId="password" validationState={this.state.passwordVal}>
                          <ControlLabel>Password</ControlLabel>
                          <FormControl 
                            type="password"
                            onChange={this.resetValidationState.bind(this, 'password')}
                            placeholder="Password"
                            ref="password"/>
                          <FormControl.Feedback />
                          {this.state.passwordErrMsg !== "" && <HelpBlock><font color="red">{this.state.passwordErrMsg}</font></HelpBlock>}
                        </FormGroup>
                        <FormGroup controlId="confirmPwd" validationState={this.state.confirmPwdVal}>
                          <ControlLabel>Confirm Password</ControlLabel>
                          <FormControl 
                            type="password"
                            onChange={this.resetValidationState.bind(this, 'confirmPwd')}
                            placeholder="Confirm Password"
                            ref="confirmPwd"/>
                          <FormControl.Feedback />
                          {this.state.confirmPwdErrMsg !== "" && <HelpBlock><font color="red">{this.state.confirmPwdErrMsg}</font></HelpBlock>}
                        </FormGroup>
                        <Button 
                          onClick={this.handleSignup.bind(this)} 
                          bsStyle="primary">
                          Sign up
                        </Button>
                      </Panel>
                    </Col>
                  </Row>
                </Well> 
              </Modal.Body>
              <Modal.Footer>
                <h6>Footer</h6>
                <Button onClick={this.close.bind(this)}>Close</Button>
              </Modal.Footer>
            </Modal>
            {/* end pop up window */}

          </Navbar>
          
        )
    }
}

// function mapStateToProps(state){
//   return {
//     validation: state
//   }
// }

export default Header;