#! /ufs/guido/bin/sgi/python

# Module 'adv' -- text-oriented adventure game.


# Name a constant that may once appear in the language...

def return_nil(): return
nil = return_nil()


# Copy of string.split() (to avoid loading all of string.py)

whitespace = ' \t\n'
def split(s):
       res = []
       i, n = 0, len(s)
       while i < n:
               while i < n and s[i] in whitespace: i = i+1
               if i = n: break
               j = i
               while j < n and s[j] not in whitespace: j = j+1
               res.append(s[i:j])
               i = j
       return res


# Constants to name directions

N = 'north'
S = 'south'
W = 'west'
E = 'east'
U = 'up'
D = 'down'
NW = 'nw'
NE = 'ne'
SW = 'sw'
SE = 'se'


# Constants to name other commands

INVENT = 'invent'
LOOK = 'look'
BACK = 'back'
HELP = 'help'
GET = 'get'
PUT = 'put'


# Aliases recognized by the parser

alias = {}
alias['n'] = N
alias['s'] = S
alias['e'] = E
alias['w'] = W
alias['u'] = U
alias['d'] = D
alias['i'] = INVENT
alias['l'] = LOOK
alias['b'] = BACK
alias['take'] = GET
alias['drop'] = PUT


# Normalize a command, in place: truncate words to 6 chars, and expand aliases.

def normalize(cmd):
       for i in range(len(cmd)):
               word = cmd[i][:6]
               if alias.has_key(word):
                       word = alias[word]
               cmd[i] = word


# The Object class describes objects that the player can carry around.

class Object():
       def init(this, name):
               this.name = name
               return this
       def describe(this):
               print 'A', this.name + '.'
       def get(this, (player, room)):
               del room.objects[this.name]
               player.objects[this.name] = this
       def put(this, (player, room)):
               del player.objects[this.name]
               room.objects[this.name] = this


# The Player class embodies first person control.

class Player():
       # Set initial state, except current room.
       def init(self, initial_room):
               self.blind = 0
               self.here = initial_room
               self.prev = nil
               self.objects = {}
               return self
       # Read and execute commands forever.
       def play(self):
               self.here.casualdescribe()
               while 1:
                       self.move()
       # Read and execute one command.
       def move(self):
               next = self.here.parser()
               if next and next <> self.here:
                       self.prev = self.here
                       self.here = next
                       if not self.blind:
                               self.here.casualdescribe()
       # Print inventory.
       def inventory(self):
               if not self.objects:
                       print 'You aren\'t carrying anything.'
                       return
               print 'You are carrying:'
               for key in self.objects.keys():
                       self.objects[key].describe()
       # Go back to previous room.
       def back(self):
               if self.prev: return self.prev
               print 'You can\'t go back now.'
       # Get an object from the room.
       def get(self, name):
               if self.here.objects.has_key(name):
                       self.here.objects[name].get(self, self.here)
               else:
                       print 'I see no', name, 'here.'
       # Put an object in the room.
       def put(self, name):
               if self.objects.has_key(name):
                       self.objects[name].put(self, self.here)
               else:
                       print 'You have no', name, 'with you.'


# The Room class describes a generic room.
# Rooms with special properties are defined by derived classes
# that override certain operations.

