"use strict"
import React from 'react';
import Header from './Header';
import Signin from './Signin';
import Footer from './Footer';
import Main from './Main';



class App extends React.Component {
    render(){
        return (
          <div>
            {/* <Header /> */}
            <Main />
            {/* <Footer /> */}
          </div>
        )

    }
}

export default App;