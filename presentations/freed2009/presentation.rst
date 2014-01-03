Let us Develop a Game Using PyGame.
===================================

Conference `Freed.in 2009`_


Presentor: O.R.Senthil Kumaran <senthil@uthcode.com>

Presentation Source at http://www.uthcode.com

.. _`Freed.in 2009`: http://freed.in/2009/

Assumptions
===========

* Curiousity.
* Game Development.
* Python Basics.


Let us Dive in
==============

* Let us have a pygame window to put some text in it.
* Our first the pygame window.

::

        # Complete Program.

        import pygame

        WINDOW = WIDTH, HEIGHT = 400, 300

        def main():
            pygame.init()
            screen = pygame.display.set_mode(WINDOW)

        if __name__ == '__main__':
            main()


That disappeared, What happened?
================================

* Truely so. Because we did not ask it to stay.
* In pygame, While True: pygame.display.flip() plays a major role in
  continously displaying the screen and making the image to stay.
* Additionally, we can set the window title using set_caption.

::

        # Complete Program.

        import pygame

        WINDOW = WIDTH, HEIGHT = 400, 300

        def main():
            pygame.init()
            screen = pygame.display.set_mode(WINDOW)
            pygame.display.set_caption("Freed.in Demo")

            while True:
                pygame.display.flip()

        if __name__ == '__main__':
            main()


Let us add text inside window
=============================

* Normal text wont do, you have to instantiate a Font() object and Render your text.
* Display (Blit) your text at the position, continuosuly.

::


        import pygame
        ...
        GREY = (210,210,210)

        def main():
            ...
            font = pygame.font.Font(None, 42)
            text = font.render("Freed.in Rocks!",1,GREY)
            textrect = text.get_rect()

            while True:
                screen.blit(text,textrect)
                pygame.display.flip()


Add a control to close Window
=============================

* Keys are got from pygame.event.get()
* Verify if the pygame.QUIT key is received.

::


        import pygame
        import sys
        ...
        def main():
            ... 
            textrect = text.get_rect()
            ...
            while True:
                for event in pygame.event.get():
                    if event.type == pygame.QUIT:
                        sys.exit()

                screen.blit(text,textrect)
                pygame.display.flip()


I want some animation.
======================

* Let us move the text.
* In pygame, you move the textrect to different position.

::

        import pygame
        ...
        MOVE = [0,1]  # X Direction, Y Direction.

        def main():
            pygame.init()
            ...
            while True:
                ...
                screen.blit(text,textrect)
                textrect = textrect.move(MOVE)
                pygame.display.flip()


That was Ugly
=============

* Because, we did not blit it with BLACK Background again.

::

        import pygame
        ...
        BLACK = (0,0,0)
        GREY = (210,210,210)
        MOVE = [0,1]  # X Direction, Y Direction.

        def main():
            pygame.init()
            ...
            while True:
                ...
                textrect = textrect.move(MOVE)

                screen.fill(BLACK)
                screen.blit(text,textrect)
                textrect = textrect.move(MOVE)
                pygame.display.flip()


It Fell Down! 
=============

* We had not added any logic or control to move.
* Let us move it till it reaches the bottom of the screen and then move it back
  up.

::

        import pygame
        ...
        MOVE = [0,1]  # Y Direction, X Direction.

        def main():
            pygame.init()
            ...
            while True:
                ...
                textrect = textrect.move(MOVE)

                if textrect.top < 0 or textrect.bottom > HEIGHT:
                    MOVE[1] = -MOVE[1]  # Move in the opposite Direction.

                screen.fill(BLACK)
                screen.blit(text,textrect)



Movement Across the screen.
===========================

::

        import pygame
        ...
        MOVE = [1,0]  # Y Direction, X Direction.

        def main():
            pygame.init()
            ...
            while True:
                ...
                textrect = textrect.move(MOVE)

                if textrect.left < 0 or textrect.right > WIDTH:
                    MOVE[0] = -MOVE[0]  # Move in the opposite Direction.
                ...
            ...


Lets do both
============

::

        import pygame
        ...
        MOVE = [1,1]  # Y Direction, X Direction.

        def main():
            pygame.init()
            ...
            while True:
                ...
                if textrect.left < 0 or textrect.right > WIDTH:
                    MOVE[0] = -MOVE[0]  # Move ACROSS in the opposite Direction.
                if textrect.top < 0 or textrect.bottom > HEIGHT:
                    MOVE[1] = -MOVE[1]  # Move Horizontally in opp Direction.

                screen.fill(BLACK)
                screen.blit(text,textrect)


* So, we see that Freed.in really Rocks!


No Text, I want Picture.
========================

::


        import pygame
        import sys

        SIZE = WIDTH, HEIGHT = 398,390

        def main():
            pygame.init()
            pygame.display.set_caption("Escher")
            screen = pygame.display.set_mode(SIZE)

            picture = pygame.image.load('Drawing-hands.jpg').convert()
            picturerect = picture.get_rect()

            while True:
                for event in pygame.event.get():
                    if event.type == pygame.QUIT:
                        sys.exit()
                screen.blit(picture, picturerect)
                pygame.display.flip()

        if __name__ == '__main__':
            main()

Difference in Pygame?
=====================

* Minimal. Dont you agree?
* After the image.load class, it is basically a rectangle of pixels.
* And you operate with those colored rectangles.
* So, instead of the Text movement, can your image move? Ofcourse, Why not?

Good Tutorial by a Programmer
=============================
* Tutorial-1_
* Tutorial-2_
* Tutorial-3_

.. _Tutorial-1: http://lorenzod8n.wordpress.com/2007/05/25/pygame-tutorial-1-getting-started/
.. _Tutorial-2: http://lorenzod8n.wordpress.com/2007/05/27/pygame-tutorial-2-drawing-lines/
.. _Tutorial-3: http://lorenzod8n.wordpress.com/2007/05/30/pygame-tutorial-3-mouse-events/
