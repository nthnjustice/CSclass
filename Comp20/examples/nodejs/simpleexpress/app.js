// Taken from http://expressjs.com/4x/api.html
var express = require('express');
var app = express();

app.get('/', function(request, response) {
	response.send("Hello world");
});

app.get('/pikachu', function(request, response) {
	response.send("You've won the game!");
});

app.listen(8888);
