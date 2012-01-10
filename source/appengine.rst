=========
AppEngine
=========

Appengine uses webapp web application framework and uses app engine datastore
with Python model api. The Python appengine sdk includes the web server
simulating the app engine environment, a local version of datastore, google
account, urlfetch and email.

The scripts dev_appserver.py is the development webserver and appcfg.py is used
for uploading the appengine script.

The standard for communication for applications to communicate with webserver
is still CGI. With a handler script and configuration file mapping every URL to
the handler, the application is complete.

Appengine supports any python framework that speaks CGI or WSGI framework using
the CGI adaptor.

A webapp application has three parts:

* one or more RequestHandler classes that process requests and build responses
* a WSGIApplication instance that routes incoming requests to handlers based on the URL
* a main routine that runs the WSGIApplication using a CGI adaptor

When webapp receives an HTTP GET request to the URL /, it instantiates the
MainPage class and calls the instance's get method. Inside the method,
information about the request is available using self.request. Typically, the
method sets properties on self.response to prepare the response, then exits.
webapp sends a response based on the final state of the MainPage instance.

The function run_wsgi_app() takes a WSGIApplication instance (or another
WSGI-compatible application object) and runs it in App Engine's CGI
environment. run_wsgi_app() is similar to the WSGI-to-CGI adaptor provided by
the wsgiref module in the Python standard library, but includes a few
additional features. 

Users service lets your application integrate with Google user accounts. 

The Python Datastore API

The App Engine datastore is a schemaless object datastore, with a query engine
and atomic transactions. The Python interface includes a rich data modeling API
and a SQL-like query language called GQL.

Using Forms. Display the HTML form in the get method and when submitted via
post, in the post method you can do a processing of request data which is submitted.

Datastore
---------

The datastore writes data in objects known as entities, and each entity has a
key that identifies the entity. Entities can belong to the same entity group,
which allows you to perform a single transaction with multiple entities. Entity
groups have a parent key that identifies the entire entity group.

In the High Replication Datastore, entity groups are also a unit of
consistency. Queries over multiple entity groups may return stale, eventually
consistent results. Queries over a single entity group return up-to-date,
strongly consistent, results. Queries over a single entity group are called
ancestor queries. Ancestor queries use the parent key (instead of a specific
entity's key).

Giving the db.StringProperty constructor the multiline=True parameter says that
values for this property can contain newline characters. Giving the
db.DateTimeProperty constructor a auto_now_add=True parameter configures the
model to automatically give new objects a date of the time the object is
created, if the application doesn't otherwise provide a value.

Doubtful

The parent has an entity kind "Guestbook". There is no need to create the
"Guestbook" entity before setting it to be the parent of another entity. In
this example, the parent is used as a placeholder for transaction and
consistency purposes. See Entity Groups and Ancestor Paths for more
information. Objects that share a common ancestor belong to the same entity
group. 

Finally, greeting.put() saves our new object to the datastore. If we had
acquired this object from a query, put() would have updated the existing
object. Since we created this object with the model constructor, put() adds the
new object to the datastore.

It's better to use a templating system, where the HTML is kept in a separate
file with special syntax to indicate where the data from the application
appears.

* ModelClass_
* PropertyClass_
* TypesandProperties_

.. _ModelClass: http://code.google.com/appengine/docs/python/datastore/modelclass.html

.. _PropertyClass: http://code.google.com/appengine/docs/python/datastore/propertyclass.html

.. _TypesandProperties: http://code.google.com/appengine/docs/python/datastore/typesandpropertyclasses.html

