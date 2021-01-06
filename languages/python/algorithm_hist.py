stmt = input()
words = stmt.split()
max_length = len(max(words, key=len)) # length of longest word
for cursor in range(max_length):
    for word in words:
        # max_length - cursor is position count
        if (max_length - cursor) <= len(word):
            print('*', end=' ')
        else:
            print(' ', end=' ')
    print()
