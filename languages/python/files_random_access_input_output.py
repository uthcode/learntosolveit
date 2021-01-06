def seek_and_read(file_name, buf_size, byte_number):
    with open(file_name) as f:
        f.seek(byte_number)
        buf = f.read(buf_size)
    return buf

def main():
    buf_size = 48
    byte_number = 6
    print(seek_and_read(
        './files_random_access_input_output.py',
        buf_size,
        byte_number))

if __name__ == '__main__':
    main()
