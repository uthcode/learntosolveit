====
Mako
====

mako for people in hurry. The Mako template library deals with 'view' portion
of the Pylons framework. It generates (X)HTML code, CSS and javascript that is
sent to the browser.

Base.mako template

::

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

Create another file in myapp/templates called my_action.mako and enter the
following.

::

    # -*- coding: utf-8 -*-
    <%inherit file="/base.mako" />
    <%def name="head_tags()">
      <!-- add some head tags here -->
    </%def>
    <h1>My Controller</h1>
    <p>Lorum ipsum dolor yadda yadda</p>

The inherit tag specifies a parent file to pass the program flow to.

* Mako defines functions with ``<% def name="function_name()">...</%def>``. The
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

::

    %if %end, %for %endfor, %while %endwhile are the flow elements.
