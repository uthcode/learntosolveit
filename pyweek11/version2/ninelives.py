#!/usr/bin/python

# A cat has nine lives.

import pyglet
from game import resources, load

game_window = pyglet.window.Window(800, 600)
main_batch = pyglet.graphics.Batch()

score_label = pyglet.text.Label(text="Score: 0", x = 10, y = 575,
        batch = main_batch)
level_label = pyglet.text.Label(text="A Cat Has Nine Lives.", x = 400, y = 575,
        anchor_x = 'center', batch = main_batch)

# The players should be an instance of the subclass
# pyglet.sprite.Sprite

cat_sprite = pyglet.sprite.Sprite(resources.cat_image, x=300, y=400,
        batch=main_batch)
rat_sprite = pyglet.sprite.Sprite(resources.rat_image, x=100,y=100,
        batch=main_batch)

lives = load.lives(3, cat_sprite.position, main_batch)

game_objects = lives

def update(dt):
    for obj in game_objects:
        obj.update(dt)

@game_window.event
def on_draw():
    game_window.clear()
    main_batch.draw()

if __name__ == '__main__':
    pyglet.clock.schedule_interval(update, 1/120.0)
    pyglet.app.run()
