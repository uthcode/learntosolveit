import pygame
GREY = (210,210,210)

WINDOW = WIDTH, HEIGHT = 400, 300

def main():
    pygame.init()
    screen = pygame.display.set_mode(WINDOW)
    pygame.display.set_caption("Freed.in Demo")
    
    font = pygame.font.Font(None,42)
    text = font.render("Freed.in Rocks!", 1, GREY)
    textrect = text.get_rect()

    while True:
        screen.blit(text,textrect)
        pygame.display.flip()

if __name__ == '__main__':
    main()
