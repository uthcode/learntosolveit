#! /usr/bin/env python

from wsgiref.simple_server import make_server

def application(environ, start_response):

   response_body = ['%s: %s' % (key, value) for key, value in sorted(environ.items())]
   response_body = '\n'.join(response_body)

   # Response_body has now more than one string
   response_body = ['The Beggining\n',
                    '*' * 30 + '\n',
                    response_body,
                    '\n' + '*' * 30 ,
                    '\nThe End']

   # So the content-lenght is the sum of all string's lengths
   content_length = 0
   for s in response_body:
      content_length += len(s)

   status = '200 OK'
   response_headers = [('Content-Type', 'text/plain'),
                  ('Content-Length', str(content_length))]
   start_response(status, response_headers)

   return response_body

httpd = make_server('localhost', 8051, application)
httpd.handle_request()
