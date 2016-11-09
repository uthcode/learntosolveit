import sqlite3
import sys

db_filename = "todo.db"

id = int(sys.argv[1])
status = sys.argv[2]


def main():
    with sqlite3.connect(db_filename) as conn:
        cursor = conn.cursor()
        query = "UPDATE task set status = :status WHERE id = :id"
        cursor.execute(query, {"status": status, "id": id})

if __name__ == '__main__':
    main()
