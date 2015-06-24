$(document).ready(function () {
         var po = document.createElement('script'); 
         po.type = 'text/javascript'; 
         po.async = true;
         po.src = 'https://apis.google.com/js/client:plusone.js?onload=signinCallback';
         var s = document.getElementsByTagName('script')[0]; 
         s.parentNode.insertBefore(po, s);
      });

function signinCallback(authResult) {
    if (authResult['status']['signed_in']) {
            document.getElementById('signinButton').setAttribute('style', 'display: none');
                makeAPICall();
    } else {
        console.log('Sign-in state: ' + authResult['error']);
    }
}

function makeAPICall(){
gapi.client.load('plus', 'v1', function() {
  var request = gapi.client.plus.people.get({
    'userId': 'me'
  });
  request.execute(function (resp){
    console.log(resp);
    if(resp.id){
      console.log('ID: ' + resp.id);
    }
    if(resp.displayName){
      console.log('Display Name: ' + resp.displayName);
    }
    if(resp.image && resp.image.url){
      console.log('Image URL: ' + resp.image.url);
    }
    if(resp.url){
      console.log('Profile URL: ' + resp.url);
    }
  });
});
}
