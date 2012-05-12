import sys
import pygame
import pymunk

from pygame.locals import *
from pygame.color import *

__version__ = 0.1

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
    screen = pygame.display.set_mode((800, 800), pygame.RESIZABLE)
    pygame.display.set_caption("Primatians  - A Nanho Games Production")
    # make our background object
    colorBackground = Color("green")
    backgroundLayer = DrawSurf(screen, colorBackground)

    clock = pygame.time.Clock()
    running = True


    while running:
        for event in pygame.event.get():
            if event.type == QUIT:
                running = False
            elif event.type == KEYDOWN and event.key == K_ESCAPE:
                running = False
            if event.type == pygame.VIDEORESIZE:
                screen_size = event.size
                screen = pygame.display.set_mode(screen_size, pygame.RESIZABLE)
                oldBg = backgroundLayer.surface.copy()
                backgroundLayer = DrawSurf(screen, backgroundLayer.color)
                backgroundLayer.surface.blit(oldBg, (0,0))


        # Draw
        backgroundLayer.draw()

        #screen.fill(THECOLORS["lightgreen"])

        pygame.display.flip()
        clock.tick(50)

if __name__ == '__main__':
    sys.exit(main())
