===========
Java Script
===========

Javascript is a dialect of ECMAScript and is dynamic, weakly typed,
object-oriented, prototype based language with first class functions. Prototype
based programming is a style of programming in which classes are absent, and
behaviour reuse is performed via a process of cloning existing objects that
serve as prototypes.

The primary use of Javascript is to write functions that are embedded in or
included from HTML pages and interact with the Document Object Model (DOM) of
the page, like opening or popping up a new window with programmatic syntax.
In simple terms, DOM is the way Javascript sees the containing HTML page and
the browser state.  DOM is a platform and a language neutral interface that
allows programs and scripts to dynamically access and update the content,
structure and the style of the document. This Model describes each webpage
element, which of its properties can be changed and how to do it. DOM provides
an object oriented programming interface between HTML/CSS and JavaScript.
DOM is api for HTML and XML. It provides a structural representation of the
Document, enabling you to modify the content and visual presentation. It is a
connection between web pages to scripts.

History
-------
Originally developed by Brenden Eich of Netscape.  The key design principles of
Javascript are inherited from Self and Scheme programming languages. Initially
many programmers denigrated the language because its target audience was 'web
authors'. 

The Javascript engine (the interpretor) was codenamed Spidermonkey this was
written in C by Brenden Eich. Rhino, another Javascript engine was written in
Java by Norris Boyd.  Webbrowser by far is the most common host environment for
Java Script. Web browsers typically use the public API to "create host objects"
responsible for reflecting the DOM into Javascript.

The advent of AJAX returned Javascript to attention and brought more
professional programming attention. The result was proliferation of frameworks
and libraries and server side javascript too.

Syntax and Structure
--------------------

The current javascript version is 1.9. Javascript can be considered a
functional programming language, similar to scheme or OCAML because it has
closures and supports higher order functions.

Javascript supports all the structed programming syntax in C (if statements,
while loops, switch statements etc). The mechanism of closures in Javascript is
by Inner Functions. Javascript uses prototypes instead of classes for defining
object properties.  Functions are same as methods Javascript has types and
operators, core objects and methods. It is like C and Java, but with the key
difference that it does not have classes.  The class functionality is
accomplished by Object prototypes. Functions are objects too.  You can toss
around function as an argument to another function.

Unlike most programming languages, javascript has no concept of input or
output. It is designed to run as a scripting language in a host environment, it
is upto the host environment to provide mechanisms to communicate with the
external world. Javascript typically relies on the run-time environment (e.g.
in a web browser) to provide objects and methods by which. For e.g.  Javascript
needs to be run inside of the {{{<script> }}} HTML tag. The most common host
environment is the browser, but the Javascript interpretor can also be found in
Adobe Acrobat, Photoshop, Yahoo! Widget Engine.

Browsers that do not support javascript will display the javascript as page
contents. To prevent them from doing this and as part of the javascript
standard, the HTML comment tag should be used to hide the javascript.
 
:: 

        <html>
        <body>
        <script type="text/javascript">
        <!--
        document.write("Hello World!");
        //-->
        </script>
        </body>
        </html>

**//** is the javascript comment tag. it prevents javascript from executing the
tag. Javascripts in the body section will be executed while the page loads.
Javascripts in the head section will be executed when the page is called. It is
normal to add semi-colon ';' to end of the javascript statement, but it is
completely optional.

An indefinite number of parameters can be passed to a function, it can either
access them through formal parameters or as the local argument.

Like many scripting languages, arrays and objects can each be created with an
succient shortcut syntax. Javascript dispatches the requests for information to
the server.

For security related aspects: Scripts are run in a sandbox. Scripts are
restricted to a same origin policy. Action Script  programming language in
Adobe flash is another implementation of ECMAScript. Java programming language,
version 6, introduced javax.script package, including a Java Script
implementation based on Mozilla Rhino.

Web applications within firefox can be debugged using the firebug on.

JSON, or Java Script Object Notation is a general purpose data interchange
format, that is defined as a subset of Java Script.

types
-----

types in javascript are 

* Numbers
* Strings
* Boolean
* Objects
   * Functions
   * Arrays
   * Dates
   * Regular Expression.
