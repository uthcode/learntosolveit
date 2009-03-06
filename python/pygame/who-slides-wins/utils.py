import pygame
import os
import sys
import signal

BLACK = (0,0,0)
WHITE = (255, 255, 255)

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

def get_picture(file_name, width, height):
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
