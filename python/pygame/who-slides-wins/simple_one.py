# The idea behind this snippet is just to create sprites.
import random
import npuzzle
import time

import pygame
from pygame.locals import *

width, height = 420, 300
BLACK = (0,0,0)
WHITE = (255,255,255)

pygame.init()
surface = pygame.display.set_mode((width, height))
surface.fill(BLACK)

image = pygame.image.load('picture.jpg')
image = pygame.transform.scale(image, (width, height))
image = image.convert()

clock = pygame.time.Clock()

piece_width = width/3
piece_height = height/3

class CreateSprite(pygame.sprite.Sprite):
    def __init__(self, image,position):
        pygame.sprite.Sprite.__init__(self)
        self.image = image
        self.rect = image.get_rect()
        self.rect.topleft = position

sprite_group = pygame.sprite.OrderedUpdates()

for y in range(0, height, piece_height):
    for x in range(0, width, piece_width):
        piece_surface = pygame.surface.Surface((piece_width, piece_height))
        area = (x,y,piece_width, piece_height)
        piece_surface.blit(image, (0,0), area)
        new_sprite = CreateSprite(piece_surface, (x,y))
        sprite_group.add(new_sprite)

sprite_group.remove(new_sprite)

blank_rect = pygame.Rect(0,0,piece_width, piece_height)
blank_rect_surface =  pygame.Surface(blank_rect.size)
blank_rect_surface.fill(BLACK)
blank_sprite = CreateSprite(blank_rect_surface,(x,y))
sprite_group.add(blank_sprite)

original_order = []

for sprite in sprite_group:
    original_order.append(sprite.image.copy())

def reorder(sprite_group, order=None):
    print order
    #curr_images = []
    #for sprite in original_image:
    #    curr_images.append(sprite.image.copy())
    for sprite,i in zip(sprite_group,order):
        sprite.image = original_order[i-1]

state = npuzzle.State(3)
start = state.start_state(10)
solution = state.solve_it(start)
solution.insert(0,start)

surface.fill(BLACK)
for step in solution:
    reorder(sprite_group,step)
    sprite_group.draw(surface)
    time.sleep(2)
    pygame.display.update()

while True:
    pygame.display.update()

#positions = []
#base = {}
#
#for sprite in sprite_group:
#    positions.append(sprite.rect.topleft)
#
#for loc,position in zip(range(len(positions)),positions):
#    base[loc+1] = position
#
#def shuffle(group,display,base):
#    """
#    positions = []
#    for sprite in group:
#        positions.append(sprite.rect.topleft)
#    existing_way = {}
#    for loc,position in zip(range(len(positions)),positions):
#        existing_way[loc+1] = position
#    print existing_way
#    """
#    print display
#    #keys = existing_way.keys()
#    #keys.sort()
#    for sprite,value in zip(group,display):
#        sprite.rect.topleft = base[value]
#    return group
#        
#state = npuzzle.State(3)
#start = state.start_state(10)
#solution = state.solve_it(start)
#sprite_group = shuffle(sprite_group,start,base)
#
#while True:
#    sprite_group.draw(surface)
#    pygame.display.update()
#    #pygame.time.delay(5000)
#    clock.tick(2)
#    for step in solution:
#        sprite_group = shuffle(sprite_group, step,base)
#        print 'going to sleep'
#        time.sleep(5)
#        print 'next step'
#        for event in pygame.event.get():
#            if event.type == KEYDOWN or event.type == KEYUP:
#                print event.type
#                if event.key == K_RIGHT:
#                    print event.key
#                    #sprite_group = shuffle(sprite_group, state)
#                    pygame.time.delay(5000)
#                    sprite_group.draw(surface)
#                    pygame.display.update()
#                    clock.tick(2)
