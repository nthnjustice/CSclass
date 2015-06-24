<!DOCTYPE html>

<?php
	if (!empty($_POST["fullname"])) {
		$price = $_POST["price"];
		$fullname = $_POST["fullname"];
		$beverage = $_POST["beverage"];
		$str = "<h1>Hello $fullname</h1>\n<h1>The price you have to pay is $price</h1>\n<h1>Your favorite beverage is $beverage</h1>";
	}
?>
<html>
<head>
<title>Hack Me Playground</title>
</head>

<body>
	<div id="theform">
		<form method="post" action="hackme.php">
			<input type="hidden" name="price" value="100" />
			<p>What is your name (max length of 15 characters)? <input type="text" name="fullname" maxlength="15" /></p>
			<p>What is your favorite beverage?</p>
			<p>
				<input type="radio" name="beverage" value="Water" /> Water<br/>
				<input type="radio" name="beverage" value="Coffee" /> Coffee<br/>
				<input type="radio" name="beverage" value="Tea" /> Tea<br/>
				<input type="radio" name="beverage" value="Soda" /> Soda<br/>
			</p>
			<p><input type="submit" name="submitBtn" value="Go!" /></p>
		</form>
	</div>
	<div id="results">
	<?php
		if (isset($str)) {
			echo "$str";
		}
	?>
	</div>
</body>
</html>
