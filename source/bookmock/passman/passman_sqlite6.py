import sqlite3

db_filename = 'todo.db'


def main():

    with sqlite3.connect(db_filename) as conn:
        conn.row_factory = sqlite3.Row
        cursor = conn.cursor()

        cursor.execute("""
        SELECT name, description, deadline FROM project WHERE name = 'pymotw'
        """)

        name, description, deadline = cursor.fetchone()

        print "Project details for %s (%s) due %s" % (description, name, deadline)

        cursor.execute("""
        SELECT id, priority, status, deadline, details FROM task WHERE project = 'pymotw' ORDER  BY deadline
        """)

        print "\n Next 5 tasks:"

        for row in cursor.fetchmany(5):
            print "%2d {%d} %-25s [%-8s] (%s) " % (row['id'], row['priority'], row['details'], row['status'],
                                                   row['deadline'])


if __name__ == '__main__':
    main()
