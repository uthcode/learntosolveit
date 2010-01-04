import io
MSG = "That man is depriving a village somewhere of a computer Scientist."

f = io.StringIO(MSG)
with f:
    print((f.read()))
