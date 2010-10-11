import pygame
from pygame.locals import *
pygame.init()
pygame.display.set_mode((420,300))
while True:
    for event in pygame.event.get():
        if event.type == KEYDOWN or event.type == KEYUP:
            if event.key == K_RETURN:
                print "ENTER PRESSED"

