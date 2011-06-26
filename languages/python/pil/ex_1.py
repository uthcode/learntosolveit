import Image
import ImageDraw
import ImageFont

f = ImageFont.truetype('FreeSans.ttf',50)
im = Image.new("RGB",(400,400), color=(255,255,255))
draw = ImageDraw.Draw(im)
draw.text((10,50), "Happy Day!", font=f, fill=(0,0,0))
im.save("hello.jpg")
