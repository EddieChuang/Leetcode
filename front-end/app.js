"use strict"
var express = require('express');
var path = require('path');


var app = express();

// MIDDLEWARE TO DEFINE FOLDER FOR STATIC FILES
app.use(express.static('public'));

// var allowCrossDomain = function(req, res, next) {
//   res.header('Access-Control-Allow-Origin', "*");
//   res.header('Access-Control-Allow-Methods', 'GET,PUT,POST,DELETE');
//   res.header('Access-Control-Allow-Headers', 'Content-Type');
//   next();
// }

// app.configure(function(){
  // app.use(allowCrossDomain);
// });


app.get('*', function(req, res){
    res.sendFile(path.resolve(__dirname, 'public', 'index.html'));
});

app.listen(3000, function(){
    console.log('app is listening on port 3000...');
});