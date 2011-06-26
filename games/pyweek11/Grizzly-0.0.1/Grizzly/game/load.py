import math
import pyglet
import random
import resources
import physicalobject

from util import distance


def lives(num_lives, player_position, batch=None):
    lives = []
    for i in range(num_lives):
        rat_x, rat_y = player_position
        while distance((rat_x, rat_y), player_position) < 200:
            rat_x = random.randint(0, 800)
            rat_y = random.randint(0, 600)
        new_rat = physicalobject.PhysicalObject(img=resources.list_of_lives[i], x=rat_x,
                y=rat_y, batch=batch)
        new_rat.rotation = random.randint(0, 360)
        new_rat.velocity_x = random.random()*40
        new_rat.velocity_y = random.random()*40
        lives.append(new_rat)
    return lives


# Don't think we are using this.

def player_lives(num_icons, batch=None):
    player_lives = []
    for i in range(num_icons):
        new_sprite = pyglet.sprite.Sprite(img = resources.cat_image,
                                                x = 785 - i * 30,
                                                y = 585,
                                                batch = batch)
        new_sprite.scale = 0.8
        player_lives.append(new_sprite)
    return player_lives
