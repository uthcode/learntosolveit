import pygame

class UpDownBox(pygame.sprite.Sprite):
    def __init__(self, color, initial_position):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.Surface([15, 15])
        self.image.fill(color)
        self.rect = self.image.get_rect()
        self.rect.topleft = initial_position
        self.going_down = True
        self.next_update_time = 0 # update() has not been called yet.

    def update(self, current_time, bottom):
        # update every 10 millisecond = 1/100th of a second
        if self.next_update_time < current_time:
            # If we are at the top or bottom of the screen, switch directions
            if self.rect.bottom == bottom - 1:
                self.going_down = False
            elif self.rect.top == 0:
                self.going_down = True

            # Move our position up or down by one pixel
            if self.going_down:
                self.rect.top += 1
            else:
                self.rect.top -= 1
            self.next_update_time = current_time + 10
