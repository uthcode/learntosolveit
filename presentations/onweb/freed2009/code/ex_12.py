import pygame
import sys


WINDOW = WIDTH, HEIGHT = 400, 300
BLACK = 0,0,0
WHITE = 255,255,255
RED   = 0,100,100

def main():
    pygame.init()
    screen = pygame.display.set_mode(WINDOW)
    
    # Let us draw a Rectangle using pygame.Rect call.
    
    # Horizontal Rectangle.
    h_rect = pygame.Rect(0,0,200,50)
    h_surface = pygame.Surface(h_rect.size)
    h_surface.fill(RED)

    # Vertical Rectangle.
    v_rect = pygame.Rect(0,0,50,150)
    v_surface = pygame.Surface(v_rect.size)
    v_surface.fill(RED)

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()

        screen.fill(WHITE)
        screen.blit(v_surface,(100,100))
        screen.blit(h_surface,(180,100))
        pygame.display.flip()

if __name__ == '__main__':
    main()
