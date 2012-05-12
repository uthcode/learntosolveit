import sys
import random
import pygame
import pymunk

from pygame.locals import *
from pygame.color import *
from pymunk import Vec2d

__version__ = 0.2

def to_pygame(point):
    """Hack to convert pymunk to pygame coordinates"""
    return int(point.x), int(-point.y+500)

class DrawSurf(object):
    """
    Create a surface used for drawing to the screen.
    """

    def __init__(self, destSurf, color=None):
        self.color = color
        self.destSurf = destSurf
        self.surface = self.makeSurf()

    def makeSurf(self):
        """
        Make a new pygame.Surface same size as the given destSurf
        """
        layer = None

        if self.color is not None:
            layer = pygame.Surface(self.destSurf.get_size(), flags=pygame.HWSURFACE)
            layer = layer.convert()
            layer.fill(self.color)
        else:
            layer = pygame.Surface(self.destSurf.get_size(), flags=pygame.SRCALPHA|pygame.HWSURFACE, depth=32)
            layer.convert_alpha()
            layer.fill((0, 0, 0, 0))

        return layer

    def draw(self):
        # Draw this surface to the defined drawSurface
        self.destSurf.blit(self.surface, (0, 0))

    def update(self, color):
        self.color = color
        self.surface.fill(self.color)

