import os
import sqlite3

db_filename = 'todo.db'
schema_filename = 'todo_schema.sql'

db_is_new = not os.path.exists(db_filename)


def main():

    with sqlite3.connect(db_filename) as conn:
        if db_is_new:
            print "Creating schema"
            with open(schema_filename, 'rt') as f:
                schema = f.read()

            conn.executescript(schema)

            print("Inserting initial data")

            conn.execute("""
        INSERT INTO project (name, description, deadline)
        VALUES ('pymotw', 'Python module of the week', '2010-11-01')
        """)

            conn.execute("""
        INSERT INTO task (details, status, deadline, project)
        VALUES ('write about select', 'done', '2010-10-03', 'pymotw')
        """)

            conn.execute("""
        INSERT INTO task (details, status, deadline, project)
        VALUES ('write about random', 'waiting', '2010-10-04', 'pymotw')
        """)

            conn.execute("""
        INSERT INTO task (details, status, deadline, project)
        VALUES ('write about sqlite3', 'active', '2010-10-17', 'pymotw')
        """)
        else:
            print("database exists. Assuming schema exists too!")


if __name__ == '__main__':
    main()

