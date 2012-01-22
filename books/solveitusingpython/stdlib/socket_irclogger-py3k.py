import socket
SERVER = 'irc.freenode.net'
PORT = 6667
NICKNAME = 'phoe6'  # REPLACE WITH YOUR USERNAME
CHANNEL = '#python' # CHANGE CHANNEL IF DESIRED

IRC = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

def irc_conn():
    IRC.connect((SERVER,PORT))

def send_data(command):
    IRC.send((command + '\r\n').encode('utf-8'))

def join(channel):
    send_data("JOIN %s" % channel)

def login(nickname, username='phoe6', password=None, realname='Senthil',
          hostname='freenode', servername='Server'):
    import getpass
    password = getpass.getpass('Enter password for %s:' % nickname)
    send_data("PASS %s" % password)
    send_data("USER %s %s %s %s" % (username, hostname, servername, realname))
    send_data("NICK %s" % nickname)

def part():
    send_data("PART")

irc_conn()
login(NICKNAME)
join(CHANNEL)
try:
    while True:
        buffer = IRC.recv(1024)
        msg = buffer.split()
        print(msg)
        if msg[0] == "PING":
            # answer PING with PONG, as RFC 1459 specifies
            send_data("PONG %s" % msg[1])
        if msg[1] == 'PRIVMSG':
            nick_name = msg[0][:msg[0].find("!")]
            message = ' '.join(msg[3:])
            print(nick_name.lstrip(':'), '->', message.lstrip(':'))
finally:
    part()
