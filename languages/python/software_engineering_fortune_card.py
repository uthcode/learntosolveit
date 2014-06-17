import textwrap
import subprocess
from PIL import Image, ImageFont, ImageDraw
import glob, os
im = Image.new("CMYK",(800,400))

p = subprocess.Popen(['fortune','-s'],
        stdout = subprocess.PIPE,
        stderr = subprocess.PIPE)
proc_stdout, proc_stderr = p.communicate()
text = proc_stdout

chosenfont = ImageFont.truetype('font.ttf',50)
draw = ImageDraw.Draw(im)
x , y = 10, 10
words_in_text = textwrap.wrap(text, 40)
for word in words_in_text:
    draw.text((x,y), word, font=chosenfont)
#    x = x + 20
    y = y + 40
im.save('fortune.jpg')
