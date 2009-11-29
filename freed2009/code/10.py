import pygame
import sys
import os

SIZE = WIDTH, HEIGHT = 398,390

def main():
    pygame.init()
    pygame.display.set_caption("Escher")
    screen = pygame.display.set_mode(SIZE)

    picture = pygame.image.load('data' + os.sep + 'Drawing-hands.jpg').convert()
    picturerect = picture.get_rect()

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
        screen.blit(picture, picturerect)
        pygame.display.flip()


if __name__ == '__main__':
    main()
