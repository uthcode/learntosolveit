import pygame
import sys

pygame.init()
size = width, height = 800, 600
black = 0,0,0

screen = pygame.display.set_mode(size).convert()
pygame.display.set_caption("Vertical Line")

vertical_rect = pygame.Rect(40,40,10,30)
vertical_line = pygame.Surface(vertical_rect.size)
vertical_line.fill((1, 255, 1))

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()

    #screen.fill(black)
    screen.blit(vertical_line, (400,0))
    pygame.display.flip()
