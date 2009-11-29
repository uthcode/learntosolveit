import pygame

x = y = 0
running = 1

width = 640
height = 400

screen = pygame.display.set_mode((width, height))

while running:
    event = pygame.event.poll()
    if event.type == pygame.QUIT:
        running = 0
    elif event.type == pygame.MOUSEMOTION:
        print "mouse at (%d, %d)" % event.pos

    screen.fill((0, 0, 0))
    pygame.display.flip()


