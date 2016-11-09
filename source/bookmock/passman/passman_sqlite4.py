import sqlite3

db_filename = 'todo.db'


def main():
    with sqlite3.connect(db_filename) as conn:
        cursor = conn.cursor()

        cursor.execute("""
        select name, description, deadline from project where name = 'pymotw'
        """)

        name, description, deadline = cursor.fetchone()

        print "Project details for %s (%s) due %s " % (description, name, deadline)

        cursor.execute("""
        select id, priority, details, status, deadline from task
        where project = 'pymotw' order by deadline
        """)

        print "\n Next 5 tasks:"

        for row in cursor.fetchmany(5):
            task_id, priority, details, status, deadline = row
            print "%2d {%d} - %-25s [%-8s] (%s) " % (task_id, priority, details, status, deadline)

if __name__ == '__main__':
    main()
