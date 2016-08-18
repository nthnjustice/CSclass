# Leg 1: Data Schema and Wireframe

## Design Rationales: 

### The data is divided into two tables: 

### Users
 - All of the pertinent information for each user is required since the
   users of the system will be employees of the institution.
 - Each user has the boolean field admin_access.  If this field is true,
   then a user will be able to view the administration panel.
 - Each user will have a list of the reports that they have filed. This
   field can be blank. 

### Reports
 - Includes a field for emergency level so that responders or employees
   at the institution know how to prioritize incidents.
 - Includes a classification (Means of classifying to be determined) so 
   that reports can be sorted. For example: medical, enviromental
 - Includes the open_closed field for the purpose of knowing if an incident
   has been resolved.  If it is closed it will be on the closed incident
   timeline and if it is open it will be on the open incident timeline.
 - The status (pending or reviewed) field is for administration.  A report
   with a pending status will be seen as unopened to admins.  A report with
   the reviewed status will be seen as opened.
 - The approved field designates whether a report should be published to
   the timeline.  If it is unapproved it will be sent to the unapproved
   (or deleted) report section of the admin panel.

# Leg 2: Implementing the Minimum Viable Product

## Ruby packages used:
  - rails
  - pg
  - sass-rails
  - uglifier
  - coffee-rails
  - jquery-rails
  - turbolinks
  - jbuilder
  - sdoc
  - rails_12factor
  - byebug
  - web-console
  - tzinfo-data

## APIs and dependencies:
  - jQuery
  - jQuery-UI
  - jQuery Cookies
  - Bootstrap
  - DataTables
  - Google Map

## Approximate time spent learning Ruby: 10

## Approximate time spent implementing the MVP: 40

## Challenges:
  1) Installing, running, and connecting a PostgreSQL database on different platforms (Windows, OS X).
  2) Connecting the MVC components together - many hours were spent trying to do this by scratch. Diligently following a handful of different online tutorials did not produce the desired results. Our group forgot about scaffolding, and in hindsight, it's astonishing to consider how many online posts we looked at without seeing any mention of scaffolding. Once we utilized this Rails feature, we were able to put together a MVP with MVC features.
  3) Figuring out how a Rails application loads assets. When deployed, local assets aren't able to be linked and utilized via HTML like in other web application frameworks. It took time to figure out how to precompile and link to assets in a "global" way for a Rails app.  

## Why Rails:
  Our group decided to use Rails because of its popularity. There is an endless sea of Rails documentation and stackoverflow posts. Additionally, we decided on Rails because of its ability to abstract the nitty-gritty details of putting together a MVC application. Rails also seemed handy because 'rails' and 'rake' commands can be configured with a global PATH on a machine. We planned on deploying our application to Heroku, and knowing Heroku has a built-in build-pack for Rails (and not Sinatra) was another reason for our decision. 

## Why PostgreSQL:
  We decided to use PostgreSQL because of it's rigor and durability. Although MySQL and SQLite would likely be sufficient for this particular project, we thought struggling through PostgreSQL's steepr learning curve would be advantageous in the long-run (such as making learning MySQL and SQLite easier in the future). PosgreSQL seemed like a safe choice without much concern of performance issues.

# Leg 3: Production, Unit Testing, Code Review

## Live URL: http://dutchess1reporter.herokuapp.com/incidents

## Why minitest:
  - RSPEC and Cucumber seemed too large for our purposes
  - an upgrade over Test::Unit
  - written in Ruby and easily integrates into the test files created by scaffolding
  - tests are run using the rake application, which is already used for database management 
  - fast
  - autodetects fixtures declared in the .yml file, making it easy to seed a database with different variants of the schema
  - fixtures and local instances can be tested simultaneously
  - minitest has an easy gem install
  - Rails autoassigns the testing environment and testing database when minitest commands are run
  - random order testing
  - allows us to focus on writing tests and not learning new frameworks
  - easy to read report, with options to customize coloration, Fail responses, and test names
  - isolates model and controller tests
  - assertion logic allows for simple to complex combinatorial arrangements of data-fields
  - works through errors (not Ruby syntax errors)
  
