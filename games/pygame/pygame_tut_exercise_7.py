import pygame
import sys
screen = pygame.display.set_mode((800, 600))
while True:
    event = pygame.event.poll()
    if event.type == pygame.QUIT:
        sys.exit(0)

