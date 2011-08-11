===========
Java Script
===========

* Javascript is a dialect of ECMAScript and is dynamic, weakly typed, prototype
  based language with first class functions.
* Prototype based programming is a style of programming in which classes are
  not present, and behaviour reuse is performed via a process of cloning
  existing objects that serve as prototypes.
* Originally developed by Brenden Eich of Netscape.
* The key design principles of Javascript are inherited from Self and Scheme
  programming languages.
* Initially many programmers denigrated the language because its target
  audience was 'web authors'.
* The advent of AJAX returned Javascript to attention and brought more
  professional programming attention.
* The result was proliferation of frameworks and libraries and server side
  javascript too.
* Javascript supports all the structed programming syntax in C (if statements,
  while loops, switch statements etc)
* The mechanism of closures in Javascript is by Inner Functions.
* Javascript uses prototypes instead of classes for defining object properties.
  Functions are same as methods
* Run time environment. Javascript typically relies on the run-time environment
  (e.g. in a web browser) to provide objects and methods by which. For e.g.
  Javascript needs to be run inside of the {{{<script> }}} HTML tag.
* An indefinite number of parameters can be passed to a function, it can either
  access them through formal parameters or as the local argument.
* Like many scripting languages, arrays and objects can each be created with an
  succient shortcut syntax.
* The primary use of Javascript is to write functions that are embedded in or
  included from HTML pages and interact with the Document Object Model (DOM) of
  the page. 
* Opening or popping up a new window with programmatic.
* Javascript dispatches the requests for information to the server.
* The Javascript engine (the interpretor) was codenamed Spidermonkey this was
  written in C by Brenden Eich.
* Rhino, another Javascript engine was written in Java by Norris Boyd.
* Webbrowser by far is the most common host environment for Java Script. Web
  browsers typically use the public API to "create host objects" responsible
  for reflecting the DOM into Javascript.
* In simple terms, DOM is the way Javascript sees the containing HTML page and
  the browser state.
* Security related aspects: Scripts are run in a sandbox.
* Scripts are restricted to a same origin policy.
* Action Script  programming language in Adobe flash is another implementation
  of ECMAScript.
* Java programming language, version 6, introduced javax.script package,
  including a Java Script implementation based on Mozilla Rhino.
* Web applications within firefox can be debugged using the firebug on.
* JSON, or Java Script Object Notation is a general purpose data interchange
  format, that is defined as a subset of Java Script.
* Javascript can be considered a functional programming language, similar to
  scheme or OCAML because it has closures and supports higher order functions.
* The current javascript version is 1.9

Online Material
===============

https://developer.mozilla.org/en/A_re-introduction_to_JavaScript

* Unlike most programming languages, javascript has no concept of input or
  output. It is designed to run as a scripting language in a host environment,
  it is upto the host environment to provide mechanisms to communicate with the
  external world.
* The most common host environment is the browser, but the Javascript
  interpretor can also be found in Adobe Acrobat, Photoshop, Yahoo! Widget
  Engine.

types
=====

Javascript is an object oriented language. It has types and operators, core
objects and methods. It is C and Java, but with the key difference that it does
not have classes.  The class functionality is accomplished by Object
prototypes. Functions are objects too. You can toss around function as an
argument to another function.

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

* There is no such thing as integers in Javascript.
* The standard numeric operators are supported, addition, subtraction and
  modulus (modulus on float ?)
* math object is available for advanced operations.
* Strings in Javascripts are sequence of characters, more importantly they are
  sequence of unicode characters.
* Javascript distinguishes between null object, which is an object of type
  'object' that indicates a delibrate non-value and undefined which is an
  object of type undefined that indicates an unintialized value.
* New variables in JavaScript are declared using the var keyword.
* If you add string to a number (or other value), everything is converted in
  to a string first.

Numbers are double precision 64-bit format IEEE 754 values.


:: 
  > "3" + 4 + 5
   345
  > 3 + 4 + "5"
   75

* Adding an empty string to something is a useful way of converting it.
*  == performs type coercion, while ===  does not perform type coercion.
* Javascript also has bitwise operations, if you want to use them, they are there.
* var name = o && o.getName()  What will this be set to?
* You can have expressions in both the switch and the case parts.
* var obj = {}; this method of creating objects is called object literal
  syntax. It was not present in the initial version of javascript.
