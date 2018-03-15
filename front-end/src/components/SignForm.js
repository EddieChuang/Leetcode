"use strict"
import React from 'react';
import ReactDOM from 'react-dom';
import {Link, withRouter} from 'react-router-dom';
import axios from 'axios';
import {Button, Well, Col, Row, Panel, Form, FormControl, FormGroup, ControlLabel, HelpBlock, Tab, Tabs, Nav, NavItem} from 'react-bootstrap';

class SigninForm extends React.Component {

    constructor(props){
        super(props);
        this.state = {
            usernameVal: null,
            passwordVal: null,
            usernameErrMsg: "",
            passwordErrMsg: ""

        }
    }

  resetValidationState(type){

    switch(type){
      case 'username':
        this.setState({
          usernameVal: null,
          usernameErrMsg: ""
        });
        break;
      case 'password':
        this.setState({
          passwordVal: null,
          passwordErrMsg: ""
        });
        break;
      default:
        console.log("error type:", type);
        break;
    }
  }

  validate(username, password){
      this.setState({
        usernameVal: username === "" ? 'error' : null,
        passwordVal: password === "" ? 'error' : null,
        usernameErrMsg: username === "" ? '請輸入名稱' : "",
        passwordErrMsg: password === "" ? '請輸入密碼' : ""
      });
      return username === "" || password === "";
  }

  handleSignin(){
    console.log("handleSignin", this);
    
    let username = ReactDOM.findDOMNode(this.refs.username).value;
    let password = ReactDOM.findDOMNode(this.refs.password).value;

    if(this.validate(username, password)){
        return;
    }

    let userInfo = new FormData();
    userInfo.append("username", username);
    userInfo.append("password", password);

    const self = this;
    const config = {headers: {'Content-Type': 'multipart/form-data'}};
    axios.post('http://localhost:8000/accounts/login/', userInfo, config)
      .then(function(response){
          console.log(response);
          if(response.data === '登入成功'){
              console.log('登入成功');            
              self.props.history.push("/home");
          } else if(response.data === '登入失敗'){
              // self.setState({usernameVal: 'error'});
              // self.setState({passwordVal: 'error'});
              self.setState({passwordErrMsg: '登入失敗'});
          }
      })
      .catch(function(error){
          console.log(error);
      })
  }

  handleEnterRoom(){
    console.log("handleEnterRoom", this);
    
    let username = ReactDOM.findDOMNode(this.refs.username).value;
    let password = ReactDOM.findDOMNode(this.refs.password).value;
    let userInfo = new FormData();
    userInfo.append("username", username);
    userInfo.append("password", password);

    console.log(userInfo);
    const config = {headers: {'Content-Type': 'multipart/form-data'}}
    axios.post('http://localhost:8000/accounts/login/', userInfo, config)
      .then(function(response){
          // this.props.history.push()
          console.log(response);
      })
      .catch(function(err){
          console.log(err);
      })
  }

  /* handleSignup(){
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

     }*/

    render(){

        return(
          <Well bsSize="large">
            <FormGroup controlId={(this.props.userType==='teacher')?('teacher'):('player')} validationState={this.state.usernameVal}>
              <ControlLabel>{(this.props.userType==='teacher')?('Teacher'):('Player')} name</ControlLabel>
              <FormControl 
                type="text"
                onChange={this.resetValidationState.bind(this, 'username')}
                placeholder="Chiamin"
                ref="username"/>
                <FormControl.Feedback />
                {this.state.usernameErrMsg !== "" && <HelpBlock><font size="14px" color="red">{this.state.usernameErrMsg}</font></HelpBlock>}
            </FormGroup>

            <FormGroup controlId={(this.props.userType==='teacher')?('password'):('roomID')} validationState={this.state.passwordVal}>
              <ControlLabel>{(this.props.userType==='teacher')?('Password'):('Room ID')}</ControlLabel>
              <FormControl 
                type={(this.props.userType==='teacher')?('password'):('text')}
                onChange={this.resetValidationState.bind(this, 'password')}
                placeholder={(this.props.userType==='teacher')?('Password'):('game-123')}
                ref="password"/>
              <FormControl.Feedback />
              {this.state.passwordVal !== "" && <HelpBlock><font size="14px" color="red">{this.state.passwordErrMsg}</font></HelpBlock>}
            </FormGroup>
            <Button onClick={(this.props.userType==='teacher') ? 
              (this.handleSignin.bind(this)) : (this.handleEnterRoom.bind(this))} bsStyle="primary">
              {(this.props.userType==='teacher') ? ('登入') : ('進入聊天室')}
            </Button>
          </Well>
          )
    }
}

export default withRouter(SigninForm);