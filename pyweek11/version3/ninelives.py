#!/usr/bin/python

# A cat has nine lives.

import pyglet
from game import resources, load
from game import player

game_window = pyglet.window.Window(800, 600)
game_window.set_caption("9 lives")

# white color background.

pyglet.gl.glClearColor(1.0,1.0,1.0,1.0)

main_batch = pyglet.graphics.Batch()

score_label = pyglet.text.Label(text="Score: 0", x = 10, y = 575,
        batch = main_batch)
level_label = pyglet.text.Label(text="A Cat Has Nine Lives.", x = 400, y = 575,
        anchor_x = 'center', batch = main_batch)

# Draw the Barb Fench
barb_horizontal1 = pyglet.sprite.Sprite(resources.barb_horizontal,x=0,y=0, batch = main_batch)
barb_horizontal2 = pyglet.sprite.Sprite(resources.barb_horizontal,x=0,y=540, batch = main_batch)
barb_vertical1 = pyglet.sprite.Sprite(resources.barb_vertical,x=0,y=0, batch = main_batch)
barb_vertical2 = pyglet.sprite.Sprite(resources.barb_vertical,x=740,y=0, batch = main_batch)

cat_sprite = player.Player(x=300, y=400, batch=main_batch)


lives = load.lives(3, cat_sprite.position, main_batch)

game_objects = [cat_sprite] + lives

game_window.push_handlers(cat_sprite)
game_window.push_handlers(cat_sprite.key_handler)

def update(dt):
    barb_horizontal1.draw()
    barb_horizontal2.draw()
    barb_vertical1.draw()
    for obj in game_objects:
        obj.update(dt)

    for i in xrange(len(game_objects)):
        for j in xrange(i+1, len(game_objects)):
            obj_1 = game_objects[i]
            obj_2 = game_objects[j]
            if not obj_1.dead and not obj_2.dead:
                if obj_1.collides_with(obj_2):
                    obj_1.handle_collision_with(obj_2)
                    obj_2.handle_collision_with(obj_1)

    for to_remove in [obj for obj in game_objects if obj.dead]:
        to_remove.delete()
        game_objects.remove(to_remove)

@game_window.event
def on_draw():
    game_window.clear()
    main_batch.draw()

if __name__ == '__main__':
    pyglet.clock.schedule_interval(update, 1/120.0)
    pyglet.app.run()
