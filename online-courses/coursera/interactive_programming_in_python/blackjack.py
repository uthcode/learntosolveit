# Mini-project #6 - Blackjack

import simplegui
import random

# load card sprite - 949x392 - source: jfitz.com
CARD_SIZE = (73, 98)
CARD_CENTER = (36.5, 49)
card_images = simplegui.load_image("http://commondatastorage.googleapis.com/codeskulptor-assets/cards.jfitz.png")

CARD_BACK_SIZE = (71, 96)
CARD_BACK_CENTER = (35.5, 48)
card_back = simplegui.load_image("http://commondatastorage.googleapis.com/codeskulptor-assets/card_back.png")    
player_hand = ["initialized player_hand"]
dealer_hand = ["initialized dealer_hand"]
deck = ["initialized deck"]

# initialize some useful global variables
in_play = False
message = "Testing Testing Testing"
score = 0

# define globals for cards
SUITS = ('C', 'S', 'H', 'D')
RANKS = ('A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K')
VALUES = {'A':1, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9, 'T':10, 'J':10, 'Q':10, 'K':10}


# define card class
class Card:
    def __init__(self, suit, rank):
        if (suit in SUITS) and (rank in RANKS):
            self.suit = suit
            self.rank = rank
        else:
            self.suit = None
            self.rank = None
            global message
            message = "Invalid card: "+str(suit)+str(rank)
          
    def __str__(self):
        return self.suit + self.rank

    def get_suit(self):
        return self.suit

    def get_rank(self):
        return self.rank

    def draw(self, canvas, pos):
        card_loc = (CARD_CENTER[0] + CARD_SIZE[0] * RANKS.index(self.rank), 
                    CARD_CENTER[1] + CARD_SIZE[1] * SUITS.index(self.suit))
        canvas.draw_image(card_images, card_loc, CARD_SIZE, [pos[0] + CARD_CENTER[0], pos[1] + CARD_CENTER[1]], CARD_SIZE)
        
# define hand class
class Hand:
    def __init__(self):
        self.cards = []
        # replace with your code

    def __str__(self):
        # replace with your code
        if len(self.cards) > 0:
            reading_cards = []
            
            for i in range(len(self.cards)):
                reading_cards.append(str(self.cards[i]))
            return str(reading_cards)
        else:
            return str(self.cards)
        
    def add_card(self, card):
        self.cards.append(card)

    # count aces as 1, if the hand has an ace, then add 10 to hand value if it doesn't bust
    def get_value(self):
        hand_value = 0
        ace_test = False
        for i in self.cards:
            hand_value += VALUES.get(str(i.rank))
            if i.rank == 'A':
                ace_test = True
        
        if ace_test == False:
            return hand_value
        else:
            if hand_value + 10 <= 21:
                return (hand_value + 10)
            else:
                return hand_value

    def busted(self):
        pass	# replace with your code
    
    def draw(self, canvas, p):
        for i in self.cards:
            n = self.cards.index(i)
            self.cards[n].draw(canvas, [ p[0] + n * 83, p[1]])
        
# define deck class
class Deck:
    def __init__(self):
        # Reference on list comprehensions: http://carlgroner.me/Python/2011/11/09/An-Introduction-to-List-Comprehensions-in-Python.html
        self.cards_in_deck = [ Card(suit, rank) for suit in SUITS for rank in RANKS]
        
    # add cards back to deck and shuffle
    def shuffle(self):
        random.shuffle(self.cards_in_deck)

    def deal_card(self, hand):
        hand.add_card(self.cards_in_deck[len(self.cards_in_deck)-1])
        self.cards_in_deck.pop((len(self.cards_in_deck)-1))
    
    def __str__(self):
        display_deck = []
        for i in self.cards_in_deck:
            display_deck.append(str(i))
        return str(display_deck)
 
#define event handlers for buttons
def deal():
    global outcome, in_play, player_hand, dealer_hand, deck, message, score
    if in_play == True:
        # Hitting the "Deal" button while hand is in play results in decrementing
        # the score.
        score -= 1       
    in_play = True
    outcome = ""
    deck = Deck()
    deck.shuffle()
    player_hand = Hand()
    dealer_hand = Hand()
    for i in range(2):
        deck.deal_card(player_hand)
        deck.deal_card(dealer_hand)
    message = "Hit or Stand?"     
    # Creates player and dealer hands and deals two (2) cards each

def hit():
    global message, in_play, score
    if player_hand.get_value() < 21:
        deck.deal_card(player_hand)
        
        if player_hand.get_value() > 21:
            message = "You have busted."
            in_play = False
            score -= 1
    else:
        message = "You've already busted!"
       
def stand():
    global message, in_play, score
    in_play = False
    if player_hand.get_value() > 21:
        message = "You've already busted!"
    else:
        while dealer_hand.get_value() < 17:
            deck.deal_card(dealer_hand)
        
        if dealer_hand.get_value() > 21:
            message = "Dealer busts. You win."
            score += 1
        else:
            if player_hand.get_value() <= dealer_hand.get_value():
                message = "Dealer wins."
                score -= 1
            else:
                message = "You win."
                score += 1

# draw handler    
def draw(canvas):
    dealer_hand.draw(canvas, [100, 200])
    player_hand.draw(canvas, [100, 400])
    canvas.draw_text(str(message), (225, 375), 22, "Yellow")
    canvas.draw_text("Blackjack", (100, 100), 40, "Blue")
    canvas.draw_text("Dealer", (100, 175), 30, "Black")
    canvas.draw_text("Player", (100, 375), 30, "Black")
    canvas.draw_text("Score: "+str(score), (370, 100), 30, "Black")
    
    if in_play == True:
        #drawing back of card over dealer's first card to hide dealer's first card while player's hand in play.
        canvas.draw_image(card_back, CARD_BACK_CENTER, CARD_BACK_SIZE, (100 + CARD_CENTER[0], 200 + CARD_CENTER[1]), CARD_BACK_SIZE) 
    
# initializing the frame
frame = simplegui.create_frame("Blackjack", 600, 600)
frame.set_canvas_background("Green")

#create buttons and canvas callback
frame.add_button("Deal", deal, 200)
frame.add_button("Hit",  hit, 200)
frame.add_button("Stand", stand, 200)
frame.set_draw_handler(draw)

# deal an initial hand

# get things rolling
frame.start()
deal()
