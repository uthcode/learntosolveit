# files_count_lines_large_file.py - 30-08-2015 08:13

CHUNK_SIZE = 8192 * 1024

def count_lines(file_path):
    count = 0
    with open(file_path, 'rb') as fh:
        while True:
            buffer = fh.read(CHUNK_SIZE)
            if not buffer:
                break
            count += buffer.count('\n')
    return count

def main():
    print(count_lines('./files_count_lines_large_file.py'))

if __name__ == '__main__':
    main()
