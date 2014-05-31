===========
Java Script
===========

Javascript is a dialect of ECMAScript and is dynamic, weakly typed,
object-oriented, prototype based language with first class functions. Prototype
based programming is a style of programming in which classes are absent, and
behaviour reuse is performed via a process of cloning existing objects that
serve as prototypes.

DOM is a platform and a language neutral interface that allows programs and
scripts to dynamically access and update the content, structure and the style
of the document. This Model describes each webpage element, which of its
properties can be changed and how to do it. DOM provides an object oriented
programming interface between HTML/CSS and JavaScript.  DOM is api for HTML and
XML. It provides a structural representation of the Document, enabling you to
modify the content and visual presentation. It is a connection between web
pages to scripts. The primary use of Javascript is to write functions that are
embedded in or included from HTML pages and interact with the Document Object
Model (DOM) of the page, like opening or popping up a new window with
programmatic syntax.

In simple terms, DOM is the way Javascript sees the containing HTML page and
the browser state.

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
closures and supports higher order functions. However it is important to
remember that mere presence of closures does not make a language functional.
Closures are however most common away of encapsulation in javascript.

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

The functions and methods defined in one js file is available in other js
files too. For e.g. you include jQuery.js file in the body of a html file and
other javascript files can access teh $.ready() which Jquery provides.

::

    Senthil: eboyjr: sure. If both client.js is getting the jQuery object from
    its global object (window), how is it able to access jQuery object as a
    standalone object, instead of window.jQuery.
    eboyjr: phoe6: Because any properties of the global object in automatically
    in scope. Here's an example...
    eboyjr: >> var window = this; var jQuery = "example"; [window.jQuery, jQuery] @ phoe6
    ecmabot: phoe6: (object) ['example', 'example']

types
-----

types in javascript are

::

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

New variables in JavaScript are declared using the var keyword. Variable names
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
object of type **undefined** that indicates an unintialized value.

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

A JavaScript object is a set of properties. A property name is a string, a
property value is any JS value.

Javascript Objects are simply collections of name-value pairs.  The name part
is a string and value is a primitive (or trivial primitive) or another
Javascript object.The keys of the object are also called object's properties.

::

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

See: `Working with Objects`_

.. _Working with Objects: https://developer.mozilla.org/en/JavaScript/Guide/Working_with_Objects

Functions
---------

Along with objects, functions are the core components in understanding
JavaScript. Functions have access to additional variable inside their body
called arguments, which is an array like object holding all the values passed
to the function.

The nameless functions are useful and clever because it allows you to put a
function in the place where an expression would be desirable. The "named
anonymous function" concept is what I see all the while in the Javascript.

::

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

::

    dfenwick: prototype is a powerful feature, but it can also be dangerous if you don't know how prototypes work
    dfenwick: Here's a simple example that can trip inexperienced folks up.  Using
    for/in, all properties, including all prototypes associated with an object will
    be returned
    dfenwick: phoe6: I have a simple example that might be of interest to you
    dfenwick: phoe6: It might help with understanding what happens with prototype:  http://jsfiddle.net/nbHYx/ 


Here is a detailed discussion on closures_ in Javascript.

Scoping and Hoisting
--------------------

Hoisting is uncommon in other programming languages but very common in
Javascript. It is one of the reasons Js is denigraded sometimes.

* http://www.adequatelygood.com/2010/2/JavaScript-Scoping-and-Hoisting

* https://gist.github.com/1164169

Statements
----------

A compilation unit contains a set of executable statements. In web browsers,
each <script> tag delivers a compilation unit that is compiled and immediately
executed. Lacking a linker, javascript throws them all together in a common
global namespace.

Dom Events
----------

DOM (Document Object Model) events allow event-driven programming languages
like JavaScript to register various event handlers/listeners on the element
nodes inside a DOM tree, e.g. HTML, XHTML, XUL and SVG documents.

Historically, like DOM, the event models used by various web browsers had some
significant differences. This caused compatibility problems. To combat this,
the event model was standardized by the W3C in DOM Level 2.


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

Javascript Coding Standards
===========================

* NPM's - https://github.com/isaacs/npm/blob/master/man1/coding-style.1
* Cockford's - http://javascript.crockford.com/code.html
* Google's - http://google-styleguide.googlecode.com/svn/trunk/javascriptguide.xml
* Killdream's - http://killdream.github.com/Black/docs/deploy/dev/style-guide.html

Questions
=========

**var name = o && o.getName()  What will this be set to?**

**How is the below expression evaluated?**

::

    $('.task-edit .parent-entity-fields input').removeAttr('disabled');

    What is happening here with .task-edit, .parent-entity-fields??

These are all classes which are searched from left to right.

**How do you implement namespaces in Javascript?**

**What is this.something in javascript?**

Code
----

