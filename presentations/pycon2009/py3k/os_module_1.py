import os

TEST_UID = 1000  # set your user id
TEST_GID = 1000  # set your user's group id

def show_user_info():
    print('Effective User:  ', os.geteuid())
    print('Effective Group: ', os.getegid())
    print('Actual User:     ', os.getuid(),  os.getlogin())
    print('Actual Group:    ', os.getgid())
    print('Actual Groups:   ', os.getgroups())
    return


print('BEFORE CHANGE:')
show_user_info()

try:
    os.setegid(TEST_GID)
except OSError:
    print('Error: Could not change effective group. Re-run as root.')
else:
    print('CHANGED GROUP')
    show_user_info()


try:
    os.seteuid(TEST_UID)
except OSError:
    print('Error: Could not change effective user. Re-run as root.')
else:
    print('CHANGED USER')
    show_user_info()

