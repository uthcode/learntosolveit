from functools import total_ordering

"""

http://en.wikipedia.org/wiki/Total_order

For pair of items from a set,  (that's the total)
if  a <= b  and  b <= c  then  a <= c  (part of the order)
if  a <= b  and  b <= a  then  a compares the same as b, a == b, (the
other part of the order)

"""

@total_ordering
class Student:
    def __init__(self, lastname, firstname):
        self.firstname = firstname
        self.lastname = lastname
    def __eq__(self, other):
        return ((self.lastname.lower(), self.firstname.lower()) ==
                (other.lastname.lower(), other.firstname.lower()))
    def __lt__(self, other):
        return ((self.lastname.lower(), self.firstname.lower()) <
                (other.lastname.lower(), other.firstname.lower()))


student1 = Student("Bond","James")
student2 = Student("Haddock","Captain")

# Where are these coming from?
print(student2 > student1)  # True
print(student2 >= student2) # True
print(student2 != student1) # True
