# Move the worm across the screen. Beware of borders and self!
import pygame

class Worm:
    def __init__(self, surface, x, y, length):
        self.surface = surface
        self.x = x
        self.y = y
        self.length = length
        self.dir_x = 0
        self.dir_y = -1
        self.body = []
        self.crashed = False

    def key_event(self, event):
        """Handle the keyboard events that affect the worm."""
        if event.key == pygame.K_UP:
            self.dir_x = 0
            self.dir_y = -1
        elif event.key == pygame.K_DOWN:
            self.dir_x = 0
            self.dir_y = 1
        elif event.key == pygame.K_LEFT:
            self.dir_x = -1
            self.dir_y = 0
        elif event.key == pygame.K_RIGHT:
            self.dir_x = 1
            self.dir_y = 0

    def move(self):
        """Move the mouse."""
        self.x += self.dir_x
        self.y += self.dir_y

        r, g, b, a = self.surface.get_at((self.x, self.y))
        if (r, g, b) != (0, 0, 0):
            self.crashed = True

        self.body.insert(0, (self.x, self.y))

        if len(self.body) > self.length:
            self.body.pop()

    def draw(self):
        """ Draw the worm."""
        for x, y in self.body:
            self.surface.set_at((x,y), (255,255,255))

# Window Dimensions

width = 640
height = 400


screen = pygame.display.set_mode((width, height))
clock = pygame.time.Clock()
running = True

# Our Worm
w = Worm(screen, width/2, height/2, 200)

while running:
    screen.fill((0,0,0))
    w.draw()
    w.move()

    if w.crashed or w.x <=0 or w.x >=width-1 or w.y <= 0 or w.y >= height-1:
        print "Crashed!"
        running = False

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.KEYDOWN:
            w.key_event(event)

    pygame.display.flip()
    clock.tick(240)
