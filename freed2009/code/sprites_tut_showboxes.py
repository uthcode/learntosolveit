import pygame
from pygame.locals import *
from sprites_tut_boxes import Box

pygame.init()
boxes = []

for color, location in [([255, 0, 0], [0,0]), ([0, 255, 0], [0,60]), ([0, 0,
        255], [0, 120])]:
    boxes.append(Box(color, location))

screen = pygame.display.set_mode([150, 150])
for b in boxes: screen.blit(b.image, b.rect)
pygame.display.update()
while pygame.event.poll().type != KEYDOWN: pygame.time.delay(10)
