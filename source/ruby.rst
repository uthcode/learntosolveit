Understanding Ruby Language
===========================

[] - empty array
[1, 2, 3, 4, 5, "woot"]
[1, 2, 3, 4, 5].append('woot')

<<< is a common way to add elements to the array too.

[1, 2, 3, 4, 5].map{ |i| i + 1}


IRB session example. Look at the list de-referencing.

::

    1.8.7 :001 > a, *b = [1,2,3,4,5]
     => [1, 2, 3, 4, 5] 
    1.8.7 :002 > a
     => 1 
    1.8.7 :003 > b
     => [2, 3, 4, 5] 
    1.8.7 :004 > 


Ruby aliases the method Array#map and Array#collect; they can used
interchangeably.

The Class#method syntax is the standard way to referring to Ruby methods and
you will see a lot of it in this book.

In Ruby, just like in real world everything is an object. To make things happen
in Ruby, one always puts oneself in the place of an object and then have
conversation with other objects telling them stuff to do.

Role-playing the object at the moment is an integral part of Object Oriented
Programming.

No parenthesis is required for calling like in Python.

When talking to an object via its methods, it is possible to give it additional
information so it can give you an appropriate response.

This additional information is called the "arguments to a method." The name
"argument" makes sense if you stop to think about the fact that methods are the
paths of communication between objects.

Parenthesis is required when you are sending on object as an argument.

Boolean methods can just be suffixed with ?

Ruby makes an exception in its syntactic rules for commonly used operators so
you don't have to use periods to invoke them on objects. If you want to be
consistent, then you can invoke them as Kernel.method, but I do not see any
place where such an invocation is encouraged.

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

Poigant means that something is so beautiful that tears shed from eyes. In this
case, the author says that Ruby code is so beautiful that tears will shed from
your eyes when you read it.

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
send arguments to the method, send the arguments with the parenthesis of the
call, like method(arg1, arg2)

Ruby uses some punctuation such a exclamations and questions to enhance the
code. Methods are attached to end of variable constants by dot. The special
Kernel methods do not require dot. Like require is a method on the Kernel class
and that one does not require a dot.::

    require "uri" instead of Kernel.require "uri"

Instance methods use dot ".".
Class methods use double-colon "::" and they are attached to variables and constants.::

    Door::new(:oak)

The variables that begin with "$" sign are globals. Instance variables start
with @sign.  Think of @ symbol as meaning attribute.

There are also @@ClassVariables.  Single @width of front door @@width will set
for everything that is a Door.

Any code that is surrounding a curly braces is a block. Curly braces can be
traded for "do ... end" and usually good if the code is longer than a line.

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

"==" sign is also a method.::

    if nil.==(true) { print "this would never see the light of the day!"}

The if statement does not take a do. it is if -> elif -> elif -> else -> end.

The irb command line tool is useful and has a lot of options.::

    irb

The respond_to? method is really nice and I plead that you never forget that it
is there.

In Ruby, the Object is the very central of things. It is The Original.  The
angle bracket indicates inheritance in the below sentence.::

    class Something < Object


The object hierarchy is something like this::

    null
    Object
    Module
    Class
    Instances

Kernel is special kind of a module. You can find all about them by looking at the following in irb.::

    p Class::superclass
    p Kernel.class
    p Module::superclass
    p Object::superclass

Modules are just an 'inn' it is not a self aware class::

    $: gives the path for the libraries and the interpreter.

There are lot of $ short-cuts just like perl syntaxes::

    %q for quoted strings
    %w for quoted words from an array.
    %x is for executing.

Regular Expressions are central part of the Ruby language too. You can use
regex from string methods like .gsub. If you are doing a match, then there is a
short-cut =~ available for match operator::

    =~ is a match method
    $& would give the resultant match string.

Just as "something".match("some") would give a MatchData and then doing a .to_s
on that MatchData would give the string back.

.dup method will duplicate the class, but there is also .clone that can copy
the metaclass related methods and variables too.

The other important concepts in ruby was :symbols - which are like strings but
immutable and has very some unique properties.

For sending multiple arguments to the method you can pass \*args. Like
World.mystory(\*characters) would send all the characters to mystory in the
world.

The tab completion facility is provided in the irb::

    irb --readline -r irb/completion

There is also document browser, called 'ri' wherein you can look at any method
by doing::

    ri Class#method

The list of classes that ri knows about can be learned by doing::

    ri -l

Ruby Tips
---------

$:.push File.expand_path("../lib", __FILE__)

$: is Ruby's load path, so it's in fact adding the a subfolder /lib of a folder
in which __FILE__ resides to this array, so that other files from this gem can
be required.