* Undefined
* Null

New variables in JavaScript are declared using the var keyword.Variable names
in JavaScript is case sensitive.  And it's scope remains local to that block.
If declared without var keyword, they are considered global.

There is no such thing as integers in Javascript. The standard numeric
operators are supported, addition, subtraction and modulus (modulus on float ?)
math object is available by default for advanced operations. Numbers are double
precision 64-bit format IEEE 754 values.

Strings in Javascripts are sequence of characters, more importantly they are
sequence of unicode characters.

If you add string to a number (or other value), everything is converted in to a
string first.

:: 

  > "3" + 4 + 5
   345
  > 3 + 4 + "5"
   75

Adding an empty string to something is a useful way of converting it.

Javascript distinguishes between **null** object, which is an object of type
'object' that indicates a delibrate *non-value* and **undefined** which is an
object of type undefined that indicates an unintialized value.

Arrays
------

array.length is one more than the highest index of the array. This is kind of a
quirk that you will need  getting used to.

splice method on a array lets you modify an array by deleting a section and
replacing it with more items.

unshift prepends items to the start of the array.

Arrays come with a number of methods, like  a.toString(), a.toLocaleString(),
a.concat(item,...), a.join(sep), a.pop(), a.push(item, ...), a.reverse(),
a.shift(), a.slice(start, end), a.sort(cmpfn), a.splice(start, delcount,
[item]...), a.unshift([item]..)

Leaving a trailing comma at the end of the array literal is incosistent across
browsers, so don't do it.  

Object Syntax
-------------

Javascript Objects are simply collections of name-value pairs.  The name part
is a string and value is a primitive (or trivial primitive) or another
Javascript object.The keys of the object are also called object's properties.

* Dictionaries in Python
* Hashes in Perl and Python
* Hash Tables in C and C++
* HashMaps in Java
* Associative arrays in PHP


There are 3 primitives:  number, string, and boolean. Trivial primitives are
null and undefined And don't confuse number with Number and string with String


var obj = {}; this method of creating objects is called object literal syntax.
It was not present in the initial version of javascript. obj.name = "Simon" and
obj["name"] = "Simon" are the two ways to access the object. The second method
has an advantage that the name of the property which is provided as string can
be calculated at run-time. obj.for will result in an error because for is a
reserved keyword; while obj["for"] will work fine.

Every object in Javascript is an instance of the object Object and therefore
inherits it's properties and methods.

Object literal syntax can be used to initialize the object in entirety.

:: 

        var obj = {
            name: "Carrot",
            "for": "Max",
            details: {
                color: "orange",
                size: 12
            }
        }

Attribute access can be chained together.

:: 

        > obj.details.color
        orange
        > obj["details"]["size"]
        12

Functions
---------

Along with objects, functions are the core components in understanding
JavaScript. Functions have access to additional variable inside their body
called arguments, which is an array like object holding all the values passed
to the function.

The nameless functions are useful and clever because it allows you to put a
function in the place where an expression would be desirable. The "named
anonymous function" concept is what I see all the while in the Javascript.::

        function makePerson(first, last) {
                return {
                        first: first,
                        last: last,
                        fullName: function() {
                                return this.first + this.last;
                                },
                        fullNameReversed: function() {
                                return this.last + this.first;
                                }
                       }
        }

functions attached to parent function is part of the lookup chain. The special
name for it is "prototype chain". Javascript allows you to call functions
recursively. It is useful for dealing with tree structures, such as you get in
browser DOM. For nameless functions, recursive call can be done using
arguments.callee method which points to the current function. 

Since arguments.callee is the current function and all functions are objects,
you can use arguments.callee to save information across multiple calls to the
same function.
 
        ::
                function Person(first, last) {
                    this.first = first;
                    this.last = last;
                }
                Person.prototype.fullName = function() {
                    return this.first + ' ' + this.last;
                }
                Person.prototype.fullNameReversed = function() {
                    return this.last + ', ' + this.first;
                }

Person.prototype is an object shared by all instances of Person. It forms part
of a lookup chain (that has a special name, "prototype chain"): any time you
attempt to access the property of Person that isn't set, JavaScript will check
Person.prototype to see if that property exists there instead.

