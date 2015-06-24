#January 15, 2015: Course Introduction
* See slides
* Why are we here?  What is the World Wide Web (a.k.a., www or web)?
* The telephone analogy: two people talking to each other on the phone
* Two computers talking to each other: networking
* The world's largest network: the Internet. Many services
  - One of those services: the World Wide Web
  - Many clients and many servers

#January 20, 2015: HyperText Transfer Protocol (HTTP)
* Last class: course expectations; basic networking; what and why WWW
* Today: _How_ the web works; NO ACCESS TO A WEB BROWSER ALLOWED IN CLASS TODAY!
* PSA: Harassment
* Recall from last class: two computers talking to each other, IP address
* In lay terms _how_ the web works: the Siri scenario; question-and-answer
* Client and server
* The technical details: request and response via HTTP
* How to request a file => URI `<protocol>://<server>/<path>/<file>`
* The big idea: simple protocol
  * Request commends: GET, POST
  * Request header to server
  * Response data from server to client
* The big question: _How do you browser the web without a modern web browser?_

#January 22, 2015: HyperText Markup Language (HTML)
* Good news everyone!
* Last class: how the web works
* Review: What kind of a protocol is HTTP?
* Review: HTTP request commands?
* Review: Fields in HTTP request header?  In response header? https://twitter.com/brunoborges/status/548626650850922498
* Review: True of false --typing in a URL in address bar of a modern web browswer will always execute HTTP GET.
* The HTTP response _data_
* The idea of markup: think of markups on an essay or English paper.  Why?
* The difficulty of markups from a computing sense 50+ years ago
* SGML => HTML. The idea: determines document appearance and behavior
* Elements (or tags)
  - Start tag
  - End tag
  - Attributes (key-value pairs)
  - Content
* Two types of tags: block and inline
* HTML => lax rules
* HTML5 => stricter rules
* The big question: _How do you build a web browser?_

#January 29, 2015: HTML (continued); Git
* Last class: HTML => document appearance and behavior; _how do you build a web browser?_
* What I am NOT going to do: discuss every HTML tag
* What is important to discuss: the finer points of HTML
  - Recall last class: what's peculiar about HTML? (hints: closing tags, attributes, nesting)
  - Two types of HTML body elements: block level and inline
* Another topic: revision control
* The nightmare scenario that illustrates the need for revision control: in the past...
* What if I need to hire developers to work on different pieces of a projet?
* Why revision control? Keep track of changes, document changes
* Why Git? Speed, no dependency of a remote server (unlike Subversion)
* Why GitHub for repositories? Network effect
* Example with our course website

#February 3, 2015: HTML (continued); Cascading Style Sheets (CSS)
* Last class: revision control with Git, started talking about finer points of HTML (block vs inline elements)
* Where we left off: HTML attributes, relative vs absolute URLs 
  - Absolute vs. relative URLs
  - Example of inline element: `<img>`. `<img>` also have some interesting attributes...
  - Good form HTML => HTML5 and the W3C validator
  - Recite https://github.com/tuftsdev/WebProgramming/tree/gh-pages/examples/html
* Why do you want to separate style?


#February 5, 2015: Cascading Style Sheets (CSS)
* Last class: HTML and started talking about the idea of a style sheet.
* Why style sheet?
* One CSS _rule_ is made up of _selectors_ and _declarations_. A declaration is a _property-value_ pair.
  - You really want to refer to a CSS cheat sheet!
* Three types of selectors: HTML tag names, ID, class
  - ID: should only be used once; starts with "#"
  - class: can be used many times; start with "."
  - Mixing IDs and classes is confusing, generally not a good idea.
  - "id" and "class" attribute exist for all HTML elements
  - Generic block HTML element: div
  - Generic inline HTML element: span
* Box model for HTML body elements
* The "cascading" in "cascading style sheet"
  - What if there is more than one style specified for an HTML element?
* Loading additional stylesheets

#February 12, 2015: Cascading Style Sheets (CSS), Part II
* Last class: CSS, the box model --what is that?
* The big idea today: mobile and responsive design --responding to different screen sizes
* The example we worked on last class: now publicly hosted on http://www.cs.tufts.edu/comp/20/news.html.  How does it look on a tablet/phone/phablet?
* Viewport: scale to the available screen area.  Problem: general assumption of mobile browsers is that a webpage is 980px wide!  Alas, the content is less readable.
* Can we use different stylesheets, or apply different styles, for different screen sizes?  Absolutely!  Thanks to the idea of _media queries_ in CSS version 3.
  - Media queries can be done in `<link>` tag or in CSS file
