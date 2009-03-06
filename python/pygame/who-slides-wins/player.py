import os
import sys
import time
import shutil

import pygame
from pygame.locals import *

import npuzzle
import getpicture
import utils
import computer

BLACK = (0,0,0)
WHITE = (255,255,255)
FONTCOLOR = (0,100,0)

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
            self.x_move = self.move_speed
        elif key == K_LEFT:
            self.x_move = -(self.move_speed)
        elif key == K_UP:
            self.y_move = -(self.move_speed)
        elif key == K_DOWN:
            self.y_move = self.move_speed

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

class PlayerSolution:
    """Creates the NxN picture puzzle."""
    def __init__(self, surface, initialstate, width, height):
        self.width = width
        self.height = height
        self.surface = surface
        self.initial_state = initialstate
        self.image = utils.get_picture('picture.jpg', width, height)
        self.piece_width = self.width / 3
        self.piece_height = self.height / 3
        self.clock = pygame.time.Clock()
        self.blank_surface = utils.get_blank_surface(width, height)
        self.sprite_group = self.createsprites()

    def createsprites(self):
        """ Creates N -1 sprites from background image. Returns a tuple of
        sprite group containing all of the sprites."""
        spritegroup = pygame.sprite.OrderedUpdates()
        for y in range(0, self.height, self.piece_height):
            for x in range(0, self.width, self.piece_width):
                piece_surface = pygame.surface.Surface((self.piece_width, self.piece_height))
                borders = (x, y, self.piece_width, self.piece_height)
                piece_surface.blit(self.image, (0,0), borders)
                new_sprite = PictureSprite(piece_surface, (x, y), self.surface.get_rect())
                spritegroup.add(new_sprite)

        spritegroup.remove(new_sprite)
        blank_rect = pygame.Rect(0,0,self.piece_width, self.piece_height)
        blank_rect_surface =  pygame.Surface(blank_rect.size)
        blank_rect_surface.fill(BLACK)
        blank_sprite = PictureSprite(blank_rect_surface,(x,y), self.surface.get_rect())
        spritegroup.add(blank_sprite)
        original_order = [sprite.image.copy() for sprite in spritegroup]
        for sprite, i in zip(spritegroup, self.initial_state):
            sprite.image = original_order[i-1]
        toremove = spritegroup.sprites()[self.initial_state.index(9)]
        spritegroup.remove(toremove)
        return spritegroup


    def update(self):
        """Update picture sprites."""
        self.sprite_group.clear(self.surface,self.blank_surface)
        self.sprite_group.update(self.sprite_group)
        self.sprite_group.draw(self.surface)
        pygame.display.update()


if __name__ == '__main__':
    p_window = (p_width, p_height) = (630, 450)
    pygame.init()
    pygame.display.set_caption("Who Slides Wins!")
    if pygame.mixer:
        music = os.path.join('data','player.wav')
        pygame.mixer.music.load(music)
        pygame.mixer.music.play(-1)
    fontfile = os.path.join('data','ARCADE.TTF')
    font = pygame.font.Font(fontfile,82)
    text = font.render("Who Slides Wins!",0,FONTCOLOR)
    messagefont = pygame.font.Font(fontfile,20)
    playersfont = pygame.font.Font(fontfile,20)
    subtextfont = pygame.font.Font(fontfile,30)
    compplayertext = playersfont.render("Computer Window",0,FONTCOLOR)
    playertext = playersfont.render("Player Window",0,FONTCOLOR)
    text1 = messagefont.render("Player Keys:",0,FONTCOLOR)
    text2 = messagefont.render("Left Arrow",0,FONTCOLOR)
    text3 = messagefont.render("Right Arrow",0,FONTCOLOR)
    text4 = messagefont.render("Up Arrow",0,FONTCOLOR)
    text5 = messagefont.render("Down Arrow",0,FONTCOLOR)
    subtext = messagefont.render("Computer vs Human. Arrange Picture with least moves and win!",0,FONTCOLOR)
    textpos = text.get_rect()
    game_window = (game_width, game_height) = (867, 627)
    game_surface = pygame.display.set_mode(game_window)
    game_surface.fill(BLACK)
    game_surface.blit(text,(240,10))
    game_surface.blit(subtext,(240,80))
    game_surface.blit(text1,(20,300))
    game_surface.blit(text2,(20,320))
    game_surface.blit(text3,(20,340))
    game_surface.blit(text4,(20,360))
    game_surface.blit(text5,(20,380))
    game_surface.blit(compplayertext,(1,160))
    game_surface.blit(playertext,(250,610))
    pygame.draw.rect(game_surface,FONTCOLOR,(10,280,150,150),4)
    # Player Surface
    p_rect =  pygame.Rect(0,0,p_width,p_height)
    p_surface = pygame.Surface(p_rect.size)

    p_piece_width = p_width/3
    p_piece_height = p_height/3

    # Computer Player Window
    cp_width, cp_height = 210, 150
    cp_window = (cp_width, cp_height)
    cp_rect =  pygame.Rect(0,0,cp_width,cp_height)
    cp_surface = pygame.Surface(cp_rect.size)
    cp_surface.fill((255,255,255))

    # N-Puzzle
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
    obj = PlayerSolution(p_surface,start,p_width,p_height)
    compplay = computer.ComputerSolution(cp_surface, start,cp_width, cp_height)
    compplay.reorder(start)
    compplay.update()
    last_event_type = None
    last_event_key = None
    computer_step = 1
    while True:
        moveover = False
        if last_event_type == KEYDOWN and not True in \
                [sprite.is_moving() for sprite in obj.sprite_group]:
                    for sprite in obj.sprite_group:
                        sprite.move(last_event_key, obj.sprite_group)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
            elif event.type == KEYDOWN or event.type == KEYUP:
                if event.key == K_RIGHT or event.key == K_LEFT \
                        or event.key == K_UP or event.key == K_DOWN:
                            last_event_type = event.type
                            last_event_key = event.key
                            moveover = True
                if moveover:
                    if computer_step >= len(solution):
                        break
                    compplay.reorder(solution[computer_step])
                    compplay.update()
                    computer_step = computer_step + 1
        obj.update()
        game_surface.blit(p_surface,(224,154))
        game_surface.blit(cp_surface, (3,3))
    print "Computer Won"