Ruby Symbols
------------

The Ruby_Newbie Guide to Symbols.

I'm writing this documentation for a specific audience: People who want to use
Ruby but are not Ruby veterans. Maybe they've used Ruby, maybe they haven't,
but they're not Ruby veterans. For the understanding of this specific audience,
this documentation is written with a minimum of Ruby specific content. Instead,
this documentation relies on general programming concepts. In the end, this
document will enable the Ruby Newbie to use symbols correctly, every time, so
that their code runs and does what they intend it to do. That is the sole goal
of this documentation.

Symbols can be viewed on many levels::

    * What do symbols look like?
    * What do they resemble in other languages?
    * How are symbols implemented?
    * What are symbols?
    * What are symbols not?
    * What can symbols do for you?
    * What are the advantages of symbols?

What do symbols look like?

This is the one area where everyone agrees. Most symbols looks like a colon
followed by a non-quoted string::

    :myname

Another way to make a symbol is with a colon followed by a quoted string, which
is how you make a symbol whose string representation contains spaces::

    :'Steve was here and now is gone'

The preceding is also a symbol. Its string representation is:

"Steve was here and now is gone"

::

    #!/usr/bin/env ruby
    puts :'I love Ruby.'
    puts :'I love Ruby.'.to_i

    [slitt@mydesk slitt]$ ./test.rb
    I love Ruby.
    10263
    [slitt@mydesk slitt]$

Symbols are immutable. Their value remains constant during the entirety of the
program. They never appear on the left side of an assignment. You'll never see
this::

    :myname = "steve"

If you were to try that, you'd get the following error message:

Symbols ARE used like this::

    mystring = :steveT
    Or this:
    mystring = :steveT.to_s
    Or this:
    myint = :steveT.to_i
    Or this:
    attr_reader :steveT

Now you at least know what we're talking about. Naturally, you still have
plenty of questions. Read on.

What do they resemble in other languages?

I'm not qualified to answer this question. In the long run, it doesn't matter.
Trying to answer this question at the start of your Ruby career can muddle the
issue.

What are symbols?

A Ruby symbol is a thing that has both a number (integer) representation and a
string representation.

Let's explore further using code.::

    #!/usr/bin/env ruby

    puts :steve
    puts :steve.to_s
    puts :steve.to_i
    puts :steve.class


One last point. In a single program, every occurrence of an identically named
symbol is actually the same object. This is not true of strings. Watch this.

::

    #!/usr/bin/env ruby

    puts :myvalue.object_id
    puts :myvalue.object_id
    puts "myvalue".object_id
    puts "myvalue".object_id

[slitt@mydesk slitt]$ ./test.rb

::

    2625806
    2625806
    537872172
    537872152
    [slitt@mydesk slitt]$


A Ruby symbol is a thing that has both a number (integer) representation and a
string representation.  The string representation is much more important and
used much more often.  The value of a Ruby symbol's string part is the name of
the symbol, minus the leading colon.  A Ruby symbol cannot be changed at runtime.
Multiple uses of the same symbol have the same object ID and are the same object.

Now let's inject just a little bit of Ruby specific terminology. Almost
everything in Ruby is an object, and symbols are no exception. They're objects.

What are symbols not?

A Symbol is Not  a String

A Ruby symbol is not a string. Ruby string objects have methods such as
capitalize, and center. Ruby symbols have no such methods:

A Symbol is not (Just) a Name
-----------------------------

The following illustrates the the use of a symbol as a name:

attr_reader :length

You're naming both a get method (length()) and an instance variable (@length).

