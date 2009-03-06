import pygame

width = 640
height = 400

screen = pygame.display.set_mode((width, height))
running = 1

while running:
    event = pygame.event.poll()
    if event.type == pygame.QUIT:
        running = 0
    else:
        print event.type,

