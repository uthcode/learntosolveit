Developing Web Applications
===========================

----

Simple Web sites. Complex Websites.
===================================


Presenter Notes 
---------------

Reiterate the Morning Session Talk.


---- 

Virtualenv
==========

* Download VirtualEvn
* Setup the Virtual Environment.

---- 


Pylons Tutorial
===============

---- 


App Engine Tutorial
===================

* Introduction

* dev_appcfg.py
 
* appcfg.py


---- 

Hello, World!
=============

* helloworld directory

* helloworld.py

.. code-block:: python

    print 'Content-Type: text/plain'
    print ''
    print 'Hello, world!'

* app.yaml to point to the 

.. code-block:: python

    application: helloworld
    version: 1
    runtime: python
    api_version: 1

    handlers:
    - url: /.*
      script: helloworld.py

* python dev_appserver.py helloworld

Hello, Webapp!
==============

.. code-block:: python

    from google.appengine.ext import webapp
    from google.appengine.ext.webapp.util import run_wsgi_app

    class MainPage(webapp.RequestHandler):
        def get(self):
            self.response.headers['Content-Type'] = 'text/plain'
            self.response.out.write('Hello, webapp World!')

    application = webapp.WSGIApplication(
                                         [('/', MainPage)],
                                         debug=True)

    def main():
        run_wsgi_app(application)

    if __name__ == "__main__":
        main()


Using Users
===========

.. code-block:: python

    from google.appengine.api import users
    from google.appengine.ext import webapp
    from google.appengine.ext.webapp.util import run_wsgi_app

    class MainPage(webapp.RequestHandler):
        def get(self):
            user = users.get_current_user()

            if user:
                self.response.headers['Content-Type'] = 'text/plain'
                self.response.out.write('Hello, ' + user.nickname())
            else:
                self.redirect(users.create_login_url(self.request.uri))

    application = webapp.WSGIApplication(
                                         [('/', MainPage)],
                                         debug=True)

    def main():
        run_wsgi_app(application)

    if __name__ == "__main__":
        main()

-------

Handling Forms
==============

* Explore helloworld/helloworld3.py

-------


Using Datastore
===============

* Explore helloworld/helloworld4.py


Using Templates
===============

* Explore helloworld/helloworld5.py
* Explore index.html

Static HTML
===========

.. code-handler:: python

    handlers:
    - url: /stylesheets
      static_dir: stylesheets

Uploading to AppEngine
======================

* pyhton appcfg.py update



Flask on Facebook Tutorial
==========================

---- 


Thank you!
==========

---- 

