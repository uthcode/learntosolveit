import sqlite3

db_filename = 'todo.db'

def main():

    with sqlite3.connect(db_filename) as conn:
        cursor = conn.cursor()

        cursor.execute("""
        SELECT * FROM task WHERE project = 'pymotw'
        """)

        print("Task table has these columns")

        for colinfo in cursor.description:
            print colinfo

if __name__ == '__main__':
    main()
