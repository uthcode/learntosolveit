from argparse import ArgumentParser

parser = ArgumentParser()
parser.add_argument('--cgi', dest='cgi_handler',
                    action='store_true',
                    help='Run as CGI Server')
parser.add_argument('port',  action='store', default=8000, type=int, nargs='?',
                   help='Specify alternative port [Default:8000]')

args = parser.parse_args()
print args
