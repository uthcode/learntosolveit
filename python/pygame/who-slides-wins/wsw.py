import os
import sys
import time
import shutil
import signal

import pygame
from pygame.locals import *

import npuzzle
import getpicture


BLACK = (0,0,0)
WHITE = (255,255,255)
LGREEN = (192,255,192)

# Game Surface
game_window = (game_width, game_height) = (867, 627)
game_surface = pygame.display.set_mode(game_window)
game_surface.fill(BLACK)

# Computer Player Surface
# Other recommended value is (420, 300)
cp_window = (cp_width, cp_height) = (210, 150) 
cp_rect =  pygame.Rect(0,0,cp_width,cp_height)
cp_surface = pygame.Surface(cp_rect.size)
cp_surface.fill(BLACK)

# Player Surface
p_window = (p_width, p_height) = (630, 450)
p_rect =  pygame.Rect(0,0,p_width,p_height)
p_surface = pygame.Surface(p_rect.size)
p_surface.fill(BLACK)


# Image
image = pygame.image.load('picture.jpg')

# Computer Player Scaled Image.
cp_image = pygame.transform.scale(image, cp_window)
cp_image = cp_image.convert()


# Player Scaled Image:
p_image = pygame.transform.scale(image, p_window)
p_image = image.convert()

cp_piece_width = cp_width/3
cp_piece_height = cp_height/3

class CreateSprite(pygame.sprite.Sprite):
    def __init__(self, image,position):
        pygame.sprite.Sprite.__init__(self)
        self.image = image
        self.rect = image.get_rect()
        self.rect.topleft = position

sprite_group = pygame.sprite.OrderedUpdates()

for y in range(0, cp_height, cp_piece_height):
    for x in range(0, cp_width, cp_piece_width):
        piece_surface = pygame.surface.Surface((cp_piece_width, cp_piece_height))
        area = (x,y,cp_piece_width, cp_piece_height)
        piece_surface.blit(cp_image, (0,0), area)
        new_sprite = CreateSprite(piece_surface, (x,y))
        sprite_group.add(new_sprite)

sprite_group.remove(new_sprite)

blank_rect = pygame.Rect(0,0,cp_piece_width, cp_piece_height)
blank_rect_surface =  pygame.Surface(blank_rect.size)
blank_rect_surface.fill(BLACK)
blank_sprite = CreateSprite(blank_rect_surface,(x,y))
sprite_group.add(blank_sprite)

original_order = []

for sprite in sprite_group:
    original_order.append(sprite.image.copy())

def reorder(sprite_group, order=None):
    print order
    for sprite,i in zip(sprite_group,order):
        sprite.image = original_order[i-1]

class TimeoutFunctionException(Exception): 
    """Exception to raise on a timeout""" 
    pass 

class TimeoutFunction: 

    def __init__(self, function, timeout): 
        self.timeout = timeout 
        self.function = function 

    def handle_timeout(self, signum, frame): 
        raise TimeoutFunctionException()

    def __call__(self, *args): 
        old = signal.signal(signal.SIGALRM, self.handle_timeout) 
        signal.alarm(self.timeout) 
        try: 
            result = self.function(*args)
        finally: 
            signal.signal(signal.SIGALRM, old)
        signal.alarm(0)
        return result 

state = npuzzle.State(3)
start = state.start_state(10)
getsolution = TimeoutFunction(state.solve_it, 1)
nosolution = 1
while nosolution:
    try:
        solution = getsolution(start)
    except TimeoutFunctionException:
        pass
    else:
        nosolution = 0

solution.insert(0,start)

class PictureSprite(pygame.sprite.Sprite):
    def __init__(self, image, initial_position, boundary_rect):
        pygame.sprite.Sprite.__init__(self)
        self.image = image
        self.rect = image.get_rect()
        self.rect.topleft = initial_position
        self.intial_position = initial_position
        self.boundary_rect = boundary_rect
        self.move_speed = 10
        self.x_move = 0
        self.y_move = 0

    def is_moving(self):
        return self.x_move != 0 or self.y_move != 0

    def sprite_collide(self, sprite_group):
        collide_list = pygame.sprite.spritecollide(self, sprite_group, False)
        try:
            collide_list.remove(self)
        except ValueError:
            pass
        return len(collide_list) > 0

    def move(self, key, sprite_group):
        self.x_move, self.y_move = 0, 0
        if key == K_RIGHT:
            self.x_move = self.move_speed  # Move right
        elif key == K_LEFT:
            self.x_move = -(self.move_speed) # Move left
        elif key == K_UP:
            self.y_move = -(self.move_speed)  # Move up
        elif key == K_DOWN:
            self.y_move = self.move_speed     # Move down

        # check for collisions or outside boundary
        # if self.is_moving():
        self.rect.move_ip(self.x_move, self.y_move)
        if self.sprite_collide(sprite_group) or \
                not self.boundary_rect.contains(self):
                    self.rect.move_ip(-self.x_move, -self.y_move)
                    self.stop()
        self.rect.move_ip(-self.x_move, -self.y_move) # WHY??

    def stop(self):
        self.x_move,self.y_move = 0, 0

    def update(self, sprite_group):
        if self.is_moving():
            self.rect.move_ip(self.x_move, self.y_move)
            if self.sprite_collide(sprite_group) or \
                    not self.boundary_rect.contains(self):
                        self.rect.move_ip(-self.x_move, -self.y_move)
                        self.stop()

