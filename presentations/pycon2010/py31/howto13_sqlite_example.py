#!/usr/bin/env python3.1

import sqlite3
conn = sqlite3.connect('exampledb')
c = conn.cursor()

# Create table
c.execute('''create table stocks (date text, trans text, symbol text, qty real,
          price real)''')
c.execute("""insert into stocks values ('2006-01-05','BUY','RHAT',100,35.14)""")
conn.commit()
c.close()
