import sys
import Image
import ImageFont, ImageDraw

WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
CARDSIZE =  (1000, 500)
PHOTOSIZE = (600, 500)
TEXTSIZE =  (400, 500)

TEXT_UP_LEFT = (10,10)
TEXT_MID_LEFT = (10,200)
TEXT_MID_CENTER = (50,200)
TEXT_LOW_LEFT = (10,400)
TEXT_LOW_RIGHT = (200,400)
TEXT_LOW_SIGNATURE = (200,450)

IMAGE_TIP = (0,0)
TEXT_TIP = (600, 0)

# Draw a Blank Area
blank = Image.new('RGB', CARDSIZE, color=WHITE)

# Crop the Image to Fit the Blank Area

if len(sys.argv) < 2:
    print('usage:python %s <image_file>' % __file__)
    sys.exit()
else: 
    photo = Image.open(sys.argv[1])

if photo.size >= PHOTOSIZE:
    photo = photo.resize(PHOTOSIZE) # use named tuple

# Write Text on a white image.

f = ImageFont.truetype('FreeSans.ttf', 30)
txt = Image.new('RGB', TEXTSIZE, color=WHITE)
draw = ImageDraw.Draw(txt)
draw.text(TEXT_UP_LEFT, "Dear Loga,", font=f, fill=BLACK)
draw.text(TEXT_MID_CENTER, "Happy Birthday!", font=f, fill=(250,0,0))
draw.text(TEXT_LOW_RIGHT, "Cheers!", font=f, fill=BLACK)
draw.text(TEXT_LOW_SIGNATURE, "Senthil", font=f, fill=BLACK)


# Fix the photo and the Text the Blank Area.
blank.paste(photo, IMAGE_TIP)
blank.paste(txt, TEXT_TIP)
blank.save('greeting.jpg')
