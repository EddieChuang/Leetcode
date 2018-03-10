"use strict"
import React from 'react';
import Header from './Header';
import Signin from './Signin';
import Footer from './Footer';


class App extends React.Component {
    render(){
        return (
          <div>
            {/* <Header /> */}
            <Signin />
            {/* <Footer /> */}
          </div>
        )

    }
}

export default App;