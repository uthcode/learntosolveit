import pygame
from pygame.locals import *

width = 640
height = 400

screen = pygame.display.set_mode((width, height))

running = 1

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = 0
