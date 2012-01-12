.. -*- coding: utf-8 -*-
.. include:: <s5defs.txt>
.. |==>| unicode:: U+02794 .. thick rightwards arrow

======
Pylons 
======

.. class:: center

   | Web Development using Pylons
   | Singapore Python Users Group - Jan 2012

.. class:: right small

   | - Senthil Kumaran


.. container:: handout

    This presentation gives an overview of Pylons web development framework.

.. contents::
   :class: handout

.. footer:: 
    http://www.uthcode.com

Pylons
======


.. image:: pylons_ramesesseum.jpg
   :align: center
   :target: http://en.wikipedia.org/wiki/Pylon_%28architecture%29

A pylon is a monumental portal to an ancient Egyptian temple.

Pylons Web Framework
====================

* Is a lightweight web framework.
* Emphasizes flexiblity
* Rapid development of web applications 
* Uses standard tools from the Python community.

.. container:: handout

    * It does not suffer from Not-Invented-Here Syndrome.
    * It uses specific tools and the project has spawned off self-contained tools 

Motivation for you
==================

* Reddit_ with source on github
* Why did Quora_ choose to develop in Pylons?
* Pylons_ project website source on github
* Pros/Cons of `Django vs Pylons`_

.. _Quora: http://www.quora.com/Why-did-Quora-choose-to-develop-in-Pylons
.. _Reddit: https://github.com/reddit/reddit/wiki (Source!)
.. _Pylons: https://github.com/Pylons/pylons
.. _Django vs Pylons: http://stackoverflow.com/questions/48681/pros-cons-of-django-vs-pylons/784390#784390


Web Development
===============

* The first shot in dynamic website designs was CGI.
* Easy to write, but difficult to maintain.
* Memory hungry because it loads up the entire interpreter.
* *They* were using CGI

.. container:: handout

    Web frameworks such as Django and Ruby on Rails have become extremely popular
    in recent years because they provide a structure that allows you to quickly
    create good-looking web sites by defining the way the data is structured. The
    tools they provide then work on that data either to automatically generate code
    (scaffold in the case of Ruby on Rails) or to create form interfaces at runtime
    (as is the case with Django).

    Pylons provides sensible low-level APIs and methodologies that allow you to
    quickly and easily glue together the component parts you choose to use for
    yourself.

    Pylons is a collection of very carefully chosen 3rd party software.


Design Patterns
===============

At their heart, web applications

* Stored Data (Model)
* Represent Data in various ways (View)
* Execute Logic code for manipulation and control interaction. (Controller)

That's MVC_ for you.

.. _MVC: http://en.wikipedia.org/wiki/Model%E2%80%93view%E2%80%93controller

Pylons Environment
==================

* Get go-pylons.py_ script and create the virtual environment ``myenv``
* ``cd myenv``
* Activate it ``source bin/activate``
* find | less

.. container:: handout

    There are other ways to setup like compiling the code directly from the
    mercurial repository. But having a dedicated environment setup is probably
    good and best during development.

.. _go-pylons.py : http://www.pylonshq.com/download/1.0/go-pylons.py


Project Template
================

* paster_ utility to create project template and serve the project.

::

    (myenv)$paster create -t pylons helloworld

* Choose the components to use.

::

    (myenv)$cd helloworld
    (myenv)$paster serve development.ini

* ``paster`` utility to serve the project welcome page.

.. _paster: http://pythonpaste.org/script/


Contoller 
==========

* Create a contoller in the project to handle request.
* Use ``paster`` again.

::

    (myenv)$paster controller hello

* Edit ``helloworld/controller/hello.py``

* Browse http://localhost:5000/hello/index

Template
========

* ``templates/hello.mako``

::

    Hello World!<br>
    Your environ looks like ${request.environ}

* Update Controller to render template
