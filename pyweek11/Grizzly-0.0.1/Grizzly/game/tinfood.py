import math
import time
import random
import pyglet

from pyglet.window import key

import physicalobject, resources

class Player(physicalobject.PhysicalObject):

    def __init__(self, *args, **kwargs):
        super(Player,self).__init__(img=resources.tinfood_image, *args,
                **kwargs)
        self.thrust = 300.0
        self.rotate_speed = 200.0
        self.velocity_x, self.velocity_y = 300, -100
        pyglet.clock.schedule_interval_soft(self.randomize, 0.2)

    def update(self, dt):
        self.visible = True
        super(Player, self).update(dt)

    def randomize(self, dt):
        self.rotation = random.randint(0,260)

    def delete(self):
        pyglet.clock.unschedule(self.randomize)
        super(Player, self).delete()
