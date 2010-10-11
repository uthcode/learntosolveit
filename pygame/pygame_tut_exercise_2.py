import pygame
import sys

if len(sys.argv) < 3:
    print "Usage Error: python program_name.py width height"
    sys.exit(1)
screen = pygame.display.set_mode((int(sys.argv[1]),int(sys.argv[2])))
while True:
    pass
