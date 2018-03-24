"use strict"
import React from 'react';
import Main from './Main';



class App extends React.Component {
    
    render(){
        console.log(this)
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