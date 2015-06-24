$(document).ready(function () {
  var po = document.createElement('script'); 
  po.type = 'text/javascript'; 
  po.async = true;
  po.src = 'https://apis.google.com/js/client:plusone.js?onload=signinCallback';
  var s = document.getElementsByTagName('script')[0]; 
  s.parentNode.insertBefore(po, s);
  //yourCart();
});

// function yourCart() {
//   xhr = new XMLHttpRequest();

//   var url = "https://hodgdon.herokuapp.com/getCart.json";
//   xhr.open("GET", url, true);

//   xhr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");

//   params = "login=" + localStorage['username'];
//   xhr.send(params);

//   xhr.onreadystatechange = function()  {
//     if (xhr.readyState == 4 && xhr.status == 200) {
//       data = JSON.parse(xhr.responseText);

//       console.log(data);
//       console.log(data.items)

//       if( data == undefined ) {
//         data = "<p>Looks like your cart is empty!<p>";
//       }
//       else {
//         data = data.items
//       }
//       document.getElementById("scrollBox").innerHTML = data;
//     }
//   }
// }

function yourCart() {
  $("div #hideMe").hide('fast');
  $("div #hideMe2").show('fast');

  /*val = [];

  for (i = 0; i <= localStorage.length-1; i++) {   
    key = sessionStorage.key(i);  
    val[i] = sessionStorage.getItem(key);   
  } 

  for (i = 0; i < val.length; i++) {
    $("ul #theCartd").append('<li role="presentation" id="'+i+'"><a role="menuitem" tabindex="-1" href="#" data-toggle="dropdown">'+val[i]+'</a></li>');
  }*/
}

function addFood () {
  xhr = new XMLHttpRequest();
  var url = "https://hodgdon.herokuapp.com/addFood";
  xhr.open("GET", url, true);
  xhr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
  xhr.send();
  xhr.onreadystatechange = bringInFood 
}

function bringInFood() {
  if (xhr.readyState == 4 && xhr.status == 200) {
      var data = JSON.parse(xhr.responseText);
      data = data.sort();
      $("div #hideMe").show('fast');
      $("div #hideMe2").hide('fast');
      for (i = 0; i < data.length; i++) {
        $("ul #allFood").append('<li role="presentation"><a role="menuitem" tabindex="-1" href="#" data-toggle="dropdown">'+data[i]+'</a></li>');
      }
  }
}

function suggestions() {

}

function signinCallback(authResult) {
  console.log(authResult);
  if (authResult['status']['signed_in']) {
    document.getElementById('signIn').setAttribute('style', 'display: none');
    makeAPICall();
 
  } 
  else {
    document.getElementById('cartBody').innerHTML = "";
    document.getElementById('errorMsg').innerHTML = "Ooops! You'll need to sign in <a href='index.html'>here</a> to use the shopping cart feature.";
    document.getElementById('errorMsg').setAttribute('style', 'text-align: center'); 
    document.getElementById('signIn').setAttribute('style', 'display: none'); 
  }
}


function makeAPICall(){
  gapi.client.load('plus', 'v1', function() {
    var request = gapi.client.plus.people.get({
      'userId': 'me'
    });
    request.execute(function (resp){
      if(resp.displayName){
        console.log(resp.id);
        localStorage['username'] = resp.id;
      }
    }); 
  });
}
