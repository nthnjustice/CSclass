//Initialization
var express = require('express');
var bodyParser = require('body-parser');
var validator = require('validator');
var app = express();
var serveStatic = require('serve-static');
var request = require('request');
var cheerio = require('cheerio');
var fs = require('fs');
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

//Mongo Init
var mongoUri = process.env.MONGOLAB_URI || process.env.MONGOHQ_URL;
var MongoClient = require('mongodb').MongoClient, format = require('util').format;
var db = MongoClient.connect(mongoUri, function(error, databaseConnection) {
	db = databaseConnection;
});

//CORS
app.use(function(req, res, next) {
  res.header("Access-Control-Allow-Origin", "*");
  res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
  next();
 });

app.use(express.static('Bootstrap'));

//set the home page route
app.get('/', function(req, res) {
	res.header("Access-Control-Allow-Origin", "*");
  	res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
	res.set('Content-Type', 'text/html');
    res.send('index.html');
});

app.get('/scrapeCarm', function(req, res){
	res.header("Access-Control-Allow-Origin", "*");
  	res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
	res.set('Content-Type', 'text/html');

	url = 'http://menus.tufts.edu/foodpro/shortmenu.asp?sName=Tufts+Dining&locationNum=09&locationName=Carmichael+Dining+Center&naFlag=1';

	request(url, function(error, response, html){
		if(!error){
			var $ = cheerio.load(html);

			var recipes = [];

			var json = {recipes: ""};

			$('div.shortmenurecipes').each(function(i, elem) {
  				recipes[i] = $(this).text();
			});
			json.recipes = recipes;
		}
        res.send(json);
	});
});	

app.get('/scrapeDewick', function(req, res){
	res.header("Access-Control-Allow-Origin", "*");
  	res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
	res.set('Content-Type', 'text/html');

	url = 'http://menus.tufts.edu/foodpro/shortmenu.asp?sName=Tufts+Dining&locationNum=11&locationName=Dewick+MacPhie+Dining+Center&naFlag=1';

	request(url, function(error, response, html){
		if(!error){
			var $ = cheerio.load(html);

			var recipes = [];

			var json = {recipes: ""};

			$('div.shortmenurecipes').each(function(i, elem) {
  				recipes[i] = $(this).text();
			});
			json.recipes = recipes;
		}
        res.send(json);
	});
});

app.get('/scrapeHodgdon', function(req, res){
	res.header("Access-Control-Allow-Origin", "*");
  	res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
	res.set('Content-Type', 'text/html');

	url = 'http://menus.tufts.edu/foodpro/shortmenu.asp?sName=Tufts+Dining&locationNum=14&locationName=Hodgdon+Good-+To-+Go+Take-+Out&naFlag=1';

	request(url, function(error, response, html){
		if(!error){
			var $ = cheerio.load(html);

			var recipes = [];

			var json = {recipes: ""};

			$('div.shortmenurecipes').each(function(i, elem) {
  				recipes[i] = $(this).text();
			});
			json.recipes = recipes;
		}
        res.send(json);
	});
});		

app.get('/addFood', function(req, res) {
	res.header("Access-Control-Allow-Origin", "*");
    res.header("Access-Control-Allow-Headers", "X-Requested-With");
	res.set('Content-Type', 'text/html');

	var allFood = [];

	db.collection('inventory', function(er, collection) {
		collection.find().toArray(function(err, cursor) {
			if (!err) {
				for (var i = 0; i < cursor.length; i++) {
					allFood[i] = cursor[i].item;
				}
				res.send(allFood);
			}
			else {
				res.send("<!DOCTYPE html><html><head><title>ERROR</title></head><body><h1>Dammit... This is bad.</h1></body></html>")
			}
		});
	});
});

app.get('/formatJSON', function(req, res) {
	res.header("Access-Control-Allow-Origin", "*");
    res.header("Access-Control-Allow-Headers", "X-Requested-With");
	res.set('Content-Type', 'text/html');

		var json = {name: "hodg_items", children: ""};
		var children = [];

/*{"price": {$lte: 6.10}}, {"_id": 0, "price": 0, "category": 0, "item": 1, "type": 1, "weekly_count": 1}*/
	db.collection('inventory', function(er, collection) {
		collection.find().toArray(function(err, cursor) {
			if (!err) {

				//categories = db.collection.distinct("type");
				//for (var j = 0; j < categories.length; j++) {
/*
					children[j] = {name: categories[j], children: ""};
					var children_two = [];

					for (var i = 0; i < cursor.length; i++) {
						if (cursor[i].type == categories[j]){
							children_two.push( {"name": cursor[i].item, "size": cursor[i].weekly_count} );
						}
					}
					children[j].children = children_two;*/
				//}
				json.children = children;

				res.send(json);
			}
			else {
				res.send("<!DOCTYPE html><html><head><title>ERROR</title></head><body><h1>Dammit... This is bad.</h1></body></html>");
			}
		});
	});
});


app.post('/updateUser', function(req, res) {
	var login = req.body.login;
	var items = req.body.items;
	if( login == undefined || items == undefined ) {
		res.send( {"error":"Whoops, something is wrong with your data!"} );
	}
	else {
		var toInsert = {
		"login": login, "items": items
		};

		db.collection('users', function(error1, coll) {
			if( coll.find({"login": login}) != undefined ) {
				coll.remove( {"login":login} );
			}
			var id = coll.insert(toInsert, function(error2, saved) {
				if (error2) {
					res.send(500);
				}
				else {
					res.send(200);
				}
		   	});
		});
	}
});
/*

app.get('/getCart.json', function(request, response) {
	var login = request.query.login;

	if( login == undefined ) {
		response.send( {"error":"Whoops, something is wrong with your data!"} );
	}

	else {
		var allFood = [];

		db.collection('users', function(er, collection) {

			else {
				collection.find({ "login": login }).nextObject(function(err, data) {
					if (!err) {
						response.send(data);
					}
					else {
						response.send("<!DOCTYPE html><html><head><title>ERROR</title></head><body><h1>Dammit... This is bad.</h1></body></html>")
					}
				});
			}
		});
	}
});

*/
app.post('/storePhones', function (req, res) {
	res.header("Access-Control-Allow-Origin", "*");
    res.header("Access-Control-Allow-Headers", "X-Requested-With");
    res.set('Content-Type', 'text/html');

	var user = req.body.user;
	var number = req.body.number; 


	if (user == undefined || number == undefined){
		res.send({"error":"Whoops, something is wrong with your data!"});
	}
	else {

		var toInsert = {
			"user": user,
			"number": number
		};
	
		db.collection('user_numbers', function (err1, coll) {
			var insertDoc = coll.insert(toInsert, function(err2, saved) {
				if (err2) {
					res.send(500);
				}
				else {
					res.send(JSON.stringify(insertDoc));
				}
			});
		});	
	}
});

//Functionality
app.listen(process.env.PORT || 3000);


