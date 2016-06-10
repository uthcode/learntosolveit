import sqlite3

db_filename = "todo.db"


def encrypt(s):
    print "Encrypting for %r " % s
    return s.encode("rot-13")


def decrypt(s):
    print "Decrypting %s" % s
    return s.encode("rot-13")


def main():

    with sqlite3.connect(db_filename) as conn:
        conn.create_function("encrypt", 1, encrypt)
        conn.create_function("decrypt", 1, decrypt)
        cursor = conn.cursor()

        # raw values
        print "Original values:"
        query = "SELECT id, details FROM task"
        cursor.execute(query)

        for row in cursor.fetchall():
            print row

        print "Encrypting"

        query = "UPDATE task SET details = encrypt(details)"

        cursor.execute(query)

        print "\n Raw encrypted values."
        query = "SELECT id, details FROM task"
        cursor.execute(query)

        for row in cursor.fetchall():
            print row

        print "\n Decrypting in query."

        query = "SELECT id, decrypt(details) FROM task"

        cursor.execute(query)

        for row in cursor.fetchall():
            print row

if __name__ == '__main__':
    main()


if __name__ == '__main__':
    main()
