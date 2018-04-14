"use strict"
import React from 'react';
import ReactDOM from 'react-dom';
// import {Router, Route, IndexRoute, browserHistory} from 'react-router';
// import {Provider} from 'react-redux';
// import {applyMiddleware, createStore} from 'redux';
// import reducers from './reducers';
// import logger from 'redux-logger';
// import thunk from 'redux-thunk';
import { BrowserRouter } from 'react-router-dom';
import App from './components/App';

// const middleware = applyMiddleware(thunk, logger);
// const store = createStore(reducers, middleware);

console.log("app")

require('./style/main.scss')

const Routes = (
  // <Provider store={store}>
    <BrowserRouter>
      <App />
    </BrowserRouter>
  // </Provider>
)
ReactDOM.render(
    Routes, document.getElementById("app")
);
