
from data import *

#
#the color light-blue
#
LightBlue = lightblue

# the 'object' dictionary contains the strings of the menu items
# that denote the objects
objects = {}

# object dictionary initialization
objects['sphere'] = [ZERO, o1]
objects['cylinder'] = [ZERO, o2]
objects['cube'] = [ONE, o3]
objects['icecream'] = [ZERO, o4]
objects['disk'] = [ZERO, o5]
objects['diamond'] = [ZERO, o6]
#objects['glass'] = [ZERO]
objects['pyramid'] = [ZERO, o7]
objects['table'] = [ZERO, o8]

# 'putDict' sets the value of entry 'key' of dictionary 'dict'
def putDict(dict, key, val) :
       dict[key][0] = val

#
# 'getDict' get the contents of entry i of key  'key'
# of dictionary 'dict'
#
def getDict(dict, key, i) :
       return dict[key][i]

# the 'options' dictionary contains the strings of the menu items
# that denote the options
options = {}

# option dictionary initialization
options['wire'] = [ZERO]
options['filled'] = [ONE]
