import os
import sys

pwd = '/Users/test/projects/appengine/python'
DIR_PATH = os.path.abspath((pwd))
SCRIPT_DIR = os.path.join(DIR_PATH, 'google', 'appengine', 'tools')
GOOGLE_SQL_DIR = os.path.join(
    DIR_PATH, 'google', 'storage', 'speckle', 'python', 'tool')

sys.path.append(SCRIPT_DIR)
sys.path.append(GOOGLE_SQL_DIR)

EXTRA_PATHS = [
  DIR_PATH,
  os.path.join(DIR_PATH, 'lib', 'antlr3'),
  os.path.join(DIR_PATH, 'lib', 'django_0_96'),
  os.path.join(DIR_PATH, 'lib', 'fancy_urllib'),
  os.path.join(DIR_PATH, 'lib', 'ipaddr'),
  os.path.join(DIR_PATH, 'lib', 'protorpc'),
  os.path.join(DIR_PATH, 'lib', 'webob'),
  os.path.join(DIR_PATH, 'lib', 'webapp2'),
  os.path.join(DIR_PATH, 'lib', 'yaml', 'lib'),
  os.path.join(DIR_PATH, 'lib', 'simplejson'),
  os.path.join(DIR_PATH, 'lib', 'google.appengine._internal.graphy'),
]


GOOGLE_SQL_EXTRA_PATHS = [
  os.path.join(DIR_PATH, 'lib', 'enum'),
  os.path.join(DIR_PATH, 'lib', 'google-api-python-client'),
  os.path.join(DIR_PATH, 'lib', 'grizzled'),
  os.path.join(DIR_PATH, 'lib', 'httplib2'),
  os.path.join(DIR_PATH, 'lib', 'oauth2'),
  os.path.join(DIR_PATH, 'lib', 'prettytable'),
  os.path.join(DIR_PATH, 'lib', 'python-gflags'),
  os.path.join(DIR_PATH, 'lib', 'sqlcmd'),
]

sys.path += EXTRA_PATHS
sys.path += GOOGLE_SQL_EXTRA_PATHS