* callbacks.shift().callback([]); // This is a way of clearing callback.

This snippet returns the Date object.

* new Date

It should return - (object) Sat Aug 27 2011 04:04:22 GMT-0400 (EDT)

Converting the Date() to int. The following are equivalent.

* var starttime = (new Date()).getTime();
* +new Date (+ is associated with the object returned via new Date; and not on new keyword.)
* Date.now()

It should return 1314432237250

`Defining Classes in JavaScript`_
`JQuery Deconstructed`_

Good article promoting some of the patterns we are using (and should be using
more of) in prodcast.  In brief

- javascript modules exposing clean, minimal interfaces
- pubsub or events to avoid direct dependencies between modules

* http://addyosmani.com/largescalejavascript/


15 days of JQuery
-----------------

* http://15daysofjquery.com/quicker/4/

Sometimes window.onload is not quick enough and you want to javascript
immediate after DOM is ready. That is why jQuery's $(document).ready() comes
into picture.

::

    $(document).ready(

    // Write javascript functions

    )

You can use it to launch any kind of javascript you like. It does not have to
be reserved for jQuery style coding and there is nothing wrong with telling
jQuery to launch several different functions all at once. It is similar to the
init function, but just a damn lot faster.

Zebra stripping made easy

* http://docs.jquery.com/Tutorials:Zebra_Striping_Made_Easy

Excellent Introduction to Jquery
--------------------------------

By doing a Zebra table showdown

* http://blog.jquery.com/2006/10/18/zebra-table-showdown/

Move way from table layouts and do the table in CSS.

Jquery
------

::

    Lochlan: phoe6; have you googled, javascript magnifier, or jquery magnifier
    Senthil: Lochlan: I should do that. thanks.
    eighty4: phoe6: looks like a standard js zoomer
    Lochlan: phoe6: no worries, that's how i get by just type 'jquery + verb'
    Lochlan: usually works :)
    eighty4: phoe6: all it does is basically tracking x,y on the main image and overlaying that with a bigger image
    Senthil: yeah, got it. http://jdbartlett.com/loupe/
    Senthil: it is brilliant.
    Lochlan: phoe6: good stuff
    Lochlan: too easy
    Senthil: I discovered jquery (as a programmer) who weeks ago only and I should say that I am falling in love with it.
    Senthil: the idea of dom manipulation is amazing. just today I looked at the 2006 tutorials (some were broken) and I felt, wow It took is me so long to get into this.
    Lochlan: phoe6: i'm not a programmer, but damn jquery is easy
    Senthil: Lochlan: seriously? i don't get that when you say it. jquery, I think is serious programming stuff.
    Senthil: perhaps you are downplaying yourself. :)
    Lochlan: phoe6: i've just rolled with it, first used plugins.. then starting reading plugins to modify, then started writing it myself, now i just write everything from scratch and barely use other people's code
    Senthil: wonderful, that's good to know.
    Lochlan: phoe6: story of my life
    Senthil: :)
    Lochlan: i just wrote quite large web app using jquery, before that all i had evr done was basic dom manipulation
    Lochlan: it's a start up and they have no $$ so i'm not getting paid anymore :/
    Lochlan: just use google and a bit of logic and you can work it all out
    Lochlan: if you know css you're halfway to jquery anyway

Here's how jQuery attacks the problem.

::

    $(document).ready(function(){
    $("img.dropshadow")
    .wrap("<div class='wrap1'><div class='wrap2'>" +
    "<div class='wrap3'></div></div></div>");
    });

And then the images would be styled like so:

::

    <img src="object.gif" class="dropshadow" alt="The object casting a shadow" />


* $(document).ready() is jQuery's version of window.onload()
* $("img.dropshadow") tells jQuery to find all images with the class name "dropshadow". If you wanted to use an id instead, you could do something like $("img#dropshadow")
* wrap() tells jQuery to use the DOM (Document Object Method Model) to wrap the images with the class="dropshadow" in the html inside the parenthesis.


**Exercise**

Explain the behavior of these jQuery methods append(), prepend(), before(),
after(), html(), and remove().

jQuery Style switcher example
-----------------------------

::

    $(document).ready(function()
    {
            $('.styleswitch').click(function()
            {
                    switchStylestyle(this.getAttribute("rel"));
                    return false;
            });
            var c = readCookie('style');
            if (c) switchStylestyle(c);
    });

    function switchStylestyle(styleName)
    {
            $('link[@rel*=style]').each(function(i)
            {
                    this.disabled = true;
                    if (this.getAttribute('title') == styleName) this.disabled = false;
            });
            createCookie('style', styleName, 365);
    }


For stuff like this - ``$('link[@rel*=style]')``, look at jQuery Selectors

http://api.jquery.com/category/selectors/

