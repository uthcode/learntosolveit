import pygame
screen = pygame.display.set_mode((800,600))
while True:
    for event in pygame.event.get():
        print event.type, event.key