* obj.name = "Simon" and obj["name"] = "Simon" are the two ways to access the
  object. The second method has an advantage that the name of the property
  which is provided as string can be calculated at run-time.
* obj.for will result in an error because for is a reserved keyword; while
  obj["for"] will work fine.
* Object literal syntax can be used to initialize the object in entirety.

:: 

        var obj = {
            name: "Carrot",
            "for": "Max",
            details: {
                color: "orange",
                size: 12
            }
        }


* Attribute access can be chained together.


:: 

        > obj.details.color
        orange
        > obj["details"]["size"]
        12


* Leaving a trailing comma at the end of the array literal is incosistent
  across browsers, so don't do it.
* array.length is one more than the highest index of the array.
* splice method on a array lets you modify an array by deleting a section and
  replacing it with more items.
* unshift prepends items to the start of the array.
* Javascript allows you to call functions recursively. It is useful for
  dealing with tree structures, such as you get in browser DOM.
* For nameless functions, recursive call can be done using arguments.callee
  method which points to the current function. 
* Since arguments.callee is the current function and all functions are
  objects, you can use arguments.callee to save information across multiple
  calls to the same function.
 
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

* Person.prototype is an object shared by all instances of Person. It forms
  part of a lookup chain (that has a special name, "prototype chain"): any
  time you attempt to access the property of Person that isn't set, JavaScript
  will check Person.prototype to see if that property exists there instead.

* This is an incredibly powerful tool. JavaScript lets you modify something's
  prototype at any time in your program, which means you can add extra methods
  to existing objects at runtime.

:: 


        > s = new Person("Simon", "Willison");
        > s.firstNameCaps();
        TypeError on line 1: s.firstNameCaps is not a function
        > Person.prototype.firstNameCaps = function() {
            return this.first.toUpperCase()
        }
        > s.firstNameCaps()
        SIMON

* Can add prototypes for the built-in JavaScript objects. Lets add a method to
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

* And this works on string literals too. Wow.

Java Script Tutorial
====================

* Javascript can put dynamic text into HTML pages.
* How to handle simple browsers? Browsers that do not support javascript will
  display the javascript as page contents. To prevent them from doing this and
  as part of the javascript standard, the HTML comment tag should be used to
  hide the javascript.
 
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

* // is the javascript comment tag. it prevents javascript from executing the
  --> tag.
* Javascripts in the body section will be executed while the page loads.
* Javascripts in the head section will be executed when the page is called.
* It is normal to add semi-colon ';' to end of the javascript statement, but
  it is completely optional.
* Variable names in JavaScript is case sensitive.
* In Javascript you dont need to import Math objects, it is always available
  to you.
* DOM is a platform and a language neutral interface that allows programs and
  scripts to dynamically access and update the content, structure and the
  style of the document.
* This Model describes each webpage element, which of its properties can be
  changed and how to do it. DOM provides an object oriented programming
  interface between HTML/CSS and JavaScript.

If you are unsure about Boolean use explicit Boolean function.

Types are basic.
Control structures are pretty similar to C language control structures.

The short circuit logic is used in the Javascript world more.

Javascript Objects are simply collections of name-value pairs.  The name part
is a string and value is a Javascript object.The keys of the object are also
called object's properties.

* Dictionaries in Python
* Hashes in Perl and Python
* Hash Tables in C and C++
* HashMaps in Java
* Associative arrays in PHP

// Arrays come with a number of methods.

a.toString(), a.toLocaleString(), a.concat(item,...), a.join(sep),
a.pop(), a.push(item, ...), a.reverse(), a.shift(), a.slice(start, end),
a.sort(cmpfn), a.splice(start, delcount, [item]...), a.unshift([item]..)

Along with objects, functions are the core components in understanding JavaScript.

Functions have access to additional variable inside their body called
arguments, which is an array like object holding all the values passed to the
function.

The nameless functions are useful and clever because it allows you to put a
function in the place where an expression would be desirable.

The "named anonymous function" concept is what I see all the while in the Javascript.

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
name for it is "prototype chain". I don't understand the call method of the
javascript object.

DOM is api for HTML and XML. It provides a structural representation of the
Document, enabling you to modify the content and visual presentation. It is a
connection between web pages to scripts.