class Room():
       # Initialize a featureless room.
       def init(here, name):
               here.seen = 0
               here.name = name
               here.exits = {}
               here.objects = {}
               here.description = []
               return here
       # Add an object to the room.  Used during initialization.
       def add(here, obj):
               here.objects[obj.name] = obj
       # Print a casual description.
       def casualdescribe(here):
               if here.seen:
                       print here.name + '.'
                       here.listobjects()
                       return
               here.seen = 1
               here.describe()
       # Print a full description, including all exits and objects seen.
       def describe(here):
               if not here.description:
                       print here.name + '.'
                       here.listexits()
               else:
                       for line in here.description: print line
               here.listobjects()
       # List exits.
       def listexits(here):
               there = here.exits.keys()
               if there:
                       if len(there) = 1:
                               print 'There is an exit leading',
                       else:
                               print 'There are exits leading',
                               for name in there[:-2]:
                                       print name + ',',
                               print there[len(there)-2], 'and',
                       print there[len(there)-1] + '.'
       # List objects
       def listobjects(here):
               if here.objects:
                       print 'I see:'
                       for key in here.objects.keys():
                               here.objects[key].describe()
       # Default parser.  Returns next room (possibly the same) or nil.
       def parser(here):
               cmd = here.getcmd(here.prompt())
               return here.decide(cmd)
       # Return default prompt string.
       def prompt(here): return '> '
       # Default input routine.  Returns a non-empty list of words.
       def getcmd(here, prompt):
               # Loop until non-empty command gotten
               # EOFError and KeyboardInterrupt may be caught elsewhere
               while 1:
                       line = raw_input(prompt)
                       cmd = split(line)
                       if cmd:
                               normalize(cmd)
                               return cmd
       # Default decision routine.  Override for room-specific commands.
       def decide(here, cmd):
               key, args = cmd[0], cmd[1:]
               if not args:
                       if key = N:             return here.north()
                       if key = S:             return here.south()
                       if key = E:             return here.east()
                       if key = W:             return here.west()
                       if key = U:             return here.up()
                       if key = D:             return here.down()
                       if key = NW:            return here.nw()
                       if key = NE:            return here.ne()
                       if key = SW:            return here.sw()
                       if key = SE:            return here.se()
                       if key = LOOK:          return here.look()
                       if key = INVENT:        return here.inventory()
                       if key = BACK:          return here.back()
                       if here.objects.has_key(key):
                               print 'What do you want to do with the', key+'?'
                       else:
                               print 'Huh?'
                       return
               if key = GET:
                       for arg in args:
                               player.get(arg)
                       return
               if key = PUT:
                       for arg in args:
                               player.put(arg)
       # Standard commands.
       def look(here):
               here.describe()
       def inventory(here):
               player.inventory()
       def back(here):
               return player.back()
       # Standard exits.
       def north(here):        return here.take_exit(N)
       def south(here):        return here.take_exit(S)
       def west(here):         return here.take_exit(W)
       def east(here):         return here.take_exit(E)
       def up(here):           return here.take_exit(U)
       def down(here):         return here.take_exit(D)
       def nw(here):           return here.take_exit(NW)
       def ne(here):           return here.take_exit(NE)
       def sw(here):           return here.take_exit(SW)
       def se(here):           return here.take_exit(SE)
       # Subroutine for standard exits.
       def take_exit(here, key):
               if here.exits.has_key(key):
                       return here.exits[key]
               print 'You cannot go in that direction.'
               return here


# Create the objects we know about.
# Object names begin with 'o_'.

o_lamp = Object().init('lamp')
o_python = Object().init('python')


# Subroutine to connect two rooms.

def connect(rm1, rm2, dir1, dir2):
       if dir1:
               rm1.exits[dir1] = rm2
       if dir2:
               rm2.exits[dir2] = rm1


# Create the rooms and connect them together.
# Room names begin with 'r_'.

r_front = Room().init('Front of building')
r_initial = r_front
r_front.description = [ \
       'You are standing in front of a large, desolate building.', \
       'Huge neon letters spell "CWI".  The "I" is blinking.', \
       'There are entrances north and west from where you are standing.', \
       ]

r_entrance = Room().init('Entrance')
r_entrance.description = [ \
       'You are standing in a small entrance room.', \
       'On the east side is a window to a reception room.', \
       'South is a door leading outside the building.', \
       'North is a large hall.' \
       ]

r_hall_s = Room().init('South of hall')
r_hall_s.description = [ \
       'You are standing at the south side of a very large hall.', \
       'There are doors leading west, southwest, south and southeast,', \
       'and a corridor leads east.', \
       'The hall continues to the north.' \
       ]

r_hall_n = Room().init('North of hall')
r_hall_n.description = [ \
       'You are stanting at the north side of a very large hall.', \
       'There are corridors leading west, northwest, northeast,', \
       'an elevator door north, and a door leading outside east.', \
       'There are stairs leading up, and the hall continues to the south.' \
       ]

r_reception = Room().init('Reception')

r_mail = Room().init('Mail room')

connect(r_front, r_entrance, N, S)
connect(r_entrance, r_hall_s, N, SW)
connect(r_hall_s, r_hall_n, N, S)
connect(r_hall_s, r_reception, S, N)
connect(r_hall_s, r_mail, SE, N)
connect(r_reception, r_mail, E, W)

r_aud_front = Room().init('Front of Auditorium')
r_aud_back = Room().init('Back of Auditorium')
r_aud_tech = Room().init('Technician\'s room in Auditorium')
r_aud_proj = Room().init('Projection room in Auditorium')

connect(r_aud_front, r_hall_s, E, W)
connect(r_aud_front, r_aud_back, S, N)
connect(r_aud_back, r_aud_proj, SE, N)
connect(r_aud_front, r_aud_tech, W, E)

r_floor1 = Room().init('First floor')
r_floor2 = Room().init('Second floor')
r_floor3 = Room().init('Third floor')

connect(r_hall_n, r_floor1, U, D)
connect(r_floor1, r_floor2, U, D)
connect(r_floor2, r_floor3, U, D)


# Drop objects here and there

r_aud_proj.add(o_python)
r_reception.add(o_lamp)

# Create an uninitialized player object.
# It is initialized by main(), but must be created here (as global)
# since some Room methods reference it.  (Though maybe they shouldn't?)

player = Player()


# Play the game from the beginning.

def main():
       x = player.init(r_initial)
       try:
               player.play()
       except (EOFError, KeyboardInterrupt):
               pass

main()
