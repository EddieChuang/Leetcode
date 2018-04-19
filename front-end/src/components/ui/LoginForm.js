"use strict"
import React from 'react';
import ReactDOM from 'react-dom';
import {Link, withRouter} from 'react-router-dom';
import axios from 'axios';
import {Button, Well, Col, Row, Panel, Form, FormControl, FormGroup, ControlLabel, HelpBlock, Tab, Tabs, Nav, NavItem} from 'react-bootstrap';
import auth from '../../utils/auth'


class LoginForm extends React.Component {

    constructor(props){
        super(props);
        this.state = {
            usernameVal: null,
            passwordVal: null,
            usernameErrMsg: "",
            passwordErrMsg: ""
        }
        this.resetValidationState = this.resetValidationState.bind(this)
        this.onEnterRoom = this.onEnterRoom.bind(this)
        this.onLogin = this.onLogin.bind(this)
        // this.validate = this.validate.bind(this)
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

    onLogin(){
      
      let username = ReactDOM.findDOMNode(this.refs.input1).value;
      let password = ReactDOM.findDOMNode(this.refs.input2).value;

      if(this.validate(username, password)){
          return;
      }

      auth.login(username, password, (loggedIn, err)=>{
          if(loggedIn){
              this.props.history.push('/home')
          } else {
              this.setState({passwordErrMsg: err})
          }
      })
    }

    componentWillUnmount(){
    } 

    onEnterRoom(){
      
      let key  = ReactDOM.findDOMNode(this.refs.input1).value;
      let team = ReactDOM.findDOMNode(this.refs.input2).value;
      let note = ReactDOM.findDOMNode(this.refs.input3).value

      auth.authRoom(key, team, note, (valid, res)=>{
        console.log(res)
        if(valid){
            let user = {'type':'team', 'key':res.team.key, 'name':res.team.name, 'note':res.team.note}
            this.props.history.replace({
              pathname:'/chat',
              state: {'label':res.label, 'user':user}
            })
        } else {
            alert(res.data.res)
        }
      })
    }
    
    render(){

        let userType = this.props.userType
        return(
          <Well bsSize="large">
            <FormGroup controlId={(userType==='teacher')?('teacher'):('player')} validationState={this.state.usernameVal}>
              <ControlLabel>{(userType==='teacher')?('老師名稱'):('遊戲金鑰')}</ControlLabel>
              <FormControl 
                type="text"
                onChange={()=>this.resetValidationState('username')}
                // placeholder={(userType==='teacher')?('Chiamin'):('')}
                ref="input1"/>
                <FormControl.Feedback />
                {this.state.usernameErrMsg !== "" && <HelpBlock><font size="14px" color="red">{this.state.usernameErrMsg}</font></HelpBlock>}
            </FormGroup>

            <FormGroup controlId={(userType==='teacher')?('password'):('roomID')} validationState={this.state.passwordVal}>
              <ControlLabel>{(userType==='teacher')?('密碼'):('隊伍名稱')}</ControlLabel>
              <FormControl 
                type={(userType==='teacher')?('password'):('text')}
                onChange={()=>this.resetValidationState('password')}
                // placeholder={(userType==='teacher')?('Password'):('Chiamin')}
                ref="input2"/>
              <FormControl.Feedback />
              {this.state.passwordVal !== "" && <HelpBlock><font size="14px" color="red">{this.state.passwordErrMsg}</font></HelpBlock>}
            </FormGroup>
            {userType==='player' ? (
              <FormGroup controlId="formControlsTextarea">
                <ControlLabel>備註</ControlLabel>
                <FormControl ref="input3" componentClass="textarea" placeholder="組員名稱 …" />
              </FormGroup>) : ("")
            }
            <Button style={{}} onClick={(userType==='teacher') ? 
              (this.onLogin) : (this.onEnterRoom)} bsStyle="primary">
              {(userType==='teacher') ? ('登入') : ('進入遊戲')}
            </Button>
          </Well>
          )
    }
}

export default withRouter(LoginForm);