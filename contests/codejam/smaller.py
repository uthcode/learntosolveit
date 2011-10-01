import re

str1 = """
(0.5 cool
  ( 1.000)
    (0.5 ))
    """

str2 = """
(0.2 furry 
    (0.81 fast 
               (0.3) 
               (0.2)
    ) 
    (0.1  fishy
               (0.3 freshwater 
                              (0.01) 
                              (0.01)
               )
               (0.1)
    )
)
"""

print str1.replace(')','').split('(') 
list1 = []
list1 = [x.strip() for x in str1.replace(')','').split('(') if x.strip()]
print list1

print str2.replace(')','').split('(')
list2 = []
list2 = [x.strip() for x in str2.replace(')','').split('(') if x.strip()]
print list2

regex = re.compile(r'([()]|\d\.\d+|\w+)')
tokens = tuple(regex.findall(str1))
print tokens
tokens = tuple(regex.findall(str2))
print tokens
