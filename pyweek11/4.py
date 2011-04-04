from pyglet.window import key
import pyglet

window = pyglet.window.Window()

@window.event
def on_key_press(symbol, modifiers):
    if symbol == key.A:
        print 'The "A" key was pressed'
    elif symbol == key.LEFT:
        print 'The left arrow key was pressed.'
    elif symbol == key.ENTER:
        print 'The enter key was pressed.'

@window.event
def on_draw():
    window.clear()

pyglet.app.run()
