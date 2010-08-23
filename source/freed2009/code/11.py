import pygame
import sys
import os

BLACK = (0,0,0)
GREY = (210,210,210)
WINDOW = WIDTH, HEIGHT = 400, 300
MOVE = [1,1] # Y Axis, X Axis.

def main():
    pygame.init()
    screen = pygame.display.set_mode(WINDOW)
    pygame.display.set_caption("Freed.in Demo")
    
    picture = pygame.image.load('data' + os.sep + 'cork.png').convert()
    picturerect = picture.get_rect()

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()

        picturerect = picturerect.move(MOVE)
        
        if picturerect.left < 0 or picturerect.right > WIDTH:
            MOVE[0] = -MOVE[0]
        if picturerect.top < 0 or picturerect.bottom > HEIGHT:
            MOVE[1] = -MOVE[1]

        screen.fill(BLACK)
        screen.blit(picture,picturerect)
        pygame.display.flip()

if __name__ == '__main__':
    main()
