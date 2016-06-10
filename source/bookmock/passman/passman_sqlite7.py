import sqlite3
import sys

db_filename = 'todo.db'
project_name = sys.argv[1]


def main():
    with sqlite3.connect(db_filename) as conn:
        cursor = conn.cursor()
        query = "select id, priority, details, status, deadline from task WHERE  project = ?"

        cursor.execute(query, (project_name,))

        for row in cursor.fetchall():
            task_id, priority, details, status, deadline = row
            print "%2d {%d} - %-20s [%-8s] (%s) " % (task_id, priority, details, status, deadline)

if __name__ == '__main__':
    main()
