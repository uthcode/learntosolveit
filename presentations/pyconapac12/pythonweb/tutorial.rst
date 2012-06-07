Python and Web
==============

----

Welcome
=======

Thanks for coming to PyCon Apac 2012.

    - **Senthil Kumaran** 
    - *Python Core Developer*
    - *Engineer at Lucasfilm, Singapore*.

.. image:: senthil_qr2.png


---- 

Why this talk
=============

* Singapore has a web-dev mindshare
* RoR, Python, JS and Databases (Though they call it as Big Data).
* I feel it is skewed towards specific technologies.
* A wider understanding may help us more.

---- 

It's not a comparision
======================

* Because I could not compare!.
* All frameworks share some commonality above a certain level.
* We will look at Basic Differences.
* We will look at State of affairs in their world.


---- 

Factors at Look
===============

* Technology - How is the progress
* Ecosystem 
* Community.

Presenter Notes 
--------------- 

Technology means how the progress with new features and bug fixes. Ecosystem
involves other dependent libraries and their progress. Community aspects
involve adoption, participation and mindshare.


CPython
=======

* 3.3 Release is on the horizon.
* Many new features in the language and standard library.
* ipaddr module and multiple bug fixes Internet protocol libraries.
* **Web Frameworks Moving towards Python3**
* PEP 3333 Adoption has been good.

----

Python 3
========

.note: Insert Ryan's tweet Photo.

---- 

But that's not the case
=======================

* Django

* Pylons

* Web3Py

* Bottle, Flask


Thinking of Web
===============

* Django, Pylons, Pyramid, Web2py
* Flask, 
* Twisted, Tornado
* Python ORMs - SqlAlchemy.


Django
======

* Django Logo
* Reusability and Pluggability
* Admin Internets is still a **Big Win**.

Presenter Notes 
---------------

* Project started in 2005
* Current Stable release is 1.4
* Django Software Foundation and DjangoCon


Companies
=========

* Pinterest
* Instagram
* Discus
* PBS

Presenter Notes 
--------------- 

Pinterest

We use python + heavily-modified Django at the application layer.  Tornado and
(very selectively) node.js as web-servers.  Memcached and membase / redis for
object- and logical-caching, respectively.  RabbitMQ as a message queue.
Nginx, HAproxy and Varnish for static-delivery and load-balancing.  Persistent
data storage using MySQL.  MrJob on EMR for map-reduce.


Instagram

Django gunicorn.org as our WSGI server.
Deploying code - we use Fabric.
Postgresql
Push Notification - pyapns - Twisted service.
Python-munin - metrics
Django Sentry - Error Logging.

Django and Python 3
===================

* Move towards Python 2.6 and to Python 3.
* Use compatiblity layer and migration path.
* Fear is for the size of the community and not technical details

https://www.djangoproject.com/weblog/2012/mar/13/py3k/


