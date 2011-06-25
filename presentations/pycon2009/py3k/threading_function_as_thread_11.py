import thread

def athread(stuff):
    print "I' am a real boy!"
    print stuff

thread.start_new_thread(athread, ('Argument',))
