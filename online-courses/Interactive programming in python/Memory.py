# implementation of card game - Memory

import simplegui
import random

# globals

numbers = []

cards_to_points = {}

closed = False
isopen = True
turns  = 0

opened = []

# helper function to initialize globals
def new_game():
    global numbers, turns, label
    turns = 0
    
    numbers = range(1, 9)
    numbers = numbers * 2
    random.shuffle(numbers)
    
    x = 0
    y = 100
    
    for i in range(0,16):
        cards_to_points[i] = [numbers[i], [[x, y-100], [x, y], [x+50, y], [x+50, y-100]], closed]
        x += 50
        
    label.set_text("Turns = %d" % turns)
     
# define event handlers
def mouseclick(pos):
    global cards_to_points, opened, label, turns
    x, y = pos
    position_number = int(x)/50
    card = cards_to_points[position_number]
    
    if card[2] == isopen:
        # do nothing
        return

    number = card[0]
    card[2] = isopen
    opened.append((position_number, number))
    
    if len(opened) == 2:
        # Set the turns every 2nd click
        turns += 1
        label.set_text("Turns = %d" % turns)
    
    if len(opened) == 3:
        # On the third exposed, check for pairing.
        
        first = opened[0]
        second = opened[1]
        
        first_position_number = first[0]
        first_number = first[1]
        
        second_position_number = second[0]
        second_number = second[1]
        

        if first_number == second_number:
            cards_to_points[first_position_number][2] = isopen
            cards_to_points[second_position_number][2] = isopen

        else:
            cards_to_points[first_position_number][2] = closed
            cards_to_points[second_position_number][2] = closed
            
        # Remove the first two.
        opened = opened[2:]
        

    
                        
# cards are logically 50x100 pixels in size    
def draw(canvas):
    for value in cards_to_points.values():
        num = value[0]
        position = value[1]
        is_open = value[2]
        canvas.draw_text(str(num), position[1], 100, "White")
        if is_open:
            canvas.draw_polygon(position, 1, "White")
        else:
            canvas.draw_polygon(position, 1, "White", "Green")

        

# create frame and add a button and labels
frame = simplegui.create_frame("Memory", 800, 100)
frame.add_button("Restart", new_game)
label = frame.add_label("Turns = %d" % turns)

# register event handlers
frame.set_mouseclick_handler(mouseclick)
frame.set_draw_handler(draw)

# get things rolling
new_game()
frame.start()


# Always remember to review the grading rubric
