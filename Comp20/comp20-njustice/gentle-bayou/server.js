//Express init
var express = require('express');
var bodyParser = require('body-parser');
//A library of string validators and sanitizers.
var validator = require('validator'); //See documentation at https://github.com/chriso/validator.js
var app = express();
// See https://stackoverflow.com/questions/5710358/how-to-get-post-query-in-express-node-js
app.use(bodyParser.json()); //To support JSON-encoded bodies
// See https://stackoverflow.com/questions/25471856/express-throws-error-as-body-parser-deprecated-undefined-extended
app.use(bodyParser.urlencoded({ extended: true })); //To support URL-encoded bodies

//Mongo initialization and connect to database
var mongoUri = process.env.MONGOLAB_URI || process.env.MONGOHQ_URL || "mongodb:njusti01:@ds061621.mongolab.com:61621/heroku_app35686666";
var MongoClient = require('mongodb').MongoClient, format = require('util').format;
var db = MongoClient.connect(mongoUri, function(error, databaseConnection) {
	db = databaseConnection;
});

//Enable CORES - code from Alex Goldschmidt
app.use(function(req, res, next) {
  res.header("Access-Control-Allow-Origin", "*");
  res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
  next();
 });

/*****************************************************************************/
/*
POST: /sendLocation API

Submits check-in from any domain.
Mandatory fields: login, lat, lng
Successful submission of these three pieces of data shall result in one entry into the collection locations in Mongo.
If a submission is missing any one of the data fields, do not insert new record into the database and send the following JSON as the response: {"error":"Whoops, something is wrong with your data!"}
*/
app.post('/sendLocation', function(request, response) {
	var lng = parseFloat(request.body.lng); //Converts plain-text to Float
	var lat = parseFloat(request.body.lat); //Converts plain-text to Float
	var login = request.body.login;
	var created_at = new Date(); //Timestamp
	//Handle missing parameters 
	if (lng == undefined || lat == undefined || login == undefined) {
    	response.send({"error":"Whoops, something is wrong with your data!"});
  	}
  	else {
  		//Store the following
    	var toInsert = {"login": login, "lat": lat, "lng": lng, "created_at": created_at.toUTCString()};
    	//Access Mongo
		db.collection('locations', function(error1, coll) {
			//Remove duplicates
			if (coll.find({"login": login}) != undefined) {
				coll.remove({"login": login});
			}
			var id = coll.insert(toInsert, function(error2, saved) {
				//Failed insertion
				if (error2) {
					response.send(500);
				}
				//Successful insertion
				else {
					//Find all documents, organize in an array
					coll.find({}).toArray(function(err, docs) {
						//Return an array of documents
						response.send(docs);
					})
				}
	    	});
		});
	}
});

/*****************************************************************************/
/*
GET: /location.json
Returns a JSON string, one object, of the last known location for a specified login.
The mandatory parameter for this API is login.
If login is empty or no results found, return empty JSON object {}
*/
app.get('/location.json', function(request, response) {
	//Check that query string is valid
    var login = request.query.login;
    //If not, return an empty JSON object
    if (login == undefined) {
        response.send({});
    } 
    else {
        db.collection('locations', function(error1, collection) {
            var query = {};
            //Assign dictionary to JSON query
            query["login"] = login;
            //Navigate database for the document
            collection.find(query).nextObject(function(error2, item) {
            	//If the document doesn't exist, return an empty JSON object
                if (item == undefined) {
                    response.send({});
                } else {
                	//Return JSON object for query
                    response.send(item);
                }
            });
        });
    }
});

/*****************************************************************************/
/*
GET: / -Home/Root/index.html
Accessing this on a web browser shall display list of the check-ins for all logins sorted in descending order by timestamp
	-the last person who checked-in is displayed first.
Example output:
	kaytea checked in at 41.903056, 12.454444 on 2015-02-22T04:53:57.214Z
*/
app.get('/', function(request, response) {
	//CORS - Duplicated from above? Is this necessary here?
	response.header("Access-Control-Allow-Origin", "*");
    response.header("Access-Control-Allow-Headers", "X-Requested-With");
	response.set('Content-Type', 'text/html');

	var indexPage = ""; //Index page to build
	//Access Mongo
	db.collection('locations', function(er, collection) {
		//Reverse documents and organize in an array
		collection.find().sort({ created_at : -1 }).toArray(function(err, cursor) {
			//Successful in accessing database
			if (!err) {
				//Build HTML
				indexPage += "<!DOCTYPE html><html><head><title>Where the...</title></head><body><h1>Where ya'll at?</h1>";
				for (var i = 0; i < cursor.length; i++) {
					//Build HTML output
					indexPage += "<p>" + cursor[i].login + " reported in " + cursor[i].lat + ", " + cursor[i].lng + " at " + cursor[i].created_at + "</p>";
				}
				indexPage += "</body></html>";
				//Send to index page
				response.send(indexPage);
			}
			else{
				//Failed to access database
				response.send("<!DOCTYPE html><html><head><title>Where the...</title></head><body><h1>Dammit... This is bad, really, really bad. Something's wrong!</h1></body></html>");
			}
		});
	});
});

/*****************************************************************************/
// Oh joy! http://stackoverflow.com/questions/15693192/heroku-node-js-error-web-process-failed-to-bind-to-port-within-60-seconds-of
app.listen(process.env.PORT || 3000);