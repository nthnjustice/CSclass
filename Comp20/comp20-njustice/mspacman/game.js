function init() {
	//create canvas object
	var canvas = document.getElementById("game_canvas");
	//exception handling - test if browser supports HTML5 <canvas>
	if (canvas.getContext) {
		//create rendering object for 2d image
		var ctx = canvas.getContext('2d');
		//create image object for Google-board
		var image = new Image();
		image.src = 'pacman10-hp-sprite.png';
		//create image object for Ms. Pacman
		var pacman = new Image();
		pacman.src = 'pacman10-hp-sprite.png';
		//create audio object for intro music
		var audio = new Audio('PacmanIntroMusic.mp3');
		//function to draw images when the page 
		image.onload = function () {
			//play intro music
			audio.play();
			//draw Google-board 
			ctx.drawImage(image, 320, 0, 465, 139, 0, 0, 465, 139);
			//draw Ms. Pacman
			ctx.drawImage(pacman, 83, 22, 17, 15, 39, 32, 17, 15);
		}
	}
	//notify user if their browser doesn't support HTML5 <canvas>
	else {
		alert('Your stupid browser does not support canvas!');
	}	
}