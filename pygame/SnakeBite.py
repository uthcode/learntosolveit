#! /usr/bin/env python

"""
SnakeBite - by PyMike
Released to the Public Domain
Created and documented on September 2nd, 2008 in 50 minutes.
"""

#import standard python modules
import os, random

#import uber cool pygame module
import pygame
from pygame.locals import *

#I'm hunnnnngry I neeeed ssssssome fruitsssss
class Snake(object):

	#Called when Snake() is called
	def __init__(self):
		self.pos = [160, 304] #Position of the snake's head
		self.body = []        #List holding the coordinates of the snake's body
		self.length = 3       #Length of the snake
		self.angle = 0        #Direction that the snake is facing
		self.alive = True     #Is he alive, or dead?

	#Called once every frame
	def update(self):

		#Insert the new position of the snake's head
		self.body.insert(0, list(self.pos))

		#make sure the snake's body isn't longer than it's length
		self.body = self.body[0:self.length]

		#Move 16 pixels according to the angle
		if self.angle == 0:
			self.pos[1] -= 16
		if self.angle == 90:
			self.pos[0] -= 16
		if self.angle == 180:
			self.pos[1] += 16
		if self.angle == 270:
			self.pos[0] += 16

		#If your head ran into your body, die!
		for b in self.body:
			if self.pos == b:
				self.alive = False

		#If your body is not in the 320x320 screen area, die!
		if self.pos[0] not in range(320):
			self.alive = False
		if self.pos[1] not in range(320):
			self.alive = False

	#I mussssst be vissssible
	def draw(self, surf):

		#Draw the head
		surf.fill((0, 0, 255), (self.pos[0], self.pos[1], 16, 16))

		#Draw the body
		for b in self.body:
			surf.fill((0, 0, 255), (b[0], b[1], 16, 16))

#Mmmmmm yum yum yum
class Fruit(object):

	#Called when Fruit() is called
	def __init__(self):
		self.change_pos() #Create the position of the friot

	#Move the fruit to a random position
	def change_pos(self):
		self.pos = [random.randrange(1, 18)*16, random.randrange(1, 18)*16]

	#Draw the fruit
	def draw(self, surf):
		surf.fill((255, 0, 0), (self.pos[0], self.pos[1], 16, 16))

#Main function
def main():
    
	#Call the SDL arg to center the window when it's inited, and then init pygame
	os.environ["SDL_VIDEO_CENTERED"] = "1"
	pygame.init()

	#Set up the pygame window
	pygame.display.set_caption("Snake")
	screen = pygame.display.set_mode((320, 320))

	#Init starting objects
	snake = Snake()
	fruit = Fruit()
	font = pygame.font.Font(None, 32)

	while 1:

		#Get the key input from pygame's event module
		for e in pygame.event.get():

			#QUIT is the big red X button on the window bar
			if e.type == QUIT:
				pygame.quit()
				return

			#Check if a key was pressed
			if e.type == KEYDOWN:

				#Quit if the Escape key is pressed
				if e.key == K_ESCAPE:
					pygame.quit()
					return

				#Change the snake's angle if the arrow keys are pressed
				if e.key == K_UP:
					snake.angle = 0
				if e.key == K_LEFT:
					snake.angle = 90
				if e.key == K_DOWN:
					snake.angle = 180
				if e.key == K_RIGHT:
					snake.angle = 270

		#call the snakes update function
		snake.update()

		#If the snake's "head" (pos) is the same as the fruit's, get fat! errr long ;)
		if snake.pos == fruit.pos:
			fruit.change_pos()
			snake.length += 1

		#If the snake died, draw text that says you died, and reinit the snake and fruit.
		if not snake.alive:
			gameovertext = font.render("You died!", 1, (0, 0, 0))
			screen.blit(gameovertext, (160-gameovertext.get_width()/2, 160-gameovertext.get_height()/2))
			pygame.display.flip()
			pygame.time.wait(1000)
			snake = Snake()
			fruit = Fruit()

		#Draw everything!
		screen.fill((255, 255, 255))
		snake.draw(screen)
		fruit.draw(screen)
		ren = font.render("Score: %d" % (snake.length-3), 1, (0, 0, 0))
		screen.blit(ren, (5, 5))
		pygame.display.flip()

		#Wait 100 milliseconds every frame. This keeps things from going a million miles per hour!
		pygame.time.wait(100)

#Run if executeed
if __name__ == "__main__":
    main()
