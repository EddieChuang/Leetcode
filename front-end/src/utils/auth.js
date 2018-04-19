import axios from 'axios';

export default {
    login: function(username, password, callback){
        // if(localStorage.token){
        //     if(callback)
        //         callback(true)
        //     return
        // }

        // let user = {"username": username, "password": password}
        let user = new FormData()
        user.append("username", username)
        user.append("password", password)
        axios.post('http://localhost:8000/login/', user)
          .then((res) => {
              console.log(res)
              localStorage.token = res.data.token
              localStorage.username = username
              callback(true)
          })
          .catch((err) => {
              // console.log(err.response.data.res)
              callback(false, err.response.data.res)
          })
    },

    logout: function(){
        delete localStorage.token
        delete localStorage.username
    },

    loggined: function(){
        return !!localStorage.token
    },

    authRoom: function(key, team, note, callback){

        let req = new FormData()
        req.append("key", key)
        req.append("team_name", team)
        req.append("note", note)
        axios.post('http://localhost:8000/chat/authRoom/', req)
          .then((res) => {
              callback(true, res.data)
          })
          .catch((err) => {
              console.log(err)
              callback(false, err.response)
          })
    },

    // inRoom: function(){
    //     return !!localStorage.user
    // },

    // leaveRoom: function(){
    //     delete localStorage.user
    // }

}