import tkinter
import time

class App():
    def __init__(self,target):
        self.root = tkinter.Tk()
        self.label = tkinter.Label(text="")
        self.label.pack()
        self.update_clock()
        self.root.mainloop()

    def update_clock(self):
        now = time.strftime("%H:%M:%S")
        self.label.configure(text=now)
        self.root.after(1000, self.update_clock)

HH = 23
MM = 30

now = time.localtime(time.time())
hour = 23
minutes  = 30
target = time.mktime((year,mon,mday,hour,minutes,sec,wday,yday,isdst))

app=App(target)
