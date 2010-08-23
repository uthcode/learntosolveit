import pygame
import sys

GREY = (210,210,210)
WINDOW = WIDTH, HEIGHT = 400, 300
MOVE = [0,1] # Y Axis, X Axis.

def main():
    pygame.init()
    screen = pygame.display.set_mode(WINDOW)
    pygame.display.set_caption("Freed.in Demo")
    
    font = pygame.font.Font(None,42)
    text = font.render("Freed.in Rocks!", 1, GREY)
    textrect = text.get_rect()

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()

        screen.blit(text,textrect)
        textrect = textrect.move(MOVE)
        pygame.display.flip()

if __name__ == '__main__':
    main()
