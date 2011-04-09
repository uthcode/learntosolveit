import pyglet

def center_image(image):
    """Sets an image's anchor point to its center."""
    image.anchor_x = image.width/2
    image.anchor_y = image.height/2

pyglet.resource.path = ['../resources']
pyglet.resource.reindex()

barb_vertical = pyglet.resource.image('barb_vertical.png')
barb_horizontal = pyglet.resource.image('barb_horizontal.png')


cat_image = pyglet.resource.image('cat.png')

# it's nine lives
rat_image = pyglet.resource.image('rat.png')
catfood_image = pyglet.resource.image('catfood.png')
drycatfood_image = pyglet.resource.image('drycatfood.png')
fish_image = pyglet.resource.image('fish.png')
goldfish_image = pyglet.resource.image('goldfish.png')
mice_image = pyglet.resource.image('mice.png')
milk_image = pyglet.resource.image('milk.png')
woolenball_image = pyglet.resource.image('woolenball.png')
tinfood_image = pyglet.resource.image('tinfood.png')

center_image(cat_image)
center_image(rat_image)
center_image(catfood_image)
center_image(drycatfood_image)
center_image(fish_image)
center_image(goldfish_image)
center_image(mice_image)
center_image(milk_image)
center_image(woolenball_image)
center_image(tinfood_image)

game_music = pyglet.resource.media('music.ogg', streaming=True)

list_of_lives = [rat_image, catfood_image, drycatfood_image, fish_image,
        goldfish_image, mice_image, milk_image, woolenball_image,
        tinfood_image]