This is an incredibly powerful tool. JavaScript lets you modify something's
prototype at any time in your program, which means you can add extra methods to
existing objects at runtime.

:: 


        > s = new Person("Simon", "Willison");
        > s.firstNameCaps();
        TypeError on line 1: s.firstNameCaps is not a function
        > Person.prototype.firstNameCaps = function() {
            return this.first.toUpperCase()
        }
        > s.firstNameCaps()
        SIMON

Can add prototypes for the built-in JavaScript objects. Lets add a method to
the string which returns the string in reverse.

:: 

        > var s = "Simon";
        > s.reversed()
        TypeError on line 1: s.reversed is not a function
        > String.prototype.reversed = function() {
            var r = "";
            for (var i = this.length - 1; i >= 0; i--) {
                r += this[i];
            }
            return r;
        }
        > s.reversed()
        nomiS

And this works on string literals too. Wow.

Statements
----------

A compilation unit contains a set of executable statements. In web browsers,
each <script> tag delivers a compilation unit that is compiled and immediately
executed. Lacking a linker, javascript throws them all together in a common
global namespace.


jQuery
======

Jquery is a cross browser javascript library that provides abstractions for DOM
traversals, event handling, animation and Ajax interactions for rapid web
development. Provides abstractions for common client side tasks such as DOM
traversal, event handling, animation and Ajax. It also provides platform for
creation of plugins that extend JQuery capabilities beyond those provided by
the core.

The jQuery library is a single JavaScript file, containing all of its common
DOM, event, effects, and Ajax functions. It can be included within a web page
by linking to a local copy, or to one of the many copies available from public
CDNs.::

        <script type="text/javascript" src="jquery.js"></script>

The most popular and basic way to introduce a jQuery function is to use the
.ready() function.::

        $(document).ready(function() {
        // jquery goes here
        });

        or the shortcut

        $(function() {
        // jquery goes here
        });

While one of the goals of jQuery is to abstract away the DOM, knowing DOM
properties can be extremely useful. One can utlize the awesome power of JQuery
to access the properties of an element.

Here is an example Simple `Jquery example`_ for selecting a Radio.

jQuery's syntax is designed to make it easier to navigate a document, select
DOM elements, create animations, handle events, and develop Ajax applications.

jQuery also provides capabilities for developers to create plug-ins on top of
the JavaScript library. This enables developers to create abstractions for
low-level interaction and animation, advanced effects and high-level,
theme-able widgets. The modular approach to the jQuery framework allows the
creation of powerful and dynamic web pages and web applications.

jQuery contains the following features.

* DOM element selections using the cross-browser open source selector engine
  Sizzle, a spin-off out of the jQuery project.
* DOM traversal and modification (including support for CSS 1-3)
* Events
* CSS manipulation
* Effects and animations
* Ajax
* Extensibility through plug-ins
* Utilities - such as browser version and the each function.
* Cross-browser support

jQuery has two usage styles:

* via the $ function, which is a factory method for the jQuery object. These
  functions, often called commands, are chainable; they all return jQuery
  objects

* via $.-prefixed functions. These are utility functions which do not work on
  the jQuery object per se.

Typically, access to and manipulation of multiple DOM nodes begins with the $
function being called with a CSS selector string, which results in a jQuery
object referencing matching elements in the HTML page. This node set can be
manipulated by calling instance methods on the jQuery object, or on the nodes
themselves. For example.::

        $("div.test").add("p.quote").addClass("blue").slideDown("slow");

The methods prefixed with $.  are convenience methods or affect global
properties and behaviour. For example, the following is an example of the map
function called each in jQuery.::

        $.each([1,2,3], function(){
          document.write(this + 1);
        });

This writes the number 234 to the document.

Example of doing a simple Ajax request using jQuery.::

        $.ajax({
          type: "POST",
          url: "example.php",
          data: "name=John&location=Boston",
          success: function(msg){
            alert( "Data Saved: " + msg );
          }
        });

There are lot of jquery plugins available - Ajax helpers, webservices,
datagrids, dynamic lists, XML and XSLT tools, drag and drop, events, cookie
handling, modal windows, even a jQuery-based Commodore 64 emulator

