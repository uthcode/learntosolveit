import pyglet

def center_image(image):
    """Sets an image's anchor point to its center."""
    image.anchor_x = image.width/2
    image.anchor_y = image.height/2

pyglet.resource.path = ['../resources']
pyglet.resource.reindex()

cat_image = pyglet.resource.image('cat.png')
rat_image = pyglet.resource.image('rat2.png')
barb_vertical = pyglet.resource.image('barb_vertical.png')
barb_horizontal = pyglet.resource.image('barb_horizontal.png')

center_image(cat_image)
center_image(rat_image)
