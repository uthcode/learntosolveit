import pygame

bgcolor = 0, 0, 0
blueval = 0
bluedir = 1

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

    pygame.draw.line(screen, (0, 0, blueval), (x, 0), (x, 399))
    pygame.draw.line(screen, (0, 0, blueval), (0, y), (639, y))

    blueval += bluedir

    if blueval == 255 or blueval == 0: bluedir *= -1
    pygame.display.flip()
