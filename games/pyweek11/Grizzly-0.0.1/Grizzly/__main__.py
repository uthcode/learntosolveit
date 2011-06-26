#!/usr/bin/python
# -*- coding: utf-8 -*-

# A cat has nine lives.

import pyglet
import sys
from game import resources, load
from game import player, rat, catfood, drycatfood, fish, goldfish, mice, milk, woolenball, tinfood

game_window = pyglet.window.Window(800, 600)
game_window.set_caption("~ Grizzly Games ~")

# white color background.

pyglet.gl.glClearColor(1.0,1.0,1.0,1.0)

main_batch = pyglet.graphics.Batch()

score_label = pyglet.text.Label(text="Lives Captured: 0", font_size = 10,
        bold=True, x = 50, y = 535,
        color = (100,100,155,155), batch = main_batch)
level_label1 = pyglet.text.Label(text=u"Capture (← ↑ ↓ → ) without hitting barb in 1 min.", font_size=10,
        bold=True, x = 50, y = 520,
        color = (100, 100, 155, 155),batch = main_batch)

level_label = pyglet.text.Label(text=u"A cat has nine lives. :o)", font_size=10,
        bold=True, x = 650, y = 535,
        color = (0, 0, 0, 100), anchor_x = 'center', batch = main_batch)

def update_score(items):
    global score_label
    score_label.delete()
    score = "Lives Captured: %s" % str(items)
    score_label = pyglet.text.Label(text=score, font_size = 10, bold=True, x = 50, y = 535,
        color = (100,100,155,155), batch = main_batch)


def congratulations():
    global level_label
    level_label.delete()
    level_label = pyglet.text.Label(text=u"Congratulations! You survived. :o)",
            font_size=10, bold=True, x = 600, y = 535,
            color = (0, 0, 0, 100), anchor_x = 'center', batch = main_batch)

def dashed():
    global level_label
    level_label.delete()
    level_label = pyglet.text.Label(text=u"Oops. You lost. Please try again.",
            font_size=10, bold=True, x = 580, y = 535,
            color = (0, 0, 0, 100), anchor_x = 'center', batch = main_batch)
    # pyglet.clock.schedule_once(pyglet.app.exit,5)


class Timer(object):
    def __init__(self):
        self.label = pyglet.text.Label('00:00', font_size=10, x = 600, y = 520, bold=True, batch = main_batch)
        self.reset()

    def reset(self):
        self.time = 0
        self.running = True
        self.label.text = '00:00'
        self.label.color = (0, 0, 0, 100)

    def update(self, dt):
        if self.running:
            self.time += dt
            m, s = divmod(self.time, 60)
            self.label.text = '%02d:%02d' % (m, s)
            if m >= 1:
                self.label.delete()
                self.label = pyglet.text.Label('Game Time Over!', font_size=10, x = 600, y = 520, bold=True, batch = main_batch)
                self.label.color = (0, 0, 0, 100)
                self.running = False

# Draw the Barb Fence
barb_horizontal1 = pyglet.sprite.Sprite(resources.barb_horizontal,x=0,y=0, batch = main_batch)
barb_horizontal2 = pyglet.sprite.Sprite(resources.barb_horizontal,x=0,y=540, batch = main_batch)
barb_vertical1 = pyglet.sprite.Sprite(resources.barb_vertical,x=0,y=0, batch = main_batch)
barb_vertical2 = pyglet.sprite.Sprite(resources.barb_vertical,x=740,y=0, batch = main_batch)

cat_sprite = player.Player(x=300, y=400, batch=main_batch)
rat_sprite = rat.Player(x=400, y=500, batch=main_batch)
catfood_sprite = catfood.Player(x=400, y=500, batch=main_batch)
drycatfood_sprite = drycatfood.Player(x=400, y=500, batch=main_batch)
fish_sprite = fish.Player(x=400, y=500, batch=main_batch)
goldfish_sprite = goldfish.Player(x=400, y=500, batch=main_batch)
mice_sprite = mice.Player(x=400, y=500, batch=main_batch)
milk_sprite = milk.Player(x=400, y=500, batch=main_batch)
woolenball_sprite = woolenball.Player(x=400, y=500, batch=main_batch)
tinfood_sprite = tinfood.Player(x=400, y=500, batch=main_batch)

#lives = load.lives(0, cat_sprite.position, main_batch)

life_objects = [rat_sprite, catfood_sprite,
        drycatfood_sprite, fish_sprite, goldfish_sprite, mice_sprite,
        milk_sprite, woolenball_sprite, tinfood_sprite]

game_window.push_handlers(cat_sprite)
game_window.push_handlers(cat_sprite.key_handler)

game_objects = [cat_sprite]

items = 0

timer = Timer()

def update(dt):
    barb_horizontal1.draw()
    barb_horizontal2.draw()
    barb_vertical1.draw()
    barb_vertical2.draw()
    timer.update(dt)

    global items

    try:
        player = game_objects[0]
        if not player.is_player:
            dashed()
    except Exception:
        dashed()

    if len(game_objects) < 2:
        try:
            player_sprite = life_objects.pop(0)
        except IndexError:
            try:
                player = game_objects[0]
            except Exception:
                 dashed()
            else:
                if player.is_player:
                    congratulations()
                else:
                    dashed()
        else:
            game_objects.append(player_sprite)

    for obj in game_objects:
        obj.update(dt)

    if not timer.running:
        for obj in game_objects:
            obj.dead = True

    for i in xrange(len(game_objects)):
        for j in xrange(i+1, len(game_objects)):
            obj_1 = game_objects[i]
            obj_2 = game_objects[j]
            if not obj_1.dead and not obj_2.dead:
                if obj_1.collides_with(obj_2) and (obj_1.is_player or obj_2.is_player):
                    obj_1.handle_collision_with(obj_2)
                    obj_2.handle_collision_with(obj_1)
                    items += 1
                    update_score(items)

    for to_remove in [obj for obj in game_objects if obj.dead]:
        to_remove.delete()
        game_objects.remove(to_remove)

@game_window.event
def on_draw():
    game_window.clear()
    main_batch.draw()

def main():
#if __name__ == '__main__':
    pyglet.clock.schedule_interval(update, 1/120.0)
    player = pyglet.media.Player()
    for i in range(3):
        player.queue(resources.game_music)
    player.play()
    pyglet.app.run()
