$(document).ready(function () {
  var po = document.createElement('script'); 
  po.type = 'text/javascript'; 
  po.async = true;
  po.src = 'https://apis.google.com/js/client:plusone.js?onload=signinCallback';
  var s = document.getElementsByTagName('script')[0]; 
  s.parentNode.insertBefore(po, s);
});

function signinCallback(authResult) {
  console.log(authResult);
  if (authResult['status']['signed_in']) {
    makeAPICall();
    document.getElementById('signinButton').setAttribute('style', 'display: none'); 
    // $(location).attr('href',"cart.html");
  } 
  else {
    // Possible error values:
    //   "user_sgned_out" - User is signed-out
    //   "ac_denied" - User denied access to your app
    //   "immediate_failed" - Could not automatically log in the user
    document.getElementById('sessionStatus').innerHtML = "<p>Oops! You cannot be logged in at this time. Please try again.</p>";
  }
}

function makeAPICall(){
  gapi.client.load('plus', 'v1', function() {
    var request = gapi.client.plus.people.get({
      'userId': 'me'
    });
    request.execute(function (resp){
      if(resp.displayName){
        var ele = document.getElementById('sessionStatus');
        ele.innerHTML = "<p>You are logged in, " + resp.displayName + "!</p><p>Click <a href='cart.html'>here</a> to go to your shopping cart.</p>";
        document.getElementById('sessionStatus').setAttribute('style', 'text-align: center'); 
      }
    }); 
  });
}

function storeNumbers(){
  var request = new XMLHttpRequest();

  var user = document.getElementById("inputName").value;
  var number = document.getElementById("inputNumber").value;


  request.open("POST", "https://hodgdon.herokuapp.com/storePhones", true); 
  request.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
  request.send('user=' + user + '&number=' + number);
}


