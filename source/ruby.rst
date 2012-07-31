Understanding Ruby Language
===========================

[] - empty array
[1, 2, 3, 4, 5, "woot"]
[1, 2, 3, 4, 5].append('woot')

<<< is a common way to add elements to the array too.

[1, 2, 3, 4, 5].map{ |i| i + 1}

Ruby aliases the method Array#map and Array#collect; they can used
interchangbly.

The Class#method syntax is the standard way to referring to Ruby methods and
you will see a lot of it in this book.

In Ruby, just like in real world everything is an object. To make things happen
in Ruby, one always puts oneself in the place of an object and then have
conversation with other objects telling them stuff to do.

Roleplaying the object at the moment is an integral part of Object Oriented
Programming.

No paranthesis is required for calling like in Python.

When talking to an object via its methods, it is possible to give it additional
information so it can give you an appropriate response.

This additional information is called the "arguments to a method." The name
"argument" makes sense if you stop to think about the fact that methods are the
paths of communication between objects.

Paranthesis is required when you are sending on object as an argument.

Boolean methods can just be suffixed with ?

Ruby makes an exception in its syntactic rules for commonly used operators so
you don't have to use periods to invoke them on objects.

This is a common pattern in Ruby - two different ways to do the same thing
where one remains consistent and the other changes the syntax to be more
programmer friendly.

Classes topic was followed by grouping objects - wonderful.

All Strings are instances of the Ruby String class which provides a number of
methods to manipulate the string. Now that you have successfully mastered
creating strings let's take a look at some of the most commonly used methods.

Do remember that placeholders aren't just variables. Any valid block of Ruby
code you place inside #{} will be evaluated and inserted at that location.
Isn't that very neat?

We've been using double quotes in all our string interpolation examples. A
String literal created with single quotes does not support interpolation.

The essential difference between using single or double quotes is that double
quotes allow for escape sequences while single quotes do not. What you saw
above is one such example. “\n” is interpreted as a new line and appears as a
new line when rendered to the user, whereas '\n' displays the actual escape
sequence to the user.

Are you getting the hang of the Ruby API? The previous three methods all ended
with a '?'. It is conventional in Ruby to have '?' at the end of the method if
that method returns only boolean values. Though it is not mandated by the
syntax, this practice is highly recommended as it increases the readability of
code.

Why's Poigant guide to Ruby
---------------------------


Poigant means that something is s so beautiful that tears shed from eyes. In
this case, the author says that Ruby code is so beautiful that tears will shed
from your eyes when you read it.

Yukihiro Matsumoto created Ruby in 1993 but I came to know about in the context
of a web development framework called Rails. This book, thankfully does not
teach you rails, but instead teaches you the Ruby Language, which in my opinion
is a greater aim to have.

Author cheerfully says that "Ruby" is the computer's language and we are the
translators for the world. Also goes about explaining the concepts in more
non-programmer approachable manner like "If variables and constants are nouns
then methods are verbs".

Here some important language related details that I learned from this book.

In ruby, if you want to call a method, just mention it's name. If you want to
send arguments to the method, send the arguments with the paranthesis of the
call, like method(arg1, arg2)

Ruby uses some punctuation such a exclaimations and questions to enhance the
code. Methods are attached to end of variable constants by dot. The special
Kernel methods do not require dot. Like require is a method on the Kernel class
and that one does not require a dot.  

    require "uri" instead of Kernel.require "uri"

Instance methods use dot "." Class methods use double-colon "::" and they are
attached to variables and constants.

    Door::new(:oak)

The variables that begin with "$" sign are globals. Instance variables start
with @sign.  Think of @ symbol as meaning attribute.

There are also @@ClassVariables.  Single @width of front door @@width will set
for everything that is a Door.

Any code that is surrounding a curly braces is a block. Curly braces can be
traded for do end and usually good if the code is longer than a line.

Block arguments are set of variables surrounded by |pipe| characters and
separated by commas. Block arguments are used at the begining of the block.

{ |x, y| x + y} The pipe characters are like a tunnel. The variables are passed
into this chute to the tunnel.

For list slices, two dots are used. If you find three dots, then the last digit
in the chain is included too.

There is a datatype called constants which start with an initial capital
letter, like Net:HTTP. Here Net is a constant.

Generally speaking everything in Ruby has a positive charge. nil and false drag
us down.  unless allows only negative charges.

print "something" if true unless false is used in ruby

"==" sign is also a method.

    if nil.==(true) { print "this would never see the light of the day!"}

The if statement does not take a do. it is if -> elif -> elif -> else -> end.

The irb command line tool is useful and has a lot of options.

    irb

The respond_to? method is really nice and I plead that you never forget that it
is there.

In Ruby, the Object is the very central of things. It is The Original.  The
angle bracket indicates inheritance in the below sentence.

    class Something < Object


The object heirarchy is something like this

    null
    Object
    Module
    Class
    Instances

Kernel is special kind of a module. You can find all about them by looking at the following in irb.

    p Class::superclass
    p Kernel.class
    p Module::superclass
    p Object::superclass

Modules are just an 'inn' it is not a self aware class.


    $: gives the path for the libraries and the interpreter.

There are lot of $ short-cuts just like perl syntaxes.

    %q for quoted strings
    %w for quoted words from an array.
    %x is for executing.

Regular Expressions are central part of the Ruby language too. You can use
regex from string methods like .gsub. If you are doing a match, then there is a
short-cut =~ available for match operator.

    =~ is a match method
    $& would give the resulant match string.

Just as "soemthing".match("some") would give a MatchData and then doing a
.to_s on that MatchData would give the string back.

.dup method will duplicate the class, but there is also .clone that can copy
the metaclass related methods and variables too.

The other important concepts in ruby was :symbols - which are like strings but
immutable and has very some unique properties.

For sending multiple arguments to the method you can pass \*args. Like
World.mystory(\*characters) would send all the characters to mystory in the
world.

The tab completion facility is provided in the irb 

    irb --readline -r irb/completion

There is also document browser, called 'ri' wherein you can look at any method
by doing.

    ri Class#method

The list of classes that ri knows about can be learned by doing

    ri -l
