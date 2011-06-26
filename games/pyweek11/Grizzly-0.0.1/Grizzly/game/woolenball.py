import math
import time
import random
import pyglet

from pyglet.window import key

import physicalobject, resources

class Player(physicalobject.PhysicalObject):

    def __init__(self, *args, **kwargs):
        super(Player,self).__init__(img=resources.woolenball_image, *args,
                **kwargs)
        self.x = random.randint(60, 760)
        self.y = random.randint(60, 540)
        self.rotate_speed = 200.0
        self.velocity_x, self.velocity_y = random.randint(150,200), random.randint(150, 200)
        pyglet.clock.schedule_interval_soft(self.randomize, 2)

    def update(self, dt):
        self.visible = True
        super(Player, self).update(dt)

    def randomize(self, dt):
        self.rotation = random.randint(0, 360)
        self.x = random.randint(60, 760)
        self.y = random.randint(60, 540)
        if random.choice([True, False]):
            self.velocity_x = random.randint(150, 200)
            self.velocity_y = random.randint(150, 200)
        else:
            self.velocity_x = random.randint(50, 100)
            self.velocity_y = random.randint(50, 100)

    def delete(self):
        pyglet.clock.unschedule(self.randomize)
        super(Player, self).delete()
