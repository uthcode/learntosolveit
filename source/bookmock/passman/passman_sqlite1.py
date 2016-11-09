import os
import sqlite3

db_filename  = 'todo.db'

db_is_new = not os.path.exists(db_filename)

conn = sqlite3.connect(db_filename)

if db_is_new:
    print "Need to create a schema"
else:
    print "Database exists, assuming schema does too. exiting."

conn.close()
