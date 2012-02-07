import urllib2
import json
import sys

sys.stderr = open('error.log', 'a')
jsondata = urllib2.urlopen('https://www.ai-class.com/course/json/filter/quizquestion').read()
pydict = json.loads(jsondata)
print json.dumps(pydict, sort_keys=True, indent=4)
sys.stderr.close()