However, symbols can be used to hold any sort of immutable string. It could be
used as a constant (but you'd probably use an identifier starting with a
capital letter instead. The point is, symbols are not restricted to just names.

That being said, symbols are used as names quite often, so although equating a
symbol to a name is not correct, saying symbols are often used to hold names is
a reasonable assertion.

A Symbol is an Object, but So What?
-----------------------------------

No doubt about it, a symbol is an object, but so what. Almost everything in
Ruby is an object, so saying a symbol is an object says nothing distinctive
about symbols.  What can symbols do for you?

A symbol is a way to pass string information, always assuming that.::

    The string needn't be changed at runtime.
    The string doesn't need methods of class String.

Because a symbol can be converted to a string with the .to_s method, you can
create a string with the same value as the symbol's string representation, and
then you can change that string at will and use all String methods.

A great many applications of symbols could be handled by strings. For instance,
you can do either the customary.

::

    attr_writer :length
    Or you can do the avant-garde:
    attr_writer "length"

Both preceding code statements create a setter method called length, which in
turn creates an instance variable called @length. If this seems like magic to
you, then keep in mind that the magic is done by attr_writer, not by the
symbol. The symbol (or the string equivalent) just functions as a string to
tell attr_writer what it should name the method it creates, and what that
method should name the instance variable it creates.

To see, in a simplified manner, how attr_writer does its "magic", check out
this program.

::


    #!/usr/bin/env ruby

    def make_me_a_setter(thename)
        eval <<-SETTERDONE
        def #{thename}(myarg)
            @#{thename} = myarg
        end
        SETTERDONE
    end

    class Example
        make_me_a_setter :symboll
        make_me_a_setter "stringg"

        def show_symboll
            puts @symboll
        end

        def show_stringg
            puts @stringg
        end
    end

    example = Example.new
    example.symboll("ITS A SYMBOL")
    example.stringg("ITS A STRING")
    example.show_symboll
    example.show_stringg

In the preceding, function make_me_a_setter is a greatly simplified version of
attr_writer. It does not implement the equal sign, so to use the setter you
must put the argument in parentheses instead of after an equal sign. It does
not iterate through multiple arguments, so each make_me_a_setter can take only
one argument, which is why we call it individually for both :symboll and
"stringg".

With the setters made, the application programmer can access the setters as
example.symboll("ITS A SYMBOL"). The following is the output of the program.

::

    [slitt@mydesk slitt]$ ./test.rb
    ITS A SYMBOL
    ITS A STRING
    [slitt@mydesk slitt]$

The following statements are handy in using (or not using) symbols:

    * A Ruby symbol looks like a colon followed by characters. (:mysymbol)
    * A Ruby symbol is a thing that has both a number (integer) and a string.
    * The value of a Ruby symbol's string part is the name of the symbol, minus the
      leading colon.
    * A Ruby symbol cannot be changed at runtime.
    * Neither its string representation nor its integer representation can be
      changed at runtime.
    * Ruby symbols are useful in preventing modification.
    * Like most other things in Ruby, a symbol is an object.
    * When designing a program, you can usually use a string instead of a symbol.
    * Except when you must guarantee that the string isn't modified.
    * Symbol objects do not have the rich set of instance methods that String objects do.
    * After the first usage of :mysymbol all further useages of :mysymbol take no
      further memory -- they're all the same object.
    * Ruby symbols save memory over large numbers of identical literal strings.
    * Ruby symbols enhance runtime speed to at least some degree.

Extend Ruby unit test to include assert_false
---------------------------------------------

::

    require "test/unit"

    module Test::Unit::Assertions
      def assert_false(object, message="")
        assert_equal(false, object, message)
      end
    end

    puts Test::Unit::TestCase.method_defined?(:assert_false)

    class MyTests < Test::Unit::TestCase
      def test_this_one_fails
        assert_false(false)
        assert_false(true)
      end
      def test_this_one_passes
        assert_false(false)
      end
      def test_this_one_passes_too
        assert(true)
      end
    end


Ruby Constructs
---------------
if __FILE__ == $PROGRAM_NAME


if __FILE__ == $0

__FILE__ is the magic variable that contains the name of the current file. $0
is the name of the file used to start the program. This check says “If this is
the main file being used…” This allows a file to be used as a library, and not
to execute code in that context, but if the file is being used as an
executable, then execute that code.


How does the self.something differ?


Ruby Gems
---------

Ruby Gems Reference - Master it.

http://docs.rubygems.org/read/chapter/10


Which is idiomatic ?
--------------------

$: << File.dirname(__FILE__)
$:.push File.expand_path("../lib", __FILE__)


Look at this
-------------

ree-1.8.7-2012.02 :001 > require 'murder'
 => true
ree-1.8.7-2012.02 :002 > require "murder"
  => false
ree-1.8.7-2012.02 :003 >

Understand Rake
---------------

Wondering how to run rake? bundle install; bundle exec rake -T. Super breezy.


1.8.7 :010 > if false
1.8.7 :011?>   elsif true
1.8.7 :012?>      p "true"
1.8.7 :013?>   end
"true"
 => nil 
1.8.7 :014 > if false
1.8.7 :015?>   elseif true
1.8.7 :016?>    p 'true'
1.8.7 :017?>   end
 => nil 
1.8.7 :018 > 

StormChaser

Pig
Oink
Scalding.
Kafka

StormChaser
Esper
Finagle


- How to create pants branch?
- What's pants, pants.pex and pants.multi
- There is pants.new but the executable is not there.
- export PANTS_DEV=1


svn.twitter.biz/maven/com/twitter/test-spiderduck-*
