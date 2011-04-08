#!/usr/bin/python

# A cat has nine lives.

import pyglet
from game import resources, load

game_window = pyglet.window.Window(800, 600)

score_label = pyglet.text.Label(text="Score: 0", x = 10, y = 575)
level_label = pyglet.text.Label(text="A Cat Has Nine Lives.", x = 400, y = 575,
        anchor_x = 'center')

# The players should be an instance of the subclass
# pyglet.sprite.Sprite

cat_sprite = pyglet.sprite.Sprite(resources.cat_image, x=300, y=400)
rat_sprite = pyglet.sprite.Sprite(resources.rat_image, x=100,y=100)

lives = load.lives(3, cat_sprite.position)

@game_window.event
def on_draw():
    game_window.clear()
    score_label.draw()
    level_label.draw()
    cat_sprite.draw()
    rat_sprite.draw()
    for life in lives():
        life.draw()

if __name__ == '__main__':
    pyglet.app.run()