## Handling large amounts of visits and hits to our website
  - We will definitely find a way to use a CDN to serve all of our
    static content so that the website does not become too slow.
  - We will keep images out of our postgresql database so that the 
    database does not overflow, and database queries will be faster.
  - We will minify our javascript and css files so that fewer requests
    are being made.
  - We will use tools like yslow to find areas where our website's 
    performance can be improved.
  - We will condense our html, css, and javascript files to remove whitespaces and reduce file size.
  - We will better understand how assets are served in a Rails application so we can reduce the number of individual javascript and css files
    needed and capitalize on inheritance between actions/views in a single controller.

# Leg 4: Static Content Optimizations

## 1) Optimization techniques used:

 - A content deliver network (CDN) - "Amazon Cloudfront: Amazon Web Services"
 - JavaScript and CSS minification - (http://jscompress.com/) and (https://cssminifier.com/)
 - Combined JavaScript files and Css files
 - JavaScript placed at the bottom of the page

## 2) Tools for testing performance:

1) Before optimization
 - PageSpeed Tools - scored a C for mobile and a B for desktop
 - YSlow - scored a C
 
2) After optimization
 - PageSpeed Tools - scored a B for mobile and an A for desktop
 - YSlow - scored a A

## 3) What performance aspects have been improved:

 - The file sizes have been improved. Specifically, the file sizes of the asset files have been reduced using the minification tools.
 - The loading time has been reduced because the number of HTTP requests made for each page of the site has been reduced. Additionally, by using a CDN service like CloudFront, which has many servers all across the world, the time associated with the physical distance for asset requests has been reduced.
 - CSS placed and the top and JavaScript at the bottom has improved the user experience when visiting the page (visual cues that page is loading even when not entirely complete).

## 4) Lingering performance issues:

 - The performance of our application could be further improved by minifying our HTML code. Additionally, serving HTML content over a CDN would also improve our application's load time. This has not been addressed because we're still developing HTML code, but this issue will be addressed towards the end of development. 
 - Another lingering performance issue is to reduce the number of HTTP requests even more. As of now, we are requesting many different CDNs in our HTML code.
 - Our performance could be improved by adding expiry headers.

 # Leg 5: Writing the API

## Desicions and reasoning:

For this leg we decided to develop an open and accessible API GUI for the main features of our application. We exposed endpoints for retrieving all of the reports (called 'microposts'), retrieving a specific micropost, updating microposts, sending new microposts, and deleting specific microposts. Additionally, we exposed the endpoints for all of the same features for the 'user' model.

We decided to use Grape to build the API. We decided to use Grape because of its seamless Rails integration. It's easily installed as a gem, and it has modest configuration steps (however, configuring Grape is more difficult without a solid understanding of the Ruby language). Our API feature is consolidated into a single directory in the 'app' folder. There is a primary module that initiates an instance of Grape::API. Mounted in this module are two additional modules for the 'user' and 'micropost' endpoint and parameter configurations.

We also decided to use Swagger-UI as a front-end framework for exploring our app's API. We decided to use Swagger because of it's easy Rails integration and it's standardization policy/functionality. It seems Swagger is considerably popular as a means of standardizing and simplifying API documentation. Swagger-UI is a GUI built on top of our Grape API modules. Another reason we used Swagger-UI is because it looks really, really cool. It's not particularly light-weight, but it does seem to execute the HTTP handshake quickly. 

We decided to link our API GUI in the footer of our deployed application. 

### App URL: https://dutchessreporter.herokuapp.com/
### Direct link to the API GUI: https://dutchessreporter.herokuapp.com//apidoc#!/microposts/POST_microposts_format

