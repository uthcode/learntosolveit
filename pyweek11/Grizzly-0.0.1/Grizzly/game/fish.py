import math
import time
import random
import pyglet

from pyglet.window import key

import physicalobject, resources

class Player(physicalobject.PhysicalObject):

    def __init__(self, *args, **kwargs):
        super(Player,self).__init__(img=resources.fish_image, *args,
                **kwargs)
        self.thrust = 300.0
        self.rotate_speed = 200.0
        self.velocity_x, self.velocity_y = random.randint(80,100), random.randint(80, 100)
        pyglet.clock.schedule_interval_soft(self.randomize, 2)

    def update(self, dt):
        self.visible = True
        super(Player, self).update(dt)

    def randomize(self, dt):
        self.velocity_x = random.randint(100, 120)
        self.velocity_y = random.randint(100, 120)

    def delete(self):
        pyglet.clock.unschedule(self.randomize)
        super(Player, self).delete()
