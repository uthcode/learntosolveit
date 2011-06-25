import argparse

parser = argparse.ArgumentParser(
            description = 'Manage servers',         # main description for help
            epilog = 'Tested on Solaris and Linux') # displayed after help
parser.add_argument('action',                       # argument name
            choices = ['deploy', 'start', 'stop'],  # three allowed values
            help = 'action on each target')         # help msg
parser.add_argument('targets',
            metavar = 'HOSTNAME',                   # var name used in help msg
            nargs = '+',                            # require one or more targets
            help = 'url for target machines')       # help msg explanation
parser.add_argument('-u', '--user',                 # -u or --user option
            required = True,                        # make it a required argument
            help = 'login as user')

print(parser.parse_args('-h'.split()))
