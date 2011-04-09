import math
from pyglet.window import key

import physicalobject, resources

class Player(physicalobject.PhysicalObject):

    def __init__(self, *args, **kwargs):
        super(Player,self).__init__(img=resources.cat_image, *args,
                **kwargs)
        self.thrust = 300.0
        self.rotate_speed = 200.0
        self.keys = dict(left=False,right=False,up=False)
        self.key_handler = key.KeyStateHandler()
        self.is_player = True

    def update(self, dt):
        super(Player, self).update(dt)

        if self.x <= 40 or self.y <= 40 or self.x >= 740 or self.y >= 560:
            self.dead = True

        if self.key_handler[key.LEFT]:
            self.rotation -= self.rotate_speed * dt
        if self.key_handler[key.RIGHT]:
            self.rotation += self.rotate_speed * dt
        if self.key_handler[key.UP]:
            angle_radians = -math.radians(self.rotation)
            force_x = math.cos(angle_radians) * self.thrust * dt
            force_y = math.cos(angle_radians) * self.thrust * dt
            self.velocity_x += force_x
            self.velocity_y += force_y

    def delete(self):
        super(Player, self).delete()
