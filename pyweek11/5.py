from pyglet.window import mouse
import pyglet

window = pyglet.window.Window()

@window.event
def on_mouse_press(x, y, button, modifiers):
    if button == mouse.LEFT:
        print 'The left mouse button was pressed.'
    if button == mouse.RIGHT:
        print 'The right mouse button was pressed.'


@window.event
def on_draw():
    window.clear()

window.push_handlers(pyglet.window.event.WindowEventLogger())
pyglet.app.run()
