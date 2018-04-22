"use strict"
import React from 'react'
import {Switch, Route, Redirect, withRouter} from 'react-router-dom'

import {Home, Login, Main} from './pages'
import auth from "../utils/auth"

class App extends React.Component {
    
    render(){
        return (
          <Switch>
            <Route exact path="/" render={() => (
                auth.loggined() ? <Redirect to="/home"/> : 
                auth.inRoom()   ? <Redirect to="/chat"/> : <Login/> 
            )}/>
            <Route exact path="/home" render={() => (
                auth.loggined() ? <Home/> :  <Redirect to="/"/>
            )}/>
            <Route exact path="/chat" render={() => (
                auth.inRoom() ? <Main /> :  <Redirect to="/"/>
            )}/>
          </Switch>
        )

    }
}

export default withRouter(App)