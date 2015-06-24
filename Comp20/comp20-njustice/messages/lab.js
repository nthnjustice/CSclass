function parse() {
	request = new XMLHttpRequest();
	request.open("GET", "http://messagehub.herokuapp.com/messages.json", true);
	request.onreadystatechange = parseData;
	request.send();
}

function parseData() {
	if ((request.readyState == 4) && (request.status == 200)){
		messages = JSON.parse(request.responseText);

        for (i = 0; i < messages.length; i++) {
			document.getElementById("messages").innerHTML += "<p>" + messages[i]["content"] + " " + messages[i]["username"] + "</p>";         
		}   
	}
 }
