============
Django Notes
============


The start a project, you would do - ``django-admin.py startproject mysite``

The startproject command creates a directory containing four files.  ::

    mysite/
        __init__.py
        manage.py
        settings.py
        urls.py

These files are as follows

* __init__.py: A file required for Python to treat the mysite directory as a
  package (i.e., a group of Python modules). It’s an empty file, and generally
  you won’t add anything to it.

* manage.py: A command-line utility that lets you interact with this Django
  project in various ways. Type python manage.py help to get a feel for what it
  can do. You should never have to edit this file; it’s created in this
  directory purely for convenience.

* settings.py: Settings/configuration for this Django project. Take a look at
  it to get an idea of the types of settings available, along with their
  default values.

* urls.py: The URLs for this Django project. Think of this as the “table of
  contents” of your Django-powered site. At the moment, it’s empty.

Django development server is called 'runserver'

``python manage.py runserver``


The main lesson here is this: a view is just a Python function that takes an
HttpRequest as its first parameter and returns an instance of HttpResponse. In
order for a Python function to be a Django view, it must do these two things.
(There are exceptions, but we’ll get to those later.)

