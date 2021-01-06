print('issubclass(type,object) ', issubclass(type,object))
print('issubclass(object,type) ', issubclass(object,type))
print('isinstance(type,object) ', isinstance(type,object))
print('isinstance(object,type) ', isinstance(object,type))
print('-------------------------')
try:
    print(issubclass(True,object))
except TypeError:
    print('issubclass(True,object) does not make sense. Object is not class.')
try:
    print(issubclass(1,object))
except TypeError:
    print('issubclass(1,object) does not make sense. Object is not class')
try:
    print(issubclass('c',object))
except TypeError:
    print("issubclass('c',object) does not make sense. Object is not class")
print('-------------------------')
try:
    print(issubclass(True,type))
except TypeError:
    print('issubclass(True,type) does not make sense. type is not class.')
try:
    print(issubclass(1,type))
except TypeError:
    print('issubclass(1,type) does not make sense. type is not class')
try:
    print(issubclass('c',type))
except TypeError:
    print("issubclass('c',type) does not make sense. type is not class")
print('-------------------------')
print('isinstance(True,object) ', isinstance(True,object))
print('isinstance(1,object) ', isinstance(True,object))
print('isinstance("c",object) ', isinstance(True,object))
print('-------------------------')
print('isinstance(True,type) ', isinstance(True,type))
print('isinstance(1,type) ', isinstance(True,type))
print('isinstance("c",type) ', isinstance(True,type))
