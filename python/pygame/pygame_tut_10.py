import pygame

LEFT = 1

running = 1

width = 320
height = 200

screen = pygame.display.set_mode((width, height))

while running:
    event = pygame.event.poll()
    if event.type == pygame.QUIT:
        running  = 0
    elif event.type == pygame.MOUSEBUTTONDOWN and event.button == LEFT:
        print "You pressed the mouse button at (%d, %d)" % event.pos
    elif event.type == pygame.MOUSEBUTTONUP and event.button == LEFT:
        print "You release the mouse button at (%d, %d)" % event.pos

    screen.fill((0,0,0))
    pygame.display.flip()

