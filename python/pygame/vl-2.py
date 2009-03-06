import pygame
import sys

a = pygame.Rect(0,0,1,600)
b = pygame.Rect(10,10,80,80)

pygame.init()
screen = pygame.display.set_mode((800,600))

while True:
    back = pygame.Surface(a.size)
    back.fill((0, 255, 0))
    screen.blit(back, (400,0))
    pygame.display.update()
