Web Python Patterns
===================

WSGI Specification.
Two web programming models - CGI Standard and mod_python
Hosting Providers
CGI
mod_wsgi

CGI is ideal to learn the basic web programming concepts as there is no
magic running to hide those from the programmer. Part of the framework
communities take it as obsolete but read those comments with caution as
some are just snobbish. If you have no web programming experience and/or
want to grow solid roots then CGI is the way to go.

The WSGI application<->server interface specification is gaining momentum
and is today an acclamation. To use it is necessary to master web
programming concepts and/or a framework/toolkit.


Task
----

#) Run the CGI HTTPServer.
#) Write a CGI Script.
#) Expose the CGI Variables.
#) Execute an Involved CGI Script.


Topics
------

1. HTML
2. FORMS
3. HTTP
4. Web Architecture.
5. Simple Web sites. Complex Websites.
6. WSGI
7. PEP 333
8. cgi.py
9. wsgiref.py
10. Javascript
12. CSS


Some host providers only let you run CGI¹ scripts in a certain directory, often
named cgi-bin. In this case all you have to do to run the script is to call it
like this:

http://my_server.tld/cgi-bin/my_script.py

The script will have to be made executable by "others". Give it a 755
permission or check the executable boxes if there is a graphical FTP interface.

Some hosts let you run CGI scripts in any directory. In some of these hosts you
don't have to do anything to configure the directories. In others you will have
to add these lines to a file named .htaccess in the directory you want to run
CGI scripts from:

    Options +ExecCGI
    AddHandler cgi-script .py

If the file does not exist create it. All directories below a directory with a
.htaccess file will inherit the configurations. So if you want to be able to
run CGI scripts from all directories create this file in the document root.

If you are using your own server then probably you won't need to do anything to
run a CGI script at the cgi-bin directory. Just make sure there is a line like
the next in httpd.conf and that it is not commented. The trailing slashs are
required.

    ScriptAlias /cgi-bin/ "/path/to/cgi-bin/directory/"

If you are using the line above and want html files to be handled correctly in
the cgi-bin directory add the next to httpd.conf. No trailing slash.

    <Directory /path/to/cgi-bin/directory>
       AddHandler default-handler .html .htm
    </Directory>

To run a script saved at the root:

http://my_server.tld/my_script.py

If it was saved in some directory:

http://my_server.tld/some_dir/some_subdir/my_script.py

If your desktop is the server then execute it like this:

http://localhost/cgi-bin/my_script.py


CGI
---

It is necessary that the script outputs the HTTP header. The HTTP header
consists of one or more messages followed by a blank line. If the output of the
script is to be interpreted as HTML then the content type will be text/html.
The blank line signals the end of the header and is required.

    print "Content-Type: text/html"
    print

Blank Lines

    print "Content-Type: text/html\n"


Client versus Server
--------------------

When programming for the Web you are in a client-server environment. All python
code will be executed at the server only. The client's http agent (e.g. the
browser) will never see a single line of python. In instead it will only get
the python script output, be it text, html, css, javascript etc. So do not make
things like trying to open a file in the client's computer as if the python
script were running there. You can only achieve what your python script output
can and the http clients in general have a very restrictive security context.



If the user inputed data is to be shown in a HTML document then it is necessary
to escape it from HTML tags or else everything inside < > will be interpreted
by the HTML parser including javascript code like
<script type="text/javascript"> malicious code here </script>

The cgi.escape() method will transform the above into safe HTML text:
&lt;script type="text/javascript"&gt; malicious code here &lt;/script&gt;

This is useful not only to prevent script injection but also to make it
possible to display HTML source code as has just been done above.


CGI
---

With CGI you download it using curl or wget directly to a directory in your
site's hierarchy like a tmp directory:

http://my_site.tld/getshellcmd.py?curl -o tmp/Django-0.95.tar.gz http://media.djangoproject.com/releases/0.95/Django-0.95.tar.gz

http://my_site.tld/getshellcmd.py?tar -xzvf tmp/Django-0.95.tar.gz


