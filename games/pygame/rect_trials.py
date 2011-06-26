import sys
import pygame

pygame.init()

SIZE = width, height = 470,325
BLACK = (0,0,0)
WHITE = (255,255,255)

pygame.display.set_caption("Rectangle Trials")

screen = pygame.display.set_mode(SIZE)

# Draw vertical Rectangle
vrect = pygame.Rect(0,0,10,30)

# Create the Surface Object

vsurface = pygame.Surface(vrect.size)
vsurface.fill(BLACK)

# Draw Horitical Rectangle
hrect = pygame.Rect(0,0,30,10)

# Create the Surface Object
hsurface = pygame.Surface(hrect.size)
hsurface.fill(BLACK)

while True:
    vsurface = pygame.Surface(vrect.size)
    vsurface.fill(BLACK)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
    screen.fill(WHITE)
    screen.blit(vsurface, (312, 0))
    screen.blit(hsurface, (0, 216))
    vrect.move(10,60)
    hrect.move(60,10)
    pygame.display.flip()
