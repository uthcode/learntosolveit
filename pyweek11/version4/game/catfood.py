import math
import time
import random
import pyglet

from pyglet.window import key

import physicalobject, resources

class Player(physicalobject.PhysicalObject):

    def __init__(self, *args, **kwargs):
        super(Player,self).__init__(img=resources.catfood_image, *args,
                **kwargs)
        self.thrust = 300.0
        self.rotate_speed = 200.0
        self.velocity_x, self.velocity_y = 80, 80
        #self.x = random.randint(60, 760)
        #self.y = random.randint(60, 540)
        #pyglet.clock.schedule_interval_soft(self.randomize, 2)

    def update(self, dt):
        self.visible = True
        super(Player, self).update(dt)

    def randomize(self, dt):
        self.x = random.randint(60, 760)
        self.y = random.randint(60, 540)

    def delete(self):
        pyglet.clock.unschedule(self.randomize)
        super(Player, self).delete()