THERE ARE UNUSEABLE ENDPOINTS AND WE ARE AWARE OF THIS. Our group made the decision to go ahead and implement user sign-up, log-in, authorization, and authentication features. When doing this, we put in a ton of security and functionality checks to make sure users can't be added unless under very specific circumstances - including password digests and password protection methods. More so, the circumstances for creating and updating microposts (reports) is even more strict. A micropost cannot be created unless a user is logged in and validated. Additoinally, we used strong_parameters and forgery protection methods built into Rails, which makes posting and updating data even more difficult to do outside of the app's experience.

Even though the API GUI looks like it's doing stuff with the POST and PUT methods, we are confident it is not actually executing as one would expect. For example, those endpoints don't work when using cURL. We thought it was in our best interest to leave the constraints in place because removing them solely for the API, only to then add them back in, seemed like a poor use of time.

One thing our group was thinking about... why would we want to expose our app's post and put API endpoints in the first place? Wouldn't this allow someone to manipulate our relatively sensitive data from outside our applciation? If that's the case, someone could easily disassemble the purpose of the app. We feel like we made a good decision making data write methods extremely difficult from outside the app. It seems like this is a benefit in terms of security.

#Leg 6: Polling and Memory Caching

##Polling

Our solution to the polling problem was to use simple ajax requests. The polling request queries the server's database every 15 seconds for new posts. Although 15 seconds might seem excessive, we decided that given the immediate attention needed for potential "emergencies", it's better from a practical standpoint that the requests are sent more often then not. The amount of time between polls may change if reloading a large number incident reports dramatically decreases the application's performance. The ajax requests are written using the setTimeout() function so that the next ajax request is made only after the one before it has completed. This way, if a request is taking a long time, we won't get a huge back up of several requests to our server.

We chose this simple solution over something like websockets for several reasons. For our purposes, we do not need real time updates so web sockets are unneccessary. The implementation of ajax requests is much more simple than writing the code to implement web socket connections which we don't know much about. As for drawbacks to our decision, there are a few: The posts will be refreshed every 15 seconds, as long as a user has our website open. Regardless of whether a user is active on our page, the polling will occur. Also, if no new posts are made for a few hours, then we are doing a lot of 'wasteful' queries to our server. However, in our current situation this does not seem like a huge issue given the small number of users that will be on our site. If in the future our user base expands and our servers are struggling to handle the load, we will look into something like web sockets.

When a polling request is sent to our server, it is directed via a routing method to execute an action in the static_pages controller called "polling". This action does two things: 1) refreshes the global report-feed's queried content with all of the reports in the database, bypassing the cache to ensure all new and updated reports are returned to the user and 2) the action executes a javascript file that refreshes the partial that renders the global report-feed. Our implementation is advantageous in that a polling request does not reload the entire page, but just the dynamic content embedded in the page. This design enhances the efficiency of our polling feature by reducing the amount of data retrieved from the server to the bare minimum.

Currently we reload all of the posts with each ajax request, but in the immediate future we plan to refine the feature to only reload the global report-feed if a new one has been stored or if an old report has been updated. This will again enhance the efficiency of our application by reducing the amount of redundant data retrieved from the server. 

##Caching

For our caching solution we used Memcached. We chose to use memcached because it seemed like there is a ton of documentationon using Memcached with Rails. Also, there is a readily available heroku addon called "Memcached Cloud", which we used to enable caching in production. Additionally, the Memcached Cloud addon has nifty data tracking features that helps us assess the amount of data cached by our users. Redis offers data persistence, but we did not see this feature as something that outweighed the steeper learning curve and available information on using Memcached with Rails.

To implement caching, all we were required to do was update the config file, add the dalli gem, and insert a few lines of code in the app to change a database query to a cache fetch. The cache fetch method is very slick because it first searches the cache for available data, if there is nothing in the cache, the fetch method then queries the database and stores the query in the cache. That is to say, the fetch method executes both read and write methods in the appropriate order (the order being, 1) check the cache, and if the cache is empty 2) check the database). Our current implementation caches all of the incident reports. Additionally, we have implemented a session-storage feature that uses caching and cookie-storage for log-in information for activated users who wish to remain logged in on the app even after closing the browser.  