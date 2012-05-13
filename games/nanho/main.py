import sys
import random
import math
import pygame
import pymunk

from pygame.locals import *
from pygame.color import *
from pymunk import Vec2d

__version__ = 0.2

def to_pygame(point):
    """Hack to convert pymunk to pygame coordinates"""
    return int(point.x), int(-point.y+500)

def main():
    # Primatians - woo
    print "Running Python version:", sys.version
    print "Running PyGame version:", pygame.ver
    print "Running PyMunk version:", pymunk.version
    print "Running Primatians version:", __version__

    pygame.init()
    screen = pygame.display.set_mode((800, 500), pygame.RESIZABLE)
    pygame.display.set_caption("Primatians  - A Nanho Games Production")

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

    # Primates
    primates = []
    mass = 1
    radius = 25
    inertia = pymunk.moment_for_circle(mass, 0, radius, (0,0))
    body = pymunk.Body(mass, inertia)
    x = random.randint(0,500)
    body.position = 400, 400
    shape = pymunk.Circle(body, radius, (0,0))
    shape.elasticity = 0.95
    space.add(body, shape)
    primates.append(shape)


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


    r_flipper_shape.group = l_flipper_shape.group = 1
    r_flipper_shape.elasticity = l_flipper_shape.elasticity = 0.4

    # sprites
    ball_sprite = pygame.image.load('assets/banana-small.png')
    primate1_sprite = pygame.image.load('assets/primate2.png')

    while running:
        for event in pygame.event.get():
            if event.type == QUIT:
                running = False
            elif event.type == KEYDOWN and event.key == K_ESCAPE:
                running = False
            elif event.type == KEYDOWN and event.key == K_z:
                l_flipper_body.apply_impulse(Vec2d.unit() * -40000, (-100,0))
            elif event.type == KEYDOWN and event.key == K_x:
                r_flipper_body.apply_impulse(Vec2d.unit() * 40000, (-100,0))
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
            #angle_degrees = math.degrees(ball.body.angle) + 180
            #rotated_logo_img = pygame.transform.rotate(ball_sprite, angle_degrees)
            #offset = Vec2d(rotated_logo_img.get_size()) / 2.
            #x, y = ball.get_points()[0]
            #p = Vec2d(x,y)
            #p = p - offset
            screen.blit(ball_sprite, p)

            pygame.draw.circle(screen, THECOLORS["yellow"], p, int(ball.radius), 2)

        for primate in primates:
            p = to_pygame(primate.body.position)
            screen.blit(primate1_sprite, p)


        r_flipper_body.position = 790, 10
        l_flipper_body.position = 10, 10

        r_flipper_body.velocity = l_flipper_body.velocity = 0,0

        for f in [r_flipper_shape, l_flipper_shape]:
            ps = f.get_points()
            ps.append(ps[0])
            ps = map(to_pygame, ps)
            color = THECOLORS["burlywood4"]

            # we need to rotate 180 degrees because of the y coordinate flip
            # angle_degrees = math.degrees(f.body.angle) + 180
            # rotated_logo_img = pygame.transform.rotate(log_sprite, angle_degrees)
            # offset = Vec2d(rotated_logo_img.get_size()) / 2.
            # x, y = f.get_points()[0]
            # p = Vec2d(x,y)
            # p = p - offset
            # screen.blit(log_sprite, p)

            #pygame.draw.lines(screen, color, False, ps)
            pygame.draw.polygon(screen,color,ps,0)

        # Update physics
        dt = 1.0/60.0/5

        for x in range(5):
            space.step(dt)

        pygame.display.flip()
        clock.tick(50)

if __name__ == '__main__':
    sys.exit(main())
