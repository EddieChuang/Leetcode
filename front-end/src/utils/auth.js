import axios from 'axios';
import {URL_AUTHROOM, URL_LOGIN} from '../constants/url'

export default {
    login: (username, password, callback) => {
        // if(sessionStorage.token){
        //     if(callback)
        //         callback(true)
        //     return
        // }

        // let user = {"username": username, "password": password}
        let user = new FormData()
        user.append("username", username)
        user.append("password", password)
        axios.post(URL_LOGIN, user)
          .then((res) => {
              console.log(res)
              let user = {
                'type': 'teacher', 
                'key': '', 
                'name': username, 
                'note': ''
              }
              sessionStorage.token = res.data.token
              sessionStorage.user = JSON.stringify(user)
              callback(true)
          })
          .catch((err) => {
              // console.log(err.response.data.res)
              callback(false, err.response.data.res)
          })
    },

    logout: () => {
        delete sessionStorage.token
        delete sessionStorage.user
    },

    loggined: () => {
        return !!sessionStorage.token
    },

    

    authRoom: (key, team, note, callback) => {

        let req = new FormData()
        req.append("key", key)
        req.append("team_name", team)
        req.append("note", note)
        axios.post(URL_AUTHROOM, req)
          .then((res) => {
              let user = {
                'type': 'team', 
                'key': res.data.team.key, 
                'name': res.data.team.name, 
                'note': res.data.team.note
              }
              sessionStorage.user = JSON.stringify(user)
              sessionStorage.label = res.data.label
              callback(true, res.data)
          })
          .catch((err) => {
              console.log(err)
              callback(false, err.response)
          })
    },
    leaveRoom: () => {
      delete sessionStorage.user
      delete sessionStorage.label
    },
    inRoom: () => {
      return !!sessionStorage.user
    }

}