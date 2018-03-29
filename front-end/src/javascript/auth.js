import axios from 'axios';

export default {
    login: function(username, password, callback){
        // if(localStorage.token){
        //     if(callback)
        //         callback(true)
        //     return
        // }

        let user = {"username": username, "password": password}
        axios.post('http://localhost:8000/login/', user)
          .then((response) => {
              console.log(response)
              localStorage.token = response.data.token
              callback(true)
          })
          .catch((error) => {
              callback(false)
          })
    },

    logout: function(){
        delete localStorage.token
    },

    loggined: function(){
        return !!localStorage.token
    }
}