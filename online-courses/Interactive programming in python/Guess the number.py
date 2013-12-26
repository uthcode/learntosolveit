# template for "Guess the number" mini-project
# input will come from buttons and an input field
# all output for the game will be printed in the console

import simplegui
import random
import math

# initialize global variables used in your code

SECRET = -1
CHANCES = 0
LOW = 0
HIGH = 100


# helper function to start and restart the game

def new_game():
    global SECRET, CHANCES
    SECRET = random.randrange(LOW, HIGH)
    print("I have thought of a number between %d and %d" % (LOW, HIGH))
    CHANCES = int(math.ceil(math.log(HIGH-LOW+1, 2)))
    print("You have %d chances to guess it right" % CHANCES)

# define event handlers for control panel
def range100():
    global LOW, HIGH
    LOW = 0
    HIGH = 100
    new_game()

    
def range1000():
    global LOW, HIGH
    LOW = 0
    HIGH = 1000
    new_game()
    

def input_guess(myguess):
    # main game logic goes here	

    global CHANCES
    guess = int(myguess)

    print("Your guess was %d" % guess)
    
    CHANCES = CHANCES - 1
    
    if (guess > SECRET):
        print("That was higher. Please try again.")
   
    elif (guess < SECRET):
        print("That was lower. Please try again.")
        
    if (guess == SECRET):
        print("That was correct! You won!\n")
        print("Let's play again!")
        new_game()
        
    if (CHANCES == 0):
        print("You ran out of guesses!\n")
        print("No problem.Let's play once again.")
        new_game()
    else:
        print("You have %d chances remaining.\n" % CHANCES)
        
        
# create frame

frame = simplegui.create_frame("Guess the Number", 300, 300)

# register event handlers for control elements

frame.add_button("Range [0-100)", range100, 150)
frame.add_button("Range [0-1000)", range1000, 150)
frame.add_input("Enter Guess", input_guess, 150)

# call new_game and start frame
print("Let's play Guess the number.")
new_game()
frame.start()

# always remember to check your completed program against the grading rubric
