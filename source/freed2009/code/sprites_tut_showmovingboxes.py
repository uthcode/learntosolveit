import pygame
from pygame.locals import *
from sprites_tut_boxes2 import UpDownBox


pygame.init()
boxes = []

for color, location in [ ( [255,0,0], [0,0] ), ( [0,255,0], [60,60] ), (
        [0,0,255], [120, 120]) ]:
    boxes.append(UpDownBox(color, location))

screen = pygame.display.set_mode([150, 150])
while pygame.event.poll().type != KEYDOWN:
    screen.fill([0,0,0]) # Blank the screen

    # Save time by only calling this once

    time = pygame.time.get_ticks()
    for b in boxes:
        b.update(time, 150)
        screen.blit(b.image, b.rect)

    pygame.display.update()