def get_picture_surface(file_name, width, height):
    full_path = os.path.join('data','images',file_name)
    try:
        picture = pygame.image.load(full_path)
    except pygame.error, message:
        try:
            full_path = os.path.join('data','images', 'default_picture.jpg')
            picture = pygame.image.load(full_path)
        except:
            print 'Cannot load image. Download again and Try!'
            raise SystemExit, message
    image = pygame.transform.scale(picture, (width, height))
    image.convert()
    return image

def get_blank_surface(width, height):
    blank_surface = pygame.Surface((width, height))
    blank_surface.fill(BLACK)
    return blank_surface

class CreatePuzzle:
    """Creates the NxN picture puzzle."""
    def __init__(self, player_surface, width, height):
        #pygame.init()
        self.main_surface = player_surface
        #pygame.display.set_caption("Who Slides Wins!")
        # N-Puzzle initialization
        self.nvalue = 3
        # self.clock = pygame.time.Clock()
        self.original_background = get_picture_surface('picture.jpg',
                width, height)
        self.blank_surface = get_blank_surface(width, height)
        self.width = width
        self.height = height
        self.sprite_group = self.create_sprites()

    def create_sprites(self):
        """ Creates N -1 sprites from background image. Returns a tuple of
        sprite group containing all of the sprites."""
        piece_width = self.width / self.nvalue
        piece_height = self.height / self.nvalue
        outline_color = BLACK
        outline_width = 1
        sprite_group = pygame.sprite.Group()
        new_sprite = None
        for top_left_x in range(0, self.width, piece_width):
            # Go column by column of each piece_width size
            for top_left_y in range(0, self.height, piece_height):
                # Cut piece_height pieces for that column
                piece_surface = pygame.surface.Surface((piece_width,
                    piece_height))
                borders = (top_left_x, top_left_y, piece_width, piece_height)
                # Blit a sub-section of the original background with border
                # specified. The blit method copies from original_background to
                # the piece_surface location 0,0, only the area specified by
                # the borders. 
                piece_surface.blit(self.original_background, (0,0), borders)
                #draw_outline(piece_surface, outline_color, outline_width)
                # Create a Sprite of the piece_surface.
                new_sprite = PictureSprite(piece_surface, (top_left_x,
                    top_left_y), self.main_surface.get_rect())
                sprite_group.add(new_sprite)

        sprite_group.remove(new_sprite)
        return sprite_group
    
    def update(self):
        """Update picture sprites."""
        self.sprite_group.update(self.sprite_group)
        self.sprite_group.draw(self.main_surface)
        pygame.display.update()
        #self.sprite_group.clear(self.main_surface, self.blank_surface)


pygame.init()

obj = CreatePuzzle(p_surface, width=630, height=450)
cp_surface.fill(BLACK)

last_event_type = None
last_event_key = None

obj.update()
for step in solution:
    if last_event_type == KEYDOWN and not True in \
            [sprite.is_moving() for sprite in obj.sprite_group]:
                    # The above condition is to do the move action only when
                    # someother sprite is not moving. If we dont have this,
                    # then the sprites will move together, the key action will
                    # act even before the other one has not completed yet.
        for sprite in obj.sprite_group:
            sprite.move(last_event_key, obj.sprite_group)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
                sys.exit()
        elif event.type == KEYDOWN or event.type == KEYUP:
            if event.key == K_RIGHT or event.key == K_LEFT \
                    or event.key ==  K_UP or event.key == K_DOWN:
                        last_event_type = event.type
                        last_event_key = event.key
            print last_event_key,last_event_type
    obj.update()
    reorder(sprite_group,step)
    sprite_group.draw(cp_surface)
    game_surface.blit(p_surface, (224,154))
    game_surface.blit(cp_surface, (3,3))
    obj.update()
    time.sleep(2)
    pygame.display.update()

while True:
    #game_surface.blit(cp_surface, (3,3))
    game_surface.blit(p_surface, (224,154))
    pygame.display.flip()

#if __name__ == '__main__':
#    if not os.path.exists('data'+ os.path.sep + 'images' + os.path.sep +
#            'picture.jpg'):
#        pass
#    elif not os.path.exists('picture.jpg'):
#        getpicture.getpicture()
#    else:
#        shutil.move('picture.jpg', 'data' + os.path.sep + 'images' + os.path.sep)
#    obj = CreatePuzzle(p_surface, width=630,height=450)
#    last_event_type = None
#    last_event_key = None
#    while True:
#        if last_event_type == KEYDOWN and not True in \
#                [sprite.is_moving() for sprite in obj.sprite_group]:
#                    # The above condition is to do the move action only when
#                    # someother sprite is not moving. If we dont have this,
#                    # then the sprites will move together, the key action will
#                    # act even before the other one has not completed yet.
#            for sprite in obj.sprite_group:
#                sprite.move(last_event_key, obj.sprite_group)
#        for event in pygame.event.get():
#            if event.type == pygame.QUIT:
#                sys.exit()
#            elif event.type == KEYDOWN or event.type == KEYUP:
#                if event.key == K_RIGHT or event.key == K_LEFT \
#                        or event.key ==  K_UP or event.key == K_DOWN:
#                            last_event_type = event.type
#                            last_event_key = event.key
#        obj.update()
