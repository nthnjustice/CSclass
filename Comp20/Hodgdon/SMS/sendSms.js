var request = new XMLHttpRequest();
var people = [];

$(document).ready(function () {
	if (request.readyState == 4 && request.status == 200){
		converted = JSON.parse(request.responseText);
		for (i = 0; i < converted.length; i++){
			username = converted[i]['user'];
			usernumber = "+" + converted[i]['number'];
			people.push({user: username, number: usernumber});
		}
		sendMessages();
	}
	else if (request.readyState == 4 && request.status != 200){
		alert("Page not loaded.");
	}
});
 
function sendMessages(){
	var d = new Date();
	var day = d.getDay();
	var h = d.getHours();
	var m = d.getMinutes();
	var accountSid = "AC9331b20275100653fbae1e451103247f";
	var authToken = "ebfe6402401234c880f077251b05c036";
	var client = require('twilio')(accountSid, authToken);

	if (day > 0 && day < 6){
	    if (h == 8 && m == 0){
	    	for (var i = 0; i < people.length; i++){
				client.messages.create({
					body:"Hey " + people[i].user + ", a new meal period has begun. It is now breakfast.",
					to: people[i].number,
					from: "408-824-1163"
				}, function(err, message){
					process.stdout.write(message.sid);
				});
			}
		}
		else if (h == 11 && m == 0){
			for (var i = 0; i < people.length; i++){
				client.messages.create({
					body:"Hey " + people[i].user + ", a new meal period has begun. It is now lunch.",
					to: people[i].number,
					from: "408-824-1163"
				}, function(err, message){
					process.stdout.write(message.sid);
				});
			}
		}
		else if (h == 17 && m == 0){
			for (var i = 0; i < people.length; i++){
				client.messages.create({
					body:"Hey " + people[i].user + ", a new meal period has begun. It is now dinner.",
					to: people[i].number,
					from: "408-824-1163"
				}, function(err, message){
					process.stdout.write(message.sid);
				});
			}	
		}
	}
}

