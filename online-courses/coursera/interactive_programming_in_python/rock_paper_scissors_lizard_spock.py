# Rock-paper-scissors-lizard-Spock template

import random

# The key idea of this program is to equate the strings
# "rock", "paper", "scissors", "lizard", "Spock" to numbers
# as follows:
#
# 0 - rock
# 1 - Spock
# 2 - paper
# 3 - lizard
# 4 - scissors

# helper functions

def number_to_name(number):
    # fill in your code below
    if number == 0:
        name = "rock"
    elif number == 1:
        name = "Spock"
    elif number == 2:
        name = "paper"
    elif number == 3:
        name = "lizard"
    elif number == 4:
        name = "scissors"
    else:
        print("Invalid number")
        name = None
        
    return name
             
    
def name_to_number(name):
    # fill in your code below
    
    if name == "rock":
        number = 0
    elif name == "Spock":
        number = 1
    elif name == "paper":
        number = 2
    elif name == "lizard":
        number = 3
    elif name == "scissors":
        number = 4
    else:
        print("Invalid name")
        number = -1
        
    return number


def rpsls(name): 
    # fill in your code below

    # convert name to player_number using name_to_number
    player_number = name_to_number(name)

    # compute random guess for comp_number using random.randrange()
    comp_number = random.randrange(0, 5)

    # compute difference of player_number and comp_number modulo five
    
    difference = (player_number - comp_number) % 5

    # use if/elif/else to determine winner
    if difference == 0:
        winner = "It's a tie"
    elif difference == 1 or difference == 2:
        winner = "Player wins."
    elif difference == 3 or difference == 4:
        winner = "Computer wins."

    # convert comp_number to name using number_to_name
    computer_name = number_to_name(comp_number)
    
    # print results
    print("Player chooses %s" % name)
    print("Computer chooses %s" % computer_name)
    print(winner)

    
# test your code
rpsls("rock")
rpsls("Spock")
rpsls("paper")
rpsls("lizard")
rpsls("scissors")

# always remember to check your completed program against the grading rubric

