import React from 'react';
import {Switch, Route} from 'react-router-dom';
import Home from './Home';
import Signin from './Signin';


class Main extends React.Component {
  render(){
    return(
      <Switch>
        <Route exact path="/" component={Signin} />
        <Route exact path="/home" component={Home} />
        <Route exact path="#" component={Home} />
      </Switch>
    )
  }
}

export default Main;