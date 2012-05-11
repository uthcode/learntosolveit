import sys
import random
import pygame
from pygame.locals import *
from pygame.color import *

import pymunk

def add_ball(space):
    mass = 1
    radius =  random.randint(10,30)
    inertia = pymunk.moment_for_circle(mass, 0, radius)
    body = pymunk.Body(mass, inertia)
    x = random.randint(120, 380)
    body.position = x, x
    shape = pymunk.Circle(body, radius)
    space.add(body, shape)
    x, y = random.randint(-150,100), random.randint(-250,100)
    space.gravity = (x, y)

    return shape

def draw_ball(screen, ball):
    p = int(ball.body.position.x), 600 - int(ball.body.position.y)
    pygame.draw.circle(screen, THECOLORS["tomato2"], p, int(ball.radius), 0)

def main():
    pygame.init()
    screen = pygame.display.set_mode((600, 600), pygame.RESIZABLE)
    pygame.display.set_caption("Nanho Game - Pyweek May 2012")
    clock = pygame.time.Clock()
    running = True

    space = pymunk.Space()
    x, y = random.randint(50,100), random.randint(50,100)
    space.gravity = (x, y)

    balls = []
    ticks_to_next_ball = 10

    while running:
        for event in pygame.event.get():
            if event.type == QUIT:
                running = False
            elif event.type == KEYDOWN and event.key == K_ESCAPE:
                running = False

        ticks_to_next_ball -= 1
        if ticks_to_next_ball <= 0:
            ticks_to_next_ball = 25
            ball_shape = add_ball(space)
            balls.append(ball_shape)

        screen.fill(THECOLORS["lightblue"])

        for ball in balls:
            draw_ball(screen, ball)

        space.step(1/50.0)
        pygame.display.flip()
        clock.tick(50)

if __name__ == '__main__':
    sys.exit(main())
