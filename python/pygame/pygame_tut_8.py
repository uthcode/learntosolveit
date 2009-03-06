import pygame

bgcolor = 0, 0, 0
linecolor = 255, 255, 255

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
        x, y = event.pos

    screen.fill(bgcolor)
    pygame.draw.line(screen, linecolor, (x, 0), (x, 399))
    pygame.draw.line(screen, linecolor, (0, y), (639, y))
    pygame.display.flip()
