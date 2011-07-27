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
* The result was proliferation of frameworks and libraries and server side javascript too.
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
    * functions
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
 * {{{ == performs type coercion, while === }}} does not perform type coercion.
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


 * Leaving a trailing comma at the end of the array literal is incosistent across browsers, so don't do it.
 * array.length is one more than the highest index of the array.
 * splice method on a array lets you modify an array by deleting a section and replacing it with more items.
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
 * How to handle simple browsers? Browsers that do not support javascript will display the javascript as page contents. To prevent them from doing this and as part of the javascript standard, the HTML comment tag should be used to hide the javascript.
 

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

 * // is the javascript comment tag. it prevents javascript from executing the --> tag.
 * Javascripts in the body section will be executed while the page loads.
 * Javascripts in the head section will be executed when the page is called.
 * It is normal to add semi-colon ';' to end of the javascript statement, but it is completely optional.
 * Variable names in JavaScript is case sensitive.
 * In Javascript you dont need to import Math objects, it is always available to you.

 * DOM is a platform and a language neutral interface that allows programs and scripts to dynamically access and update the content, structure and the style of the document.
 * This Model describes each webpage element, which of its properties can be changed and how to do it. DOM provides an object oriented programming interface between HTML/CSS and JavaScript.
   zR

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


- Expressions wrapped in ${...} are evaluated by Mako and returned as text.
- ${ and } may span several lines but closing brace should not be a line by itself.
- Functions that are part of the self namespace are defined in the Mako
templates !! (I don't understand this).


Create another file in myapp/templates called my_action.mako and enter the following.

# -*- coding: utf-8 -*-
<%inherit file="/base.mako" />
<%def name="head_tags()">
  <!-- add some head tags here -->
</%def>
<h1>My Controller</h1>
<p>Lorum ipsum dolor yadda yadda</p>

- The inherit tag specifies a parent file to pass the program flow to.
- Mako defines functions with <% def name="function_name()">...</%def>. The
contents of the tag is returned.
- Anything left after the Mako tags are parsed is automatically put into the
body() function.


Rendering the Mako template as a controller.

In the controller - use the following as return value.
return render('my_action.mako')

Passing variables to Mako from the controller.

- The c object is passed to Mako from the controller.
- c.title = "Mr John Lives"
- <title>${c.title}</title>
- There is a webhelper function. link tag to the css or js. cool.
- Write python code in the mako by including it within <% and %>.

Output from python in mako is via template context.
%if %end, %for %endfor, %while %endwhile are the flow elements.








Questions
=========

$('.task-edit .parent-entity-fields input').removeAttr('disabled');

- What is happening here? .task-edit, .parent-entity-fields??
- jquery?

