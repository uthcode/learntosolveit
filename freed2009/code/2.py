import pygame

WINDOW = WIDTH, HEIGHT = 400, 300

def main():
    pygame.init()
    screen = pygame.display.set_mode(WINDOW)
    pygame.display.set_caption("Freed.in Demo")

    while True:
        pygame.display.flip()

if __name__ == '__main__':
    main()
