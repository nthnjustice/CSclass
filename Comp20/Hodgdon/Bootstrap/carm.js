$(document).ready(function () {
	getData();
});


function getData() {
	xhr = new XMLHttpRequest();

	var url = "https://hodgdon.herokuapp.com/scrapeCarm";
	xhr.open("GET", url, true);

	xhr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");

	xhr.send();

	xhr.onreadystatechange = function()  {
	    if (xhr.readyState == 4 && xhr.status == 200) {
			var data = JSON.parse(xhr.responseText);
			data = data.recipes;

			document.getElementById('carmMenu').innerHTML = data;
	    }
	}
}