https://developer.mozilla.org/en/Introduction_to_Object-Oriented_JavaScript

https://developer.mozilla.org/en/JavaScript/Guide

alert function is not part of Javascript itself.

Every object in Javascript is an instance of the object Object and therefore
inherits it's properties and methods.

jQuery
------

jQuery's syntax is designed to make it easier to navigate a document, select
DOM elements, create animations, handle events, and develop Ajax applications.

jQuery also provides capabilities for developers to create plug-ins on top of
the JavaScript library. This enables developers to create abstractions for
low-level interaction and animation, advanced effects and high-level,
theme-able widgets. The modular approach to the jQuery framework allows the
creation of powerful and dynamic web pages and web applications.

jQuery contains the following features:

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

The jQuery library is a single JavaScript file, containing all of its common
DOM, event, effects, and Ajax functions. It can be included within a web page
by linking to a local copy, or to one of the many copies available from public
servers such as Google or Microsoft CDN.

<script type="text/javascript" src="jquery.js"></script>

The most popular and basic way to introduce a jQuery function is to use the .ready() function.

$(document).ready(function() {
// jquery goes here
});

or the shortcut

$(function() {
// jquery goes here
});

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
themselves. For example:

$("div.test").add("p.quote").addClass("blue").slideDown("slow");

The methods prefixed with $.  are convenience methods or affect global
properties and behaviour. For example, the following is an example of the map
function called each in jQuery:

$.each([1,2,3], function(){
  document.write(this + 1);
});

This writes the number 234 to the document.

Example of doing a simple Ajax request using jQuery.

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

Mako
----

mako for people in hurry. The Mako template library deals with 'view' portion
of the Pylons framework. It generates (X)HTML code, CSS and javascript that is
sent to the browser.

Base.mako template

# -*- coding: utf-8 -*-

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html>
  <head>
    ${self.head_tags()}
  </head>
  <body>
    ${self.body()}
  </body>
</html>


* Expressions wrapped in ${...} are evaluated by Mako and returned as text.
* ${ and } may span several lines but closing brace should not be a line by itself.
* Functions that are part of the self namespace are defined in the Mako
templates !! (I don't understand this).

Create another file in myapp/templates called my_action.mako and enter the following.

# -*- coding: utf-8 -*-
<%inherit file="/base.mako" />
<%def name="head_tags()">
  <!-- add some head tags here -->
</%def>
<h1>My Controller</h1>
<p>Lorum ipsum dolor yadda yadda</p>

* The inherit tag specifies a parent file to pass the program flow to.
* Mako defines functions with <% def name="function_name()">...</%def>. The
  contents of the tag is returned.
* Anything left after the Mako tags are parsed is automatically put into the
  body() function.

Rendering the Mako template as a controller.

In the controller - use the following as return value.
return render('my_action.mako')

Passing variables to Mako from the controller.

* The c object is passed to Mako from the controller.
* c.title = "Mr John Lives"
* <title>${c.title}</title>
* There is a webhelper function. link tag to the css or js. cool.
* Write python code in the mako by including it within <% and %>.

Output from python in mako is via template context.
%if %end, %for %endfor, %while %endwhile are the flow elements.

* Debug javascript using firebug. The console.debug and console.dir would help
  you do introspection.


Questions
=========

$('.task-edit .parent-entity-fields input').removeAttr('disabled');

These are all classes which are searched from left to right.

* What is happening here? .task-edit, .parent-entity-fields??
* jquery?


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

Statements in Javascript

A compilation unit contains a set of executable statements. In web browsers,
each <script> tag delivers a compilation unit that is compiled and immediately
executed. Lacking a linker, javascript throws them all together in a common
global namespace.

JQuery
------

Jquery is a cross browser javascript library that provides abstractions for DOM
traversals, event handling, animation and Ajax interactions for rapid web
development.

Provides abstractions for common client side tasks such as DOM traversal, event
handling, animation and Ajax. It also provides platform for creation of plugins
that extend JQuery capabilities beyond those provided by the core.

Know your DOM properties and Functions.

While one of the goals of jQuery is to abstract away the DOM, knowing DOM
properties can be extremely useful. One can utlize the awesome power of JQuery
to access the properties of an element.


