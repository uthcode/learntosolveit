#!/usr/bin/env python
#
# Copyright 2007 Google Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

import webapp2
import cgi

form = """
<html>
<form method="post" action="/unit2">
<textarea name="text">%s</textarea>
<input type="submit">
</form>
</html>
"""

class MainHandler(webapp2.RequestHandler):
    def get(self):
        self.response.out.write('Hello Udacity!')

class Rot13Handler(webapp2.RequestHandler):
    def get(self, text=""):
        text = cgi.escape(text, quote=True)
        form_with_text = form % (text,)
        self.response.out.write(form_with_text)

    def post(self):
        text = self.request.get('text')
        text = text.encode('rot13')
        text = cgi.escape(text, quote=True)
        form_with_text = form % (text,)
        self.response.out.write(form_with_text)


app = webapp2.WSGIApplication([('/', MainHandler),
                               ('/unit2', Rot13Handler),
                               ],
                              debug=True)
