from javax.swing import *

def hello(event):
   print "Hello, world!"

frame = JFrame("Hello Jython")

button = JButton("Hello", actionPerformed = hello)
frame.add(button)

frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE)
frame.setSize(300, 300)
frame.show()
