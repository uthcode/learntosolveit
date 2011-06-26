from functools import total_ordering

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
