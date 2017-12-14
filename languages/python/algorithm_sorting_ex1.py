"""
**Multi-level sorting in Python.**

Problem:
    Suppose you have student tuple with elements name, age and grade. You got to
    sort them by age first and then by their grade.

Solution:
    It is easily accomplished by multi-level sorting using the *key* attribute
    of the sort function and using operator modules itemgetter function which
    can take multiple values.
"""
import operator

list_of_students = [("James",42,"A"), ("Harry",18,"A"), ("Haddock",50,"B"), ("TinTin",20,"A")]
print(list_of_students)
# [('James', 42, 'A'), ('Harry', 18, 'A'), ('Haddock', 50, 'B'), ('TinTin', 20, 'A')]

list_of_students = sorted(list_of_students, key=operator.itemgetter(1))
print(list_of_students)
# [('Harry', 18, 'A'), ('TinTin', 20, 'A'), ('James', 42, 'A'), ('Haddock', 50, 'B')]

