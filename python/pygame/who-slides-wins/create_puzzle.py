#!/usr/bin/env python
#-*- coding:utf-8 -*-

import os
import sys
import shutil

import pygame
from pygame.locals import *

import getpicture

BLACK = (0,0,0)
WHITE = (255, 255, 255)

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
        image = pygame.image.load(full_path)
    except pygame.error, message:
        print 'Cannot load image.'
        raise SystemExit, message
    image = pygame.transform.scale(image, (width, height))
    image.convert()
    return image

def get_blank_surface(width, height):
    blank_surface = pygame.Surface((width, height))
    blank_surface.fill([0,0,0])
    return blank_surface

def draw_outline(surface, color, width):
    top_left = (0,0)
    top_right = (surface.get_width() - width, 0)
    bottom_left = (0, surface.get_height() - width)
    bottom_right = (surface.get_width() - width, surface.get_height() - width)
    pygame.draw.polygon(surface, color, [top_left, bottom_left, bottom_right,
            top_right], width)

class CreatePuzzle:
    """Creates the NxN picture puzzle."""
    def __init__(self, width, height):
        pygame.init()
        self.main_surface = pygame.display.set_mode((width, height))
        pygame.display.set_caption("Who Slides Wins!")
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
                draw_outline(piece_surface, outline_color, outline_width)
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
        self.sprite_group.clear(self.main_surface, self.blank_surface)

if __name__ == '__main__':
    if not os.path.exists('data'+ os.path.sep + 'images' + os.path.sep + 'picture.jpg'):
        pass
    elif not os.path.exists('picture.jpg'):
        getpicture.getpicture()
        shutil.move('picture.jpg', 'data' + os.path.sep + 'images' +
                os.path.sep)
    obj = CreatePuzzle(width=630,height=450)
    last_event_type = None
    last_event_key = None
    while True:
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
        obj.update()