SlickGrid
=========

https://github.com/mleibman/SlickGrid/wiki

DOM Nodes are continously being created and removed. It does a few other things
to maximize performance, such as dynamically generating and updating CSS rules,
so that resize.

SlickGrid in the simplest scenario, it accesses data through an array
interface. Using the dataitem to get an item at a given position and
"data.length" to determine the number of items, but the API is structured in
such a way that it is very easy to make the grid react to any possible changes
to the underlying data.

Node
====


Tidbits
-------

*  == performs type coercion, while ===  does not perform type coercion.
* Javascript also has bitwise operations, if you want to use them, they are there.
* You can have expressions in both the switch and the case parts.
* If you are unsure about Boolean use explicit Boolean function.
* alert function is not part of Javascript itself.
* Debug javascript using firebug. The console.debug and console.dir would help
  you do introspection.

Questions
=========

var name = o && o.getName()  What will this be set to?
------------------------------------------------------

How is the below expression evaluated?
--------------------------------------

``$('.task-edit .parent-entity-fields input').removeAttr('disabled');`` What is happening here with .task-edit, .parent-entity-fields??

These are all classes which are searched from left to right.

How do you implement namespaces in Javascript?
----------------------------------------------

What is this.something in javascript?
-------------------------------------


Code
----

channel object as appendMessage and query.
var callbacks = [];
callbacks.shift().callback([]); // This is a way of clearing callback.
sessions is a dictionary.
remove the memory rss limits
don't care about sessions at the moment.
Have everything in the single file.
What is the idea behind a channel and a session?
createSession object is used when it is called for /join.
There is a /send for sending the message.
The GET's query string text is the message that you type.

All are the requests which are happening but not via browser, but via simpleJSON calls.

// I would not have written this all by myself. 

var starttime = (new Date()).getTime();

--

Senthil: I would not have written the above, if I was left by myself. # var starttime = (new Date()).getTime();
Senthil: how should remember that I have to do ( new Date()) 
inimino: js> new Date().getTime()
ecmabot: inimino: (number) 1314432211820
inimino: js> +new Date
ecmabot: inimino: (number) 1314432231484
inimino: js> Date.now()
ecmabot: inimino: (number) 1314432237250
Senthil: js> (new Date()).getTime()
ecmabot: phoe6: (number) 1314432239166
Senthil: js> new Date
ecmabot: phoe6: (object) Sat Aug 27 2011 04:04:22 GMT-0400 (EDT)
hughfdjackson: js> var a = new Date; a;
ecmabot: hughfdjackson: (object) Sat Aug 27 2011 04:04:54 GMT-0400 (EDT)
Senthil: thanks everyone.  I was confused when I saw this var starttime = (new Date()).getTime(); - I would rather use something which I understand.
Senthil: guys what is +new?
Senthil: js>+new Date;
ecmabot: phoe6: (number) 1314432448111
Senthil: js> new Date;
ecmabot: phoe6: (object) Sat Aug 27 2011 04:07:37 GMT-0400 (EDT)
Senthil: How does +new working above?
hughfdjackson: phoe6: are you familiar with type coercion?
Senthil: yup.
Senthil: what is it coercing against.
hughfdjackson: + is just coercing the Date object you create to a number
hughfdjackson: that's all
Senthil: I thought new was keyword 
hughfdjackson: new Date() resolves
hughfdjackson: which leaves a date object behind
hughfdjackson: then + is applied to the date object
hughfdjackson: coercing it
hughfdjackson: that's my understanding
Senthil: oh + is associated with the object returned via new Date; and not on new keyword.
Senthil: interesting.
hughfdjackson: js> (+new) Date()
ecmabot: hughfdjackson: SyntaxError: syntax error
hughfdjackson: js> + (new Date())
ecmabot: hughfdjackson: (number) 1314432577653
hughfdjackson: see? :D
Senthil: gotcha. :)
Senthil: thanks.
hughfdjackson: welcome
Senthil: js> I love you.
ecmabot: phoe6: SyntaxError: missing ; before statement
Senthil: js> I love you;
hughfdjackson: js> ;i love you
ecmabot: phoe6: SyntaxError: missing ; before statement
ecmabot: hughfdjackson: SyntaxError: missing ; before statement
hughfdjackson: aaaaargh
hughfdjackson: js, you fickle maiden!


