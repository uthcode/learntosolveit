import pygame
import sys

pygame.init()

size = width, height = 720, 660
speed = [1,1]
black = 0,0,0

screen = pygame.display.set_mode(size)

pygame.display.set_caption('Name is there!')

#background = pygame.Surface(screen.get_size())
#background = background.convert()
#background.fill(0,0,0)

if pygame.font:
    font = pygame.font.Font(None, 42)
    text = font.render("Good Day, Mr.Senthil.",1,(210,210,210))
    textpos = text.get_rect()

while 1:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()

    textpos = textpos.move(speed)
    if textpos.left < 0 or textpos.right > width:
        speed[0] = -speed[0]
    if textpos.top < 0 or textpos.bottom > height:
        speed[1] = -speed[1]

    screen.fill(black)
    screen.blit(text, textpos)
    #background.blit(text, textpos)
    #screen.blit(background, (0,0))
    pygame.display.flip()

