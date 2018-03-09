"use strict";
import React from 'react';
import {Link} from 'react-router-dom';

class Footer extends React.Component {
    render(){
        return (
          <footer className="footer text-center">
            <div className="container">
              <Link to='/admin/'>Admin</Link>
              <p className="footer-text">Copyright 2018 Digiedu. All rights reserved.</p>
            </div>
          </footer>
        )
    }
}

export default Footer;