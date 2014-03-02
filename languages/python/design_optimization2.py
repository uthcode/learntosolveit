def test1():
    """This is a comment"""
    x = 0
    if x: x = (x + x + (x + x) + (x + x + (x + x))) + (x + x + (x + x) + (x + x + (x + x)))
    if x: x = (x + (x + (x + (x + (x + (x + (x + (x
               + (x + (x + (x + (x + (x + (x + (x + x)))))))
              ))))))))

import sys, dis

dis.dis(test1)