* Lab 4: the other big idea stressed is the idea of a _sprite sheet_.  Used by many major websites including Facebook, Instagram.

#February 17, 2015: JavaScript
* So far, we have covered quite a bit: HTTP, HTML, CSS, Git
* What are the problems and limitations with just HTML and CSS?
* HTTP: stateless protocol, no memory of previous requests
* In the early 90s, "Netscape quickly realized that the Web needed to become more dynamic. Even if you simply wanted to check that users entered correct values in a form, you needed to send the data to the server in order to give feedback." http://speakingjs.com/es5/ch04.html
* Our focus is still on the client-side
* Variables: dynamic typing but will be one of the following: number, string, array, object, boolean
  - Three states of a variable: (1) not set yet (undefined), (2)set to nothing (null), (3) set to a valid value
* Operations: "+" is interesting
* Function arguments: (1) too many: extras ignored, (2) too few: remainders get an undefined value
* Lists (a.k.a., arrays)
* _(Almost) everything in JavaScript is an object_ https://stackoverflow.com/questions/9108925/how-is-almost-everything-in-javascript-an-object
* Too many built-in JavaScript objects to name: string, Date, Math
* Special object in JavaScript: the associative array a.k.a., dictionary a.k.a., hash a.k.a., finite map
* Okay, but how do I use JavaScript in an HTML page?  Or how do I dynamically modify a loaded HTML page using JavaScript?

#February 24, 2015: The Document Object Model
* Last class: JavaScript data and data structures (lists and dictionaries)
* Recall: almost everything in JavaScript is a/an ______
* Recall: how to use a dictionary
* Important points about client-side JavaScript that I omitted:
  - Client-side tasks (or what you can do with client-side JavaScript)
    - Dynamically modify browser content, e.g., with animation
    - Dynamically fetch new documents from servers
    - Allow new methods of user interaction other than links and buttons
    - Get information about a user's computer (navigator.userAgent)
  - Limitations of client-side scripts
    - Scalable: run on the browser itself
    - Not entirely portable: some methods and scripts only work on certain browser
    - Subject to many security limits
* The big idea today: using JavaScript to dynamically modify HTML content after it is loaded.  Yes, you can mix HTML and JavaScript
* The document object: a JavaScript object that contains the entire structure of an HTML page after it is loaded, in tree-like format (thus, known as the Document Object Model tree).  Example of a DOM tree: https://developer.mozilla.org/en-US/docs/Using_the_W3C_DOM_Level_1_Core
* Example 1: Tufts FML
* Example 2: Highlighting paragraphs in an HTML document
* Even more powerful idea: update the HTML with data from a web server

#February 26, 2015: First-Class Functions
* Last class: the Document Object Model (DOM).  What does the DOM structure look like?
* Recall Tufts FML
* Lab 5 requires the use of the DOM.  It also requires knowledge of another incredibly powerful concept. Mitchell's question on Piazza.
* Recall: almost everything in JavaScript is an object.  That also include functions.
* What if I told you functions can be used as values to variables? Functions as arguments to functions? That's what it means by functions as first-class!
* Recall Algebra: function composition
* Why is this a powerful idea?
  - Reduce repetitive code
  - More reusable and scalable code
  - "Object Oriented Programming" in JavaScript
* Example: animation using HTML5 canvas; karaoke

#March 3, 2015: JSON and XMLHttpRequest
* I forced a lot of people to make mistakes on Quiz 1 --you might as well learn them now, especially the importance of being precise
* Last class: first-class functions
* Today: more powerful ideas that use everything we have discussed so far: JS data and data structures, objects, DOM, first-class functions
* So far, you have only worked with synchronous communications. Problem: slow, linear, "locking", not smooth
* Asynchronous communications.  Where it is used: events
* Client-side JS is heavily event-based
* Recall Tom Addison's karaoke from last semester.
* Examples of async APIs in JavaScript: `navigator.geolocation.getCurrentPosition()`, `XMLHttpRequest`
* The idea of XMLHttpRequest => make a request to a server-side script to get data, manage the response
* XHR key methods and attributes: open(), send(), onreadystatechange, status, readyState, responseText
* The data that now typically get back in the `responseText`: JSON
* gh-pages branch in GitHub; examples

#March 5, 2015: Loose Ends
* Last class: Events and asynchronous
  - Asynchronous: "where data can be transmitted intermittently rather than in a steady stream"; not going at the same rate
  - Are they the same? No. Are they related? Yes --almost all event handling functions are asynchronous.
