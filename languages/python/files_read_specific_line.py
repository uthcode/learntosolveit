import linecache


def get_line_from_a_file(file_path, line_number):
    return linecache.getline(file_path, line_number)


def main():
    file_path = './files_read_specific_line.py'
    desired_line_number = 10
    print get_line_from_a_file(file_path, desired_line_number)


if __name__ == '__main__':
    main()
