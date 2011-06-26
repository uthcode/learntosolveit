import pygame
pygame.init()
game_surface = pygame.display.set_mode((630,450))
game_surface.fill((0,0,0))
rectangle = pygame.Rect(0,0,420,300)
surface = pygame.Surface(rectangle.size)
surface.fill((255,255,255))
while True:
    game_surface.blit(surface,(0,0))
    pygame.display.flip()
