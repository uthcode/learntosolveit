import sys
import pygame

pygame.init()

size = width, height = 470,325
black = 0,0,0
white = 255,255,255

pygame.display.set_caption("Who Slides Wins!")

screen = pygame.display.set_mode(size)

picture = pygame.image.load("picture.jpg").convert()
pictrect = picture.get_rect()

# Draw vertical Rectangle
vrect = pygame.Rect(0,0,2,325)

# Create the Surface Object

vsurface = pygame.Surface(vrect.size)
vsurface.fill(black)

# Draw Horitical Rectangle
hrect = pygame.Rect(0,0,470,2)

# Create the Surface Object
hsurface = pygame.Surface(hrect.size)
hsurface.fill(black)

# Black Rectangle
brect = pygame.Rect(0,0,156,108)
bsurface = pygame.Surface(brect.size)
bsurface.fill(black)

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
    screen.fill(black)
    screen.blit(picture, pictrect)
    screen.blit(vsurface,(156,0))
    screen.blit(vsurface,(312,0))
    screen.blit(hsurface,(0,108))
    screen.blit(hsurface,(0,216))
    screen.blit(bsurface,(312,216))
    pygame.display.flip()
