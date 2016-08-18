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