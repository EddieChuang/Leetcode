import React from 'react';
import {Switch, Route} from 'react-router-dom';
import Home from './Home';

class Main extends React.Component {
  render(){
    return(
      <Switch>
        <Route exact path="/" component={Home} />
        <Route exact path="/" component={Home} />
        <Route exact path="/" component={Home} />
      </Switch>
    )
  }
}

export default Main;