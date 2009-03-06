import os
import sys
import time
import shutil

import pygame
from pygame.locals import *

import npuzzle
import utils

BLACK = (0,0,0)
WHITE = (255,255,255)

class CreateSprite(pygame.sprite.Sprite):
    def __init__(self, image,position):
        pygame.sprite.Sprite.__init__(self)
        self.image = image
        self.rect = image.get_rect()
        self.rect.topleft = position

class ComputerSolution:
    def __init__(self, surface, initialstate, width, height):
        self.cp_width = width
        self.cp_height = height
        self.cp_surface = surface
        self.initial_state = initialstate
        self.rate = 1000
        self.cp_image = utils.get_picture('picture.jpg', self.cp_width, self.cp_height)
        self.cp_piece_width = self.cp_width/3
        self.cp_piece_height = self.cp_height/3
        self.cp_sprites = self.createsprites()
        self.original_order = [sprite.image.copy() for sprite in self.cp_sprites]

    def createsprites(self):
        sprite_group = pygame.sprite.OrderedUpdates()
        for y in range(0, self.cp_height, self.cp_piece_height):
            for x in range(0, self.cp_width, self.cp_piece_width):
                piece_surface = pygame.surface.Surface((self.cp_piece_width, self.cp_piece_height))
                area = (x,y,self.cp_piece_width, self.cp_piece_height)
                piece_surface.blit(self.cp_image, (0,0), area)
                new_sprite = CreateSprite(piece_surface, (x,y))
                sprite_group.add(new_sprite)

        sprite_group.remove(new_sprite)
        blank_rect = pygame.Rect(0,0,self.cp_piece_width, self.cp_piece_height)
        blank_rect_surface =  pygame.Surface(blank_rect.size)
        blank_rect_surface.fill(BLACK)
        blank_sprite = CreateSprite(blank_rect_surface,(x,y))
        sprite_group.add(blank_sprite)
        #self.reorder(self.initial_state)
        return sprite_group

    def reorder(self, order):
        for sprite, i in zip(self.cp_sprites, order):
            sprite.image = self.original_order[i-1]

    def update(self):
        #self.cp_sprites.clear(self.cp_surface)
        self.cp_sprites.update(self.cp_sprites)
        self.cp_sprites.draw(self.cp_surface)
        pygame.display.update()
        pygame.time.wait(self.rate)


if __name__ == '__main__':
    pygame.init()
    game_window = (game_width, game_height) = (867, 627)
    game_surface = pygame.display.set_mode(game_window)
    game_surface.fill(BLACK)

    # Computer Player Surface
    cp_window = (cp_width, cp_height) = (210, 150) 
    cp_rect =  pygame.Rect(0,0,cp_width,cp_height)
    cp_surface = pygame.Surface(cp_rect.size)

    state = npuzzle.State(3)
    start = state.start_state(10)
    getsolution = utils.TimeoutFunction(state.solve_it, 1)
    nosolution = 1
    while nosolution:
        try:
            solution = getsolution(start)
        except utils.TimeoutFunctionException:
            pass
        else:
            nosolution = 0

    solution.insert(0,start)
    obj = ComputerSolution(cp_surface,start,cp_width,cp_height)
    for step in solution:
        print step
        obj.reorder(step)
        obj.update()
        game_surface.blit(cp_surface,(3,3))
        pygame.display.update()

    while True:
        obj.update()
        game_surface.blit(cp_surface,(3,3))
        pygame.display.update()

