import pygame
from pygame.locals import *

BLACK = (0,0,0)
WHITE = (255,255,255)

game_window = (game_window_width, game_window_height) = (867, 627)

# Other recommended value is (420, 300)
computer_window = (computer_window_width, computer_window_height) = (210, 150) 
computer_rect =  pygame.Rect(3,3,computer_window_width, computer_window_height)
computer_surface = pygame.Surface(computer_rect.size)
computer_surface.fill(WHITE)

player_window = (player_window_width, player_window_height) = (630, 450)
player_rect =  pygame.Rect(216,146,player_window_width, player_window_height)
player_surface = pygame.Surface(player_rect.size)
player_surface.fill(WHITE)

pygame.init()

game_surface = pygame.display.set_mode(game_window)
game_surface.fill(BLACK)

while True:
    game_surface.blit(computer_surface, (3,3))
    game_surface.blit(player_surface, (224,154))
    pygame.display.flip()
