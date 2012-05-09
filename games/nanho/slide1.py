import sys
import pygame
from pygame.locals import *
from pygame.color import *

import pymunk

def main():
    pygame.init()
    screen = pygame.display.set_mode((600, 600))
    pygame.display.set_caption("Joints. Just wait and the L will tip over")
    clock = pygame.time.Clock()
    running = True

    space = pymunk.Space()
    space.gravity = (0.0, -900.0)

    while running:
        for event in pygame.event.get():
            if event.type == QUIT:
                running = False
            elif event.type == KEYDOWN and event.key == K_ESCAPE:
                running = False
        screen.fill(THECOLORS["white"])
        space.step(1/50.0)
        pygame.display.flip()
        clock.tick(50)

if __name__ == '__main__':
    sys.exit(main())