def main():
    # Primatians - woo
    print "Running Python version:", sys.version
    print "Running PyGame version:", pygame.ver
    print "Running PyMunk version:", pymunk.version
    print "Running Primatians version:", __version__

    pygame.init()
    screen = pygame.display.set_mode((800, 500), pygame.RESIZABLE)
    pygame.display.set_caption("Primatians  - A Nanho Games Production")
    # make our background object
    colorBackground = Color("darkolivegreen4")
    backgroundLayer = DrawSurf(screen, colorBackground)

    clock = pygame.time.Clock()
    running = True

    # Physics stuff
    space = pymunk.Space(50)
    space.gravity = (90, -90.0)

    # Balls
    balls = []
    mass = 1
    radius = 25
    inertia = pymunk.moment_for_circle(mass, 0, radius, (0,0))
    body = pymunk.Body(mass, inertia)
    x = random.randint(0,500)
    body.position = 400, 400
    shape = pymunk.Circle(body, radius, (0,0))
    shape.elasticity = 0.95
    space.add(body, shape)
    balls.append(shape)


    # Walls first

    static_body = pymunk.Body()
    # x1,y1, x2,y2
    static_lines = [pymunk.Segment(static_body, (0.0, 0.0), (0.0, 500.0), 5.0),
                    pymunk.Segment(static_body, (0.0, 500.0), (800.0, 500.0), 5.0),
                    pymunk.Segment(static_body, (800.0, 500.0), (800.0, 0.0), 5.0),
                    pymunk.Segment(static_body, (800.0, 0.0), (0.0, 0.0), 5.0)
                   ]

    for line in static_lines:
        line.elasticity = 0.7
        line.group = 1

    space.add(static_lines)

    # Some Logs

    static_logs = [pymunk.Segment(static_body, (200, 250), (600, 250), 5)]

    for logs in static_logs:
        logs.elasticity = 1
        logs.group = 1

    space.add(static_logs)

    # Add Flippers ( handler tree logs)

    fp = [(20,-20), (-120, 0), (20,20)]
    mass = 100
    moment = pymunk.moment_for_poly(mass, fp)

    # right flipper
    r_flipper_body = pymunk.Body(mass, moment)
    r_flipper_body.position = 750, 10
    r_flipper_shape = pymunk.Poly(r_flipper_body, fp)
    space.add(r_flipper_body, r_flipper_shape)

    r_flipper_joint_body = pymunk.Body()
    r_flipper_joint_body.position = r_flipper_body.position
    j = pymunk.PinJoint(r_flipper_body, r_flipper_joint_body, (0,0), (0,0))
    #todo: tweak values of spring better
    s = pymunk.DampedRotarySpring(r_flipper_body, r_flipper_joint_body, 0.15, 20000000,900000)
    space.add(j, s)

    # left flipper
    l_flipper_body = pymunk.Body(mass, moment)
    l_flipper_body.position = 10, 10
    l_flipper_shape = pymunk.Poly(l_flipper_body, [(-x,y) for x,y in fp])
    space.add(l_flipper_body, l_flipper_shape)

    l_flipper_joint_body = pymunk.Body()
    l_flipper_joint_body.position = l_flipper_body.position
    j = pymunk.PinJoint(l_flipper_body, l_flipper_joint_body, (0,0), (0,0))
    s = pymunk.DampedRotarySpring(l_flipper_body, l_flipper_joint_body, -0.15, 20000000,900000)
    space.add(j, s)

    # new flippers

    fp = [(20,-20), (-120, 0), (20,20)]
    #fp = [(120, 0), (120,-20),(-120,0)]
    mass = 100
    moment = pymunk.moment_for_poly(mass, fp)

    # top-right flipper
    tr_flipper_body = pymunk.Body(mass, moment)
    tr_flipper_body.position = 750, 450
    tr_flipper_shape = pymunk.Poly(tr_flipper_body, fp)
    space.add(tr_flipper_body, tr_flipper_shape)

    tr_flipper_joint_body = pymunk.Body()
    tr_flipper_joint_body.position = tr_flipper_body.position
    j = pymunk.PinJoint(tr_flipper_body, tr_flipper_joint_body, (0,0), (0,0))
    #todo: tweak values of spring better
    s = pymunk.DampedRotarySpring(tr_flipper_body, tr_flipper_joint_body, 0.15, 20000000,900000)
    space.add(j, s)

    # top-left flipper
    tl_flipper_body = pymunk.Body(mass, moment)
    tl_flipper_body.position = 50, 850
    tl_flipper_shape = pymunk.Poly(tl_flipper_body, [(-x,y) for x,y in fp])
    space.add(tl_flipper_body, tl_flipper_shape)

    tl_flipper_joint_body = pymunk.Body()
    tl_flipper_joint_body.position = tl_flipper_body.position
    j = pymunk.PinJoint(tl_flipper_body, tl_flipper_joint_body, (0,0), (0,0))
    s = pymunk.DampedRotarySpring(tl_flipper_body, tl_flipper_joint_body, -0.15, 20000000,900000)
    space.add(j, s)


    r_flipper_shape.group = l_flipper_shape.group = tr_flipper_shape.group = tl_flipper_shape.group = 1
    r_flipper_shape.elasticity = l_flipper_shape.elasticity = tr_flipper_shape.elasticity = tl_flipper_shape.elasticity = 0.4


    while running:
        for event in pygame.event.get():
            if event.type == QUIT:
                running = False
            elif event.type == KEYDOWN and event.key == K_ESCAPE:
                running = False
            elif event.type == KEYDOWN and event.key == K_j:
                r_flipper_body.apply_impulse(Vec2d.unit() * 40000, (-100,0))
            elif event.type == KEYDOWN and event.key == K_f:
                l_flipper_body.apply_impulse(Vec2d.unit() * -40000, (-100,0))
            elif event.type == KEYDOWN and event.key == K_g:
                tl_flipper_body.apply_impulse(Vec2d.unit() * 40000, (-100,0))
            elif event.type == KEYDOWN and event.key == K_h:
                tr_flipper_body.apply_impulse(Vec2d.unit() * -40000, (-100,0))

            if event.type == pygame.VIDEORESIZE:
                screen_size = event.size
                screen = pygame.display.set_mode(screen_size, pygame.RESIZABLE)
                oldBg = backgroundLayer.surface.copy()
                backgroundLayer = DrawSurf(screen, backgroundLayer.color)
                backgroundLayer.surface.blit(oldBg, (0, 0))

        # Draw
        # backgroundLayer.draw()

        screen.fill(THECOLORS["darkolivegreen"])

        # Draw lines

        for line in static_lines:
            body = line.body
            pv1 = body.position + line.a.rotated(body.angle)
            pv2 = body.position + line.b.rotated(body.angle)
            p1 = to_pygame(pv1)
            p2 = to_pygame(pv2)
            pygame.draw.lines(screen, THECOLORS["black"], False, [p1,p2])

        # Draw logs

        for log in static_logs:
            body = log.body
            pv1 = body.position + log.a.rotated(body.angle)
            pv2 = body.position + log.b.rotated(body.angle)
            p1 = to_pygame(pv1)
            p2 = to_pygame(pv2)
            pygame.draw.lines(screen, THECOLORS["brown"], False, [p1,p2])

        for ball in balls:
            p = to_pygame(ball.body.position)
            pygame.draw.circle(screen, THECOLORS["yellow"], p, int(ball.radius), 2)

        r_flipper_body.position = 790, 10
        l_flipper_body.position = 10, 10
        tr_flipper_body.position = 790, 490
        tl_flipper_body.position = 10, 490

        r_flipper_body.velocity = l_flipper_body.velocity = tr_flipper_body.velocity = tl_flipper_body.velocity = 0,0

        for f in [r_flipper_shape, l_flipper_shape, tr_flipper_shape, tl_flipper_shape,]:
            ps = f.get_points()
            ps.append(ps[0])
            ps = map(to_pygame, ps)
            color = THECOLORS["red"]
            pygame.draw.lines(screen, color, False, ps)

        # Update physics
        dt = 1.0/60.0/5

        for x in range(5):
            space.step(dt)

        pygame.display.flip()
        clock.tick(50)

if __name__ == '__main__':
    sys.exit(main())
