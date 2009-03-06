import pygame
pygame.init()
pygame.display.set_mode((800, 600))
pygame.display.set_caption("Who Slides Wins!")

#Picture Game Initialization
num_of_squares_x = 3
num_of_squares_y = 4
width = 800
height = 600

image = pygame.image.load("picture.jpg")
image_scaled = pygame.transform.scale(image, (width, height))
original = image.convert()

blank_surface = pygame.Surface((width, height))
blank_surface.fill([0,0,0])

chop_width = width/num_of_squares_x
chop_height = width/num_of_squares_y

sprite_group = pygame.sprite.Group()

new_sprite = None

for top_left_x in range(0, width, chop_width):
    for top_left_y in range(0, width, chop_height):
        # Create a Surface with appropriate size to use the chop background.
        chop_surface = pygame.surface.Surface((chop_width, chop_height))
        # Blit a sub-section of original background with border area
        # of top_left_x, top_left_y, chop_width and chop_height
        chop_border = (top_left_x, top_left_y, chop_width, chop_height)
        chop_surface.blit(original,(0,0), chop_border)
        new_sprite = pygame.sprite.Sprite(chop_surface,(800,600),chop_surface.get_rect())
        sprite_group.add((new_sprite))

while True:
    pygame.update()
