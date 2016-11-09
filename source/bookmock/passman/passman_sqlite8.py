import sqlite3
import sys

db_filename = "todo.db"
project_name = sys.argv[1]


def main():
    with sqlite3.connect(db_filename) as conn:
        cursor = conn.cursor()

        query = """SELECT id, priority, details, status, deadline FROM task WHERE
project = :project_name ORDER BY deadline, priority"""

        cursor.execute(query, {"project_name" : project_name})

        for row in cursor.fetchall():
            task_id, priority, details, status, deadline = row
            print "%2d {%d} %-25s [%-8s] (%s)" % (task_id, priority, details, status, deadline)


if __name__ == '__main__':
    main()
