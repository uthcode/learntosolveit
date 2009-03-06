#!/usr/bin/python
# Filename: yahoo_search.py

import sys
if sys.version_info[0] != 3:
    sys.exit('This program needs Python 3.0')

import json
import urllib, urllib.parse, urllib.request, urllib.response
import codecs

# Get your own APP ID at http://developer.yahoo.com/wsregapp/
YAHOO_APP_ID = 'jl22psvV34HELWhdfUJbfDQzlJ2B57KFS_qs4I8D0Wz5U5_yCI1Awv8.lBSfPhwr'
SEARCH_BASE = 'http://search.yahooapis.com/WebSearchService/V1/webSearch'

class YahooSearchError(Exception):
    pass

# Taken from http://developer.yahoo.com/python/python-json.html
def search(query, results=20, start=1, **kwargs):
    kwargs.update({
        'appid': YAHOO_APP_ID,
        'query': query,
        'results': results,
        'start': start,
        'output': 'json'
    })
    url = SEARCH_BASE + '?' + urllib.parse.urlencode(kwargs)
    obj = urllib.request.urlopen(url)
    #result = json.load(urllib.request.urlopen(url))
    result = json.load(obj,encoding='utf-8')
    if 'Error' in result:
        raise YahooSearchError(result['Error'])
    return result['ResultSet']

#query = input('What do you want to search for? ')
query = 'swaroop'
for result in search(query)['Result']:
    print("{0} : {1}".format(result['Title'], result['Url']))

