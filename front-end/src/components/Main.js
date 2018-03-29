import React from 'react'
// import { Redirect } from 'react-router'
import {Switch, Route, Redirect} from 'react-router-dom'
import Home from './Home'
import Login from './Login'
import { withRouter } from "react-router-dom"
import auth from "../javascript/auth"


class Main extends React.Component {
  
  render(){
    return(
      <Switch>
        <Route exact path="/" render={() => (
            auth.loggined() ? <Redirect to="/home"/> : <Login/> 
        )}/>
        <Route exact path="/home" render={() => (
            !auth.loggined() ? <Redirect to="/"/> : <Home/> 
        )}/>
      </Switch>
    )
  }
}

export default withRouter(Main)