* Last class: JSON (http://json.org/)
* Today: finish up on XMLHttpRequest
  - Asynchronous
  - The event: onreadystatechange.  The readyState values:
    - 0 => The request is not initialized
    - 1 => The request has been set up
    - 2 => The request has been sent
    - 3 => The request is in process
    - 4 => The request is complete
* Parsing the JSON data
* Is checking for readyState 4 good enough?  NO!
* Caveats with XMLHttpRequest and one of the limitations of client-side JavaScript

#March 26, 2015: Server-Side
* What are the limitations of client-side?
  1. Can't connect to a database server directly --and hence, store lots and lots of data
  2. Other people cannot access data or information that you have (i.e., you can't make responses)
  3. Can't to write to files on disk
  4. You are constrained by web browser (i.e., browser incompatibility issues)
  5. Storage constraints (e.g., cookies, local storage)
  6. Security issues (e.g., same origin policy)
  7. View source
* How do you design the server-side environment, assuming that the hardware (computer(s) for server) is provided to you?
  1. Handle requests
  2. Store data "somewhere"
  3. Send response
  4. It is somehow secure (not trivial)
  5. Some logic to do something with request before sending response
  6. Has to be on / running (almost) all the time
  7. Handle concurrent connection, concurrent transactions
  8. IP address and port number must be provided to the public.
  
#April 2, 2015: Server-Side (continued), Frameworks
* Option A: https://github.com/tuftsdev/WebProgramming/blob/gh-pages/examples/nodejs/server.js
* Option B: https://github.com/tuftsdev/WebProgramming/blob/gh-pages/examples/nodejs/simpleexpress/app.js
* A good framework:
  1. Don't reinvent the wheel
  2. Most of the important ideas are already built for you
  3. Shorten code
  4. Add-on modules that you need.  For all web applications developed using Express.js, a file `package.json` is required.  The file is a list of requirements / dependencies for the web application.  Think of this as the ingredients for a recipe.  Then install all the requirements / dependencies via `npm install`
* General form of a method in Express.js:

#April 7, 2015: Data Persistence with MongoDB, Connecting Node.js with MongoDB
* A simple and complex picture of client-server architecture: https://www.acunetix.com/websitesecurity/web-applications/
* So far, we have talked about the middle tier using Node.js and Express.js (framework on top of Node.js)
* Let's talk about storing data now, the database server layer
* Yes, we are dealing with another server (for solely storing data)
* Why aren't we using a relational database or SQL in this class? Complexity.  The big idea that you know already: key-value pairs
* MongoDB: we can store lots and lots of key-value pairs a la JSON
* Database: a bin of data
* Collection: lots and lots of data records
* Document: a single record of key-value pairs in JSON format
* All documents contain a field `_id`, generated for you
* Important: a document does not need to follow a certain structure
* Operations: inserting a document, querying a collection, updating a document
* Important: inserting a document into a database that does not exist WILL create the database!
* Wait, I'm confused: we are dealing with two different systems here. How do you have a Node.js server talk to a MongoDB server? The answer: a driver. A driver is a piece of software for accessing a database.  Think of this as a translation engine.  There is a `mongodb` driver for Node.js
* Example: https://github.com/tuftsdev/WebProgramming/tree/gh-pages/examples/nodejs/nodemongoapp.  Feel free to copy and use initialization code.  It will help you big time!

#April 9, 2015: Connecting Node.js with MongoDB
* Last class: MongoDB, the database server
* Recall: architecture https://www.acunetix.com/websitesecurity/web-applications/
* Recall: how to query a collection in MongoDB
* Today: make web application written with Node.js + Express talk to a MongoDB
* Recall: driver
* Example: https://github.com/tuftsdev/WebProgramming/tree/gh-pages/examples/nodejs/nodemongoapp.  Feel free to copy and use initialization code.  It will help you big time!
* MongoDB syntax: easy. Executing MongoDB statements in Node.js using the `mongodb` driver: ugly. Event-driven.

#April 14, 2015: Uh oh...
* Data sent to a web server is always text! (thanks to Maggie).  Use parseFloat() to convert a string to a floating point number.
* Revisiting `nodemongoapp`
* There's something wrong with it. What if...
* Cross-Site Scripting (XSS): what is it, why is it so bad, and where to attack?
* Security 101: never trust user input from a client
* Awareness:
  1. OWASP Top 10 list: https://www.owasp.org/index.php/Top_10_2013-Top_10
  2. CWE/SANS TOP 25 Most Dangerous Software Errors: https://www.sans.org/top25-software-errors/
* Playground: http://www.cs.tufts.edu/comp/20/hackme.php
* Bypassing client-side validation using a proxy
* Defending against XSS
* The moral of the story...