"use strict"
import React from 'react'
import {Switch, Route, Redirect, withRouter} from 'react-router-dom'

import Home from './pages/Home'
import Login from './pages/Login'
import Chatroom from './pages/Chatroom'
import Game from './pages/Game'
import auth from "../utils/auth"

class App extends React.Component {
    
    render(){
        return (
          <Switch>
            <Route exact path="/" render={() => (
                auth.loggined() ? <Redirect to="/home"/> : 
                false   ? <Redirect to="/chat"/> : <Login/> 
            )}/>
            <Route exact path="/home" render={() => (
                !auth.loggined() ? <Redirect to="/"/> : <Home/> 
            )}/>
            <Route exact path="/chat" render={() => (
                false ? <Redirect to="/"/> : <Game />
            )}/>
          </Switch>
        )

    }
}

export default withRouter(App)