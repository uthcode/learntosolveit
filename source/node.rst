Knockout Progress
=================

http://nodeguide.com/beginner.html

http://nodejs.org/docs/v0.4.4/api/all.html

.js files are interpreted as JavaScript text files, and .node files are
interpreted as compiled addon modules loaded with dlopen.

A module prefixed with '/' is an absolute path to the file. For example,
require('/home/marco/foo.js') will load the file at /home/marco/foo.js.

A module prefixed with './' is relative to the file calling require(). That is,
circle.js must be in the same directory as foo.js for require('./circle') to
find it.

Without a leading '/' or './' to indicate a file, the module is either a "core
module" or is loaded from a node_modules folder.

Signal Events
function () {}

Emitted when the processes receives a signal. See sigaction(2) for a list of
standard POSIX signal names such as SIGINT, SIGUSR1, etc.

All streams are instances of EventEmitter.

File I/O is provided by simple wrappers around standard POSIX functions. To use
this module do require('fs'). All the methods have asynchronous and synchronous
forms.

Regex in node
-------------

  if (/[^\w_\-^!]/.exec(nick)) return null;


Links
-----

https://github.com/joyent/node/wiki/Projects,-Applications,-and-Companies-Using-Node

https://github.com/ry/node_chat

https://github.com/cmpolis/Apples-and-Oranges

https://github.com/joyent/node/wiki

https://github.com/haxd/scriptable-node-irc-bot


https://github.com/StanAngeloff/node-paperserve

