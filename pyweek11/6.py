import pyglet

music = pyglet.resource.media('resources/music.ogg',streaming=True)
music.play()

pyglet.app.run()
