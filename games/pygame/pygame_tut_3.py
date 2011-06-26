import pygame
screen = pygame.display.set_mode((640, 400))
running = 1

while running:
    event = pygame.event.poll()
    if event.type == pygame.QUIT:
        running = 0 
    screen.fill((0,0,0))
    pygame.display.flip()

