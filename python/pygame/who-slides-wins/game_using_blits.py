# The idea behind this snippet is just to create sprites.
import random
import npuzzle
import time
import copy

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

piece_width = width/3
piece_height = height/3

picture_pieces = {}
original_picture = {}
key = 1

for y in range(0, height, piece_height):
    for x in range(0, width, piece_width):
        piece_surface = pygame.surface.Surface((piece_width, piece_height))
        area = (x,y,piece_width, piece_height)
        piece_surface.blit(image, (0,0), area)
        picture_pieces[key] = [piece_surface, (x,y)]
        original_picture[key] = [piece_surface.copy(), (x,y)]
        key = key + 1

blank_rect = pygame.Rect(0,0,piece_width, piece_height)
blank_rect_surface =  pygame.Surface(blank_rect.size)
blank_rect_surface.fill(BLACK)

picture_pieces[key-1][0] = blank_rect_surface
original_picture[key-1][0] = blank_rect_surface.copy()

state = npuzzle.State(3)
start = state.start_state(10)
solution = state.solve_it(start)
solution.insert(0,start)

def picture_copy(picture_pieces):
    newpicture = {}
    for key,value in picture_pieces.iteritems():
        newpicture[key] = [value[0].copy(),value[1]]
    return newpicture

def rearrange(picture_pieces, order):
    original = picture_copy(picture_pieces)
    for key,value in picture_pieces.iteritems():
        picture_pieces[key][0] = original_picture[order[key-1]][0]

for i in range(len(solution)):
    print solution[i]
    rearrange(picture_pieces, solution[i])
    pygame.display.update()
    for key in picture_pieces.keys():
        surface.blit(picture_pieces[key][0], picture_pieces[key][1])
        #picture_pieces[key][0] = original[order[key-1]][0]
    pygame.display.update()
    time.sleep(10)
    
"""
print solution[0]
rearrange(picture_pieces, solution[0])
for key in picture_pieces.keys():
    surface.blit(picture_pieces[key][0], picture_pieces[key][1])
pygame.display.update()
time.sleep(2)

print solution[1]
rearrange(picture_pieces, solution[1])
for key in picture_pieces.keys():
    surface.blit(picture_pieces[key][0], picture_pieces[key][1])
pygame.display.update()
time.sleep(2)

print solution[2]
rearrange(picture_pieces, solution[2])
for key in picture_pieces.keys():
    surface.blit(picture_pieces[key][0], picture_pieces[key][1])
pygame.display.update()
time.sleep(2)

print solution[3]
rearrange(picture_pieces, solution[3])
for key in picture_pieces.keys():
    surface.blit(picture_pieces[key][0], picture_pieces[key][1])
pygame.display.update()
time.sleep(2)
"""

while True:
    pygame.display.update()
