import sqlite3

db_filename = 'todo.db'


def main():
    with sqlite3.connect(db_filename) as conn:
        cursor = conn.cursor()

        cursor.execute("""
        select id, priority, details, status, deadline from task where project = 'pymotw'
        """)

        for row in cursor.fetchall():
            task_id, priority, details, status, deadline = row
            print "%2d {%d} - %-20s [%-8s] (%s)" % (task_id, priority, details, status, deadline)


if __name__ == '__main__':
    main()
