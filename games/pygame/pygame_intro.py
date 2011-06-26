# First Program in Pygame
import sys
import pygame
pygame.init()

size = width, height = 520,440
speed = [1,1]
black = 0,0,0

screen = pygame.display.set_mode(size)

ball = pygame.image.load("cork.png")
ballrect = ball.get_rect()

while 1:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()

    ballrect = ballrect.move(speed)

    if ballrect.left < 0 or ballrect.right > width:
        speed[0] = -speed[0]
    if ballrect.top < 0 or ballrect.bottom > height:
        speed[1] = -speed[1]

    screen.fill(black)
    screen.blit(ball, ballrect)
    pygame.display.flip()

