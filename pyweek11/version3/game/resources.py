import pyglet

def center_image(image):
    """Sets an image's anchor point to its center."""
    image.anchor_x = image.width/2
    image.anchor_y = image.height/2

pyglet.resource.path = ['../resources']
pyglet.resource.reindex()

cat_image = pyglet.resource.image('cat.jpg')
rat_image = pyglet.resource.image('rat.jpg')

center_image(cat_image)
center_image(rat_image)
