import pygame
pygame.mixer.init()

pygame.mixer.music.load("player.wav")
while True:
    pygame.mixer.music.play()
