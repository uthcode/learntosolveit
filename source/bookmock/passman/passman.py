#! python3

PASSWORDS = {'email': 'F7minlBDDuvMJuxESSKHFhTxFtjVB6',
             'blog': 'VmALvQyKAxiVH5G8v01if1MLZF3sdt',
             'luggage': '12345'}

import sys
import pyperclip


def get_password(account):
    if account in PASSWORDS:
        pyperclip.copy(PASSWORDS[account])
        print('Password for ' + account + ' copied to clipboard.')
    else:
        print('There is no account named ' + account)


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print('Usage: py pw.py [account] - copy account password')
        sys.exit()

    account = sys.argv[1]   # first command line arg is the account name
    get_password(account)