phoe6, there are loads of different coding styles you can take a look before
deciding your own. NPM's (
https://github.com/isaacs/npm/blob/master/man1/coding-style.1 ), Cockford's (
http://javascript.crockford.com/code.html ), Google's (
http://google-styleguide.googlecode.com/svn/trunk/javascriptguide.xml ), mine's
( http://killdream.github.com/Black/docs/deploy/dev/style-guide.html )


(12:39:28) eboyjr: !objects
(12:39:28) ecmabot: eboyjr: A JavaScript object is a set of properties.  A property name is a string, a property value is any JS value.  See: Working with Objects https://developer.mozilla.org/en/JavaScript/Guide/Working_with_Objects
(12:39:48) dfenwick: Again, think in terms of a dict
(12:40:22) Senthil: ok.
(12:40:52) dfenwick: And now a note on prototype, since I'm on that section
(12:41:09) dfenwick: prototype is a powerful feature, but it can also be dangerous if you don't know how prototypes work
(12:43:28) dfenwick: phoe6: Here's a simple example that can trip inexperienced folks up.  Using for/in, all properties, including all prototypes associated with an object will be returned
(12:44:32) Senthil: just a moment..
(12:55:50) dfenwick: phoe6: I have a simple example that might be of interest to you
(12:56:19) dfenwick: phoe6: It might help with understanding what happens with prototype:  http://jsfiddle.net/nbHYx/
(12:59:11) very_odd: dfenwick, don't put <html> into the html field on jsfiddle. it's meant for the content of <body>. :)
(12:59:26) dfenwick: Bah, nitpick
(12:59:33) dfenwick: I copied it from my browser :)
(13:00:16) very_odd: ew, just look the generated page source `<body><html><head><script type="application/javascript">...`
(13:00:31) dfenwick: It's beautiful!
(13:00:38) dfenwick: The fact that it renders is even cooler
(13:03:24) very_odd: dfenwick, but document.body.getElementsByTagName("html")[0] is undefined. so i think everythings okay.



(15:51:27) Senthil: eboyjr: sure. If both client.js is getting the jQuery object from its global object (window), how is it able to access jQuery object as a standalone object, instead of window.jQuery.  
(15:51:29) shachaf: brianloveswords: I thought there was already a PNG metadata parser in JS, though?
(15:52:04) Senthil: that's not perfect grammar either. but did I make sense?
(15:52:08) brianloveswords: shachaf: There might be! I couldn't find one that was pure JS (that doesn't depend on libpng)
(15:52:09) eboyjr: phoe6: Because any properties of the global object in automatically in scope. Here's an example...
(15:52:22) shachaf: brianloveswords: Oh, this is a server-side thing?
(15:52:27) brianloveswords: shachaf: Yeah.
(15:52:33) eboyjr: >> var window = this; var jQuery = "example"; [window.jQuery, jQuery] @ phoe6
(15:52:33) ecmabot: phoe6: (object) ['example', 'example']

Links to go through

http://www.adequatelygood.com/2010/2/JavaScript-Scoping-and-Hoisting

https://gist.github.com/1164169

References
==========

* `A Re-Introduction to Javascript`_
* `Introduction to Object Oriented Javascript`_
* `Javascript Guide`_
* Immediately Invoked Function Expression - `IFFE`_
* `Vim Configuration for Javascript`_

.. _A Re-Introduction to Javascript: https://developer.mozilla.org/en/A_re-introduction_to_JavaScript
.. _Introduction to Object Oriented Javascript: https://developer.mozilla.org/en/Introduction_to_Object-Oriented_JavaScript
.. _Javascript Guide: https://developer.mozilla.org/en/JavaScript/Guide
.. _Jquery example: http://jsfiddle.net/ndJFD/13/
.. _IIFE: http://benalman.com/news/2010/11/immediately-invoked-function-expression/
.. _Vim Configuration for Javascript: http://www.brankovukelic.com/post/2091037293/turn-vim-into-powerful-javascript-editor
