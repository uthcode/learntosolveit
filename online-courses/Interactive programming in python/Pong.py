# Implementation of classic arcade game Pong

import simplegui
import random

# initialize globals - pos and vel encode vertical info for paddles

WIDTH = 600
HEIGHT = 400       
BALL_RADIUS = 20
PAD_WIDTH = 8
PAD_HEIGHT = 80
HALF_PAD_WIDTH = PAD_WIDTH / 2
HALF_PAD_HEIGHT = PAD_HEIGHT / 2
LEFT = False
RIGHT = True

# Paddle positions and velocities
paddle1_pos = [0,PAD_HEIGHT]
paddle2_pos = [0,PAD_HEIGHT]

paddle1_vel = 0
paddle2_vel = 0

ball_pos = [WIDTH/2,HEIGHT/2]
ball_horizontal = random.randrange(6, 12)
ball_vertical = random.randrange(3, 9)
ball_vel = [ball_horizontal,ball_vertical]

ball_left = ball_pos[0] - BALL_RADIUS
ball_right = ball_pos[0] + BALL_RADIUS

ball_top = ball_pos[1] - BALL_RADIUS
ball_down = ball_pos[1] + BALL_RADIUS

score1 = 0
score2 = 0


# initialize ball_pos and ball_vel for new bal in middle of table
# if direction is RIGHT, the ball's velocity is upper right, else upper left
def spawn_ball(direction):
    global ball_pos, ball_vel, score1, score2
    global ball_horizontal, ball_vertical
    ball_horizontal = random.randrange(4, 6)
    ball_vertical = random.randrange(3, 4)

    ball_pos = [WIDTH/2,HEIGHT/2]
    if direction == RIGHT:
        ball_vel = [ball_horizontal,-ball_vertical]
    else:
        ball_vel = [-ball_horizontal,-ball_vertical]
    


# define event handlers
def new_game():
    global paddle1_pos, paddle2_pos, paddle1_vel, paddle2_vel  # these are numbers
    global score1, score2  # these are ints
    score1 = 0
    score2 = 0
    paddle1_vel = 0
    paddle2_vel = 0
    direction = random.choice([RIGHT,LEFT])
    spawn_ball(direction)
    

def draw(c):
    global score1, score2, paddle1_pos, paddle2_pos, ball_pos, ball_vel
    global paddle1_vel, paddle2_vel
    global ball_left, ball_right, ball_top, ball_down
    global ball_horizontal,ball_vertical
 
        
    # draw mid line and gutters
    c.draw_line([WIDTH / 2, 0],[WIDTH / 2, HEIGHT], 1, "White")
    c.draw_line([PAD_WIDTH, 0],[PAD_WIDTH, HEIGHT], 1, "White")
    c.draw_line([WIDTH - PAD_WIDTH, 0],[WIDTH - PAD_WIDTH, HEIGHT], 1, "White")
    
    # reverse direction on top and bottom
    
    if ((ball_pos[1] - BALL_RADIUS) <= 0):
        ball_vel[1] = -ball_vel[1]
        
    if ((ball_pos[1] + BALL_RADIUS) >= HEIGHT):
        ball_vel[1] = -ball_vel[1]
    
    # ball hits the paddle.
    
    if (ball_pos[0] - BALL_RADIUS) <= 0 and (paddle1_pos[0] < ball_pos[1] < paddle1_pos[1]):
        ball_horizontal = ball_horizontal + (0.1 * ball_horizontal)
        ball_vertical = ball_vertical + (0.1 * ball_vertical)
        ball_vel = [ball_horizontal,ball_vertical]
    
    if (ball_pos[0] + BALL_RADIUS) >= WIDTH and (paddle2_pos[0] < ball_pos[1] < paddle2_pos[1]):
        ball_horizontal = ball_horizontal + (0.1 * ball_horizontal)
        ball_vertical = ball_vertical + (0.1 * ball_vertical)
        ball_vel = [-ball_horizontal,-ball_vertical]

    ball_pos[0] += ball_vel[0]
    ball_pos[1] += ball_vel[1]
    
    if (ball_pos[0]) < 0:
        score2 += 1
        spawn_ball(RIGHT)
    if (ball_pos[0]) > WIDTH:
        score1 += 1
        spawn_ball(LEFT)

        

    # draw ball
    c.draw_circle(ball_pos, BALL_RADIUS, 2, "Red", "White")

    
    # update paddle's vertical position, keep paddle on the screen

    if paddle1_pos[0] < 0 and paddle1_vel < 0:
        paddle1_vel = 0
        
    if paddle1_pos[1] > HEIGHT and paddle1_vel > 0:
        paddle1_vel = 0
        
    if paddle2_pos[0] < 0 and paddle2_vel < 0:
        paddle2_vel = 0
        
    if paddle2_pos[1] > HEIGHT and paddle2_vel > 0:
        paddle2_vel = 0

    paddle1_pos[0] += paddle1_vel
    paddle1_pos[1] += paddle1_vel
    
    paddle2_pos[0] += paddle2_vel
    paddle2_pos[1] += paddle2_vel   
    
    
    # draw paddles
    c.draw_line([0, paddle1_pos[0]],[0,paddle1_pos[1]], PAD_WIDTH*2,"WHITE")
    c.draw_line([WIDTH, paddle2_pos[0]],[WIDTH, paddle2_pos[1]], PAD_WIDTH*2, "WHITE")
    
    # draw scores
    c.draw_text(str(score1), [WIDTH/4,HEIGHT/6], 60, 'Blue')
    c.draw_text(str(score2), [3.0*WIDTH/4,HEIGHT/6], 60, 'Blue')
                
        
def keydown(key):
    incr = 10
    global paddle1_vel, paddle2_vel
    if key == simplegui.KEY_MAP["up"]:
        paddle2_vel -= incr
    if key == simplegui.KEY_MAP["down"]:
        paddle2_vel += incr
    if key == simplegui.KEY_MAP["w"]:
        paddle1_vel -= incr
    if key == simplegui.KEY_MAP["s"]:
        paddle1_vel += incr
        
   
def keyup(key):
    incr = 6
    global paddle1_vel, paddle2_vel
    if key == simplegui.KEY_MAP["up"]:
        paddle2_vel -= incr
    if key == simplegui.KEY_MAP["down"]:
        paddle2_vel += incr
    if key == simplegui.KEY_MAP["w"]:
        paddle1_vel -= incr
    if key == simplegui.KEY_MAP["s"]:
        paddle1_vel += incr


# create frame
frame = simplegui.create_frame("Pong", WIDTH, HEIGHT)
frame.set_draw_handler(draw)
frame.set_keydown_handler(keydown)
#frame.set_keyup_handler(keyup)
frame.add_button("restart", new_game, 150)


# start frame
new_game()
frame.start()
