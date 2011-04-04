import pyglet

window = pyglet.window.Window()

@window.event
def on_key_press(symbol, modifiers):
    print 'A key was pressed.'

@window.event
def on_draw():
    window.clear()

pyglet.app.run()