Basically, it is telling jQuery to find all link elements with a rel attribute
containing the string ‘style’”.

::

    this.disabled = true;
    if (this.getAttribute('title') == styleName) this.disabled = false;

“Disable every stylesheet link but then un-disable any link where the “title”
attribute is the same as the value passed to the switchStylestyle function”

What we’re doing is matching the rel attribute of the links on our page (the
clickable links for switching the stylesheets) with the title attribute of the
stylesheets (and alternates) available to us.

When one of the clickable links is clicked, a function is called, which finds
all the stylesheets, disables all of them, and then turns one back on… the one
where the title of the stylesheet link matches the rel attribute of the link
clicked.

Whew!

JQuery style switcher example 

* http://www.kelvinluck.com/assets/jquery/styleswitch/toggle.html

How would we take a html and use jQuery to clean up the code?

First we need a “hook” – a unique html element, or an id, or a class name – to
tell jQuery to target.

**Rounded box example**

::

    <div class="dialog">
     <div class="hd">
      <div class="c"></div>
      </div>
     <div class="bd">
      <div class="c">
    <div class="s">
      <-- main content goes here -->
    </div>
      </div>
      </div>
     <div class="ft">
      <div class="c"></div>
      </div>
    </div>

Let's try this

::

    <div class="roundbox">
      <-- main content goes here -->
      </div>

Next step… we use jQuery to add in our html code:

::

    $(document).ready(function(){ $("div.roundbox") .wrap('<div
            class="dialog">'+
            '<div class="bd">'+
            '<div class="c">'+
            '<div class="s">'+
            '</div>'+
            '</div>'+
            '</div>'+
            '</div>');
    });


This is a perfect opportunity to use append and prepend functions of jQuery and chain them together.

::

    $('div.dialog').prepend('<div class="hd">'+
            '<div class="c"></div>'+
            '</div>')
    .append('<div class="ft">'+
            '<div class="c"></div>'+
            '</div>');


Multiple file upload script
---------------------------

::

    <input type="file" class="upload" name="fileX[]" />

The big difference in this second version is that I loop through each file
input field and apply the doIt() function when the field value changes. By
looping through each one, I can send an additional piece of information that’s
critical to my code: the order of the field in the “stack”.

In other words, as the code executes, it’s specifically targeting the first
input field, or the second, or the third.

The code for this is found here:

::

    $("input[@type=file]:nth-of-type("+n+")")

jQuery’s flexibility allows me to use CSS and XPath descriptions to target specific elements.

thickbox

* http://jquery.com/demo/thickbox/

**JQuery Interface Plugins**

* http://interface.eyecon.ro/download

**Puzzle demo**

* http://madrobby.github.com/scriptaculous/puzzle-demo/

Pretty useful for what I think for uthcode.

**CSS**

* http://designinfluences.com/fluid960gs/
* http://960.gs/


jsfiddle
--------

::

    <link href="http://ajax.googleapis.com/ajax/libs/jqueryui/1.8/themes/base/jquery-ui.css" rel="stylesheet" type="text/css"/>
    <script src="http://ajax.googleapis.com/ajax/libs/jquery/1.5/jquery.min.js"></script>
    <script src="http://ajax.googleapis.com/ajax/libs/jqueryui/1.8/jquery-ui.min.js"></script>

    <!- Write all your Jquery below -->

    <script>

    <!- In order for the Jqery to act on all events use this -->
    $(document).ready(function () {
    <!- All your Jquery -->
    });

    </script>

Coffee Script
-------------

Coffee script seems easy to write.

::

    p = $ ->

is the definition of a function

::

    p = $(arg) ->

is a function which takes an arg.


References
----------

* `A Re-Introduction to Javascript`_
* `Introduction to Object Oriented Javascript`_
* `Javascript Guide`_
* Immediately Invoked Function Expression - `IIFE`_
* `Vim Configuration for Javascript`_

.. _A Re-Introduction to Javascript: https://developer.mozilla.org/en/A_re-introduction_to_JavaScript
.. _Introduction to Object Oriented Javascript: https://developer.mozilla.org/en/Introduction_to_Object-Oriented_JavaScript
.. _Javascript Guide: https://developer.mozilla.org/en/JavaScript/Guide
.. _Jquery example: http://jsfiddle.net/ndJFD/13/
.. _IIFE: http://benalman.com/news/2010/11/immediately-invoked-function-expression/
.. _Vim Configuration for Javascript: http://www.brankovukelic.com/post/2091037293/turn-vim-into-powerful-javascript-editor
.. _closures: http://jibbering.com/faq/notes/closures/
.. _Defining Classes in JavaScript: http://www.phpied.com/3-ways-to-define-a-javascript-class/
.. _JQuery Deconstructed: http://www.keyframesandcode.com/code/development/javascript/jquery/jquery-deconstructed/
