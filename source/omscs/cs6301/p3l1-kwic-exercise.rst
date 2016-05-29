.. title: P3L1 KWIC Exercise 
.. slug: P3L1 KWIC Exercise 
.. date: 2016-05-27 23:47:20 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

P3L1 KWIC Exercise
==================

01 - Software Architecture
--------------------------

To get a feel for software architecture, we will do an exercise first described in a paper by David Parnas, which is
linked on the class resources page.


The exercise asks you to come up with four different architectures that address the same problem.


The problem is to design a program that produces a Key Word in Context index, also called a KWIC index.


02 - Key Word in Context
------------------------

A KWIC index system accepts as input a sequence of text lines.


Each line is a sequences of words and each word is a sequence of characters.


You can think of the lines as containing titles, something like titles.


A line may be circularly shifted by removing its first word and appending it to the end of the line.


Thus, a line consisting of four words will have four circular shifts, including the original.


The idea being, that we can index into the list of lines using each of the words that comprise the line.


The quick index system outputs a listing of all the circular shifts of all the lines in alphabetical order of the key
word used to shift the line.


The idea is that if you want to look up any of those titles, you can use any of the words that comprise the title to
find it


03 - Example of Circular Shifts
-------------------------------

For example, if the original title is Gone With the Wind, a good Atlanta title to, to deal with, then there are then
there are circular shifts for it, for them, one for each of the words in the title.


And we've indicated them here by underlining the word that we're shifting.


So we have Gone with the Wind, and with the Wind Gone, and the Wind done Gone, no, the Wind Gone with.


Okay, and the Wind Gone with the.


And if we wanted to look up using any of those words we could because now we've indexed on it.


And when we alphabetize it, we have the one starting with gone and then the the and the wind and with.


04 - Example with Multiple Titles
---------------------------------

Of course, the value of doing the quick index is if we have more than one title, and here's an example with three
titles.


Beyond Gone with the Wind, we have War and Remembrance and The Winds of War.


Let's see how that looks.


05 - KWIC Exercise
------------------

Here's a solution to that example with three titles.


And note that we have in doing this, we have left out unimportant words like and, and of, which are sometimes called
stop words.


And that we have rotated the output so that all the key words line up in a column.


Okay. And when quick indexes are actually published, you can see them look like this and you can just go down the column
to find the appropriate word.


And so we have, in this case, six lines in our output.


We've removed the stop words from the, from the index list and, and then alphabetized according to the key word.


06 - Diagramming KWIC Quiz
--------------------------

And so, here's our, here's our exercise.


Assume that you had to implement quick.


Or, more accurately, to design and implementation of it quick.


And to start doing that, you want to break it up into pieces.


I realize this is a small problem and maybe doesn't really warrant having pieces, but assume that you want to break it
up into component pieces, okay, and we're going to represent the architecture you come up with as, with a diagram called
a box and arrow diagram.


And the boxes are going to correspond to the pieces or components that you come up with.


And shoot for something like three to five or six, different, different pieces, components, okay.


And come up with a label for each one of those components.


After you've done that, decide how the comp, components are going to communicate.


And [COUGH] have line between two boxes saying how it's going to communicate.


And in particular there's two typical kinds of communication.


One is a flow of control, typically A calling B or A passing control to B and the other is a sort of data, data
communication that is that one component uses the data in another in another component.


Indicate in your diagram which kind of communication, whether it's a data communication or it's a flow communication,
control flow communication, and you can do that by using different line style or whatever, or wanting a textural label.


And the trip of the exercise is I want you to come up with at least two solutions.


>> Okay. >> Okay?


And so take, take a minute and see if you can't sketch out a couple of box and arrow diagrams.


>> Do I need to be worried about assigning words to talk about the relationships between the boxes and arrows?


>> So there's only going to be two kinds of relationships.


Okay, there's going to be, think of A calls B.


Okay?


And so you could just have one kind of line a solid line with an arrowhead indicating that and the other is, A uses the
data in.


Okay, you can think of that as a dash line or something like that.


Okay?


07 - Diagramming KWIC Quiz Solution
-----------------------------------

So why don't you tell me about your first, first solution.


What components do you have?


>> Sure. So I started with five components, and then I added one towards the end because I realized I might need a
distinction for this component.


So I have a line, and lines consist of words.


So there's two components I have.


And, and in- >> So, so you have a component that holds the data for lines?


>> Yes. >> And a component that holds the data for words?


>> Yes. >> Okay.


Go ahead.


That have index, which is this object that holds all of our titles, which consist of lines and nodes.


I guess, actually, I don't, I think titles may not be necessary.


I feel like I'm saying the same thing.


The index consists of all of our lines.


>> So the index, the word index could either be a verb or a noun.


So this is, this, you're thinking of it as a data structure?


>> Yes.


>> Go ahead.


>> And then I have a, a system which contains this index of all of our lines, and then it also contains, or also uses
our passes control to a circle or like a shifter that will shift those lines around.


>> Okay, well, which of the components is responsible for doing the sorting?


>> Okay, so I've worked that out.


I don't have one.


>> Okay, so one other one.


>> Mm-hm.


>> And so, the, the operation here would be the system passing over control to the, well, tell, tell me how it would
work?


What would be the, the steps?


>> So the system would pass control to the index, or it would use the index to aggregate through all of our lines, all
of our, yes, all of our lines that had multiple words in it.


And as it's going through each line circler would then circle it in all the different formations that the line could be
in so that the index will grow.


>> So the, the system is doing the calling into the data structure index to get a, get out particular pieces, it then
passes those to the circular shifter?


>> Yes.


>> Okay. And then a circular shifter produces some results that are then passed over to the sorter.


Okay.


And this order does its thing and presumably there's an input process at the start of this and there's an output process
at the end of this.


>> Yes.


Well the way you phrased one part, the circler doesn't necessarily have to know about this order.


So the circler its, I'm thinking its only job is rearrange the lines and then now you have this index all the different
arrangements in your lines.


That index could then just work with the sorter and the circler doesn't have to know about it.


>> Sure.


And now, what is it that breaks the file into lines and the lines into words?


>> I guess the, the system in this case would be the one that gets the file and then gives that off to the index or
populates the index initially.


08 - Components
---------------

So, it sounds as though what you have is the system component is responsible for causing the input to be read in,
causing it to be parsed into pieces getting storing those pieces into the line and word data structures, and organizing
index.


Okay? And then calling the circular ship to do his thing, and then ultimately calling the sorted view to do its thing.


Now sometimes when you put a lot of responsibility for organizing steps and behavior and algorithms inside of one piece,
you may want to break that piece into, into parts.


So, this particular solution is similar to


Parnas' approach which he called the Shared Data Decomposition.


Well, we're the system into components based upon the functions they compute.


And all components share access to the data, which is stored in, in, in memory.


So you have a component several data structure components which are then accessible to the circular sorter and to the
the circular shifter and, and to the sorter.


And this solution solutions like this typically contain some form of what's called a master controller routine, which
you have labeled as systems.


And it's responsible for invoking the others and knowing what steps are, are in the process and that the typically in a
situation like this, control flow dependencies, is, are organized or realized by function calls.


09 - Shared Data
----------------

And he has a, a diagram which has these pieces in it.


It's somewhat similar to yours and it differentiates between subroutine calls which are indicated here by the lines with
the arrowheads, the big arrowheads.


And accesses to the memory which are lines with the smaller arrowheads.


And he also breaks out system IO, that is the reading and the input and the writing and the output.


So that's solution number one.


Take a minute now and see if you can come up with another solution.


>> Okay, so for my second solution, I've tried to decentralize some of this, because it sounded like the system was just
too, too heavy.


So, the system is still comprised of these components for parsing something to circle what we parsed, and sort and then
display.


So I have the parser, the circler, the sorter and the displayer, but


I'm trying to treat it as if it's like a running through a process in which the system doesn't have to negotiate
everything.


So [INAUDIBLE]. >> So, a step at a time?


>> A step at a time.


>> Okay. >> So we start with the parser.


The parser does its job, passes its output to the circler.


The circler, then, creates all of our different, you know, shifted versions of the lines.


That gets passed to the sorter.


And then, the sorter sorts it alphabetically and passes that on to the displayer.


>> Okay.


This sounds very similar to, what Parnas calls the pipe and filter, solution to things, so let's take a minute and look
at that.


10 - Pipe and Filter
--------------------

>> Well, it turns out that in doing image processing, okay? You put various filters along the way to to, to, to deal
with the processing of the images.


Also in situations where there's sensor data and you want to filter out noise of certain kinds, or select, you know,
certain frequency bands and so on. It's binary data but it's, it's going through a filtering process. So this, although
this does work in other situations it's most familiar and most used in situations where there's text files. So as you've
indicated, there's going to be filters having to do with circular shifting, and alphabetizing, and reading things in,
and putting things out. And one of the essential elements of this particular approach to solving things, is there's no
common data storage elements. We're just passing the solution along as we go.


11 - Pipe and Filter Diagram
----------------------------

And if we lay it out graphically, it looks like a pipe and filters.


The filters are the components along the way and the pipes are the little lines connecting them.


And, and, and this, this form, will indeed, solve the problem and yet it's much different than the previous one.


Well, Parnas also laid out two other solutions, which I want to briefly describe to you and they're probably many more.


>> Is there a problem necessarily because the pipe and filter doesn't have any central storage location that we're not
keeping that data?


Do we need to have good like logging systems, for instance, if we use that type of approach because the data isn't
persistent, maybe like it would be with a shared data model?


>> Well, okay, so


I haven't really laid out what the requirements of the problem are, okay?


And even in the shared data solution, that's in memory and it's going to go away when the process is over.


Now, we could imagine adding in or being more explicit about what the requirements are and whether we need to persist
them, okay.


And let's, let's come back to that in a couple of minutes.


>> Okay. >> Okay?


First I'd like to go over a couple of other solutions that Parnas proposes.


The next one to consider is called the Abstract Data Type or


ADT solution and this is breaking the system into components based upon important data structures.


So when we had the shared memory solution, that was breaking things into components based upon functions and likewise,
the pipe and filter was more breaking it into functions.


Here we're thinking in terms of the data first.


We're going to hide the represent, representations of those datas behind abstract interfaces.


That is we have a function called interface to it and how exactly we store this stuff away is all hidden from the other
components.


The components holding the data, of course, are also going to have some operations available to them.


In a sense, this is a precursor to an object oriented approach.


It's not, it was, it was first developed before object oriented languages became popular but many of the features that
ADTs have, have been incorporated into object oriented solutions to things


12 - Abstract Data Types
------------------------

In the ADT solution, we're going to have components for lines for characters, we're even going to treat the circular
shifter, instead of being a verb, it's going to be the circular shifts data structure and there's an operation for
computing the circular shifts.


And similarly for the alphabetized versions of things.


So we try to make everything into a data structure, the components into data structure, and then have operations for
computing the values in that data structure.


We have input components, like before, output components like before, and a master controller that invokes the other
components.


13 - Abstract Data Type Diagram
-------------------------------

In the diagram, we have the master controller invoking the inputs and outputs.


But the other communication is based upon more or less a need to know when the output needs some value, to be produced
it looks to it's source which is the alphabetic.


Alphabetizer or the alphabetized shift component.


And it looks to the circular shift component, which looks to the information that was stored during the parsing process.


14 - Implicit Invocation
------------------------

Parness' other solution is a little bit more subtle.


Now, in this case we're going to coordinate the communication between the components using a technique called
registration broadcast.


Components requiring services which, we're going to call clients, express interest in state changes in components
providing them which we'll call servers.


And that requesting notification is called a registration process.


When a server component announces that something, detects that something has been changed and announces it, it's going
to announce it to all the registered clients and that's going to be broadcast.


In this particular approach, servers don't know the identities of the clients.


The clients called them and said, call me back, but I don't know who you are that I'm calling.


And the uni, unit of notification here is the event.


We have essentially the same components as before, it's just that their mode of interaction has changed, and, and is now
implicit invocation based upon something happening.


15 - Implicit Invocation Diagram
--------------------------------

The diagram is similar to the diagram we just saw, except now some of the arrows are going in different direction to
indicate when, when the various components are being notified about the events that are there.


So now we have four solutions, and we, we might ask the question why do we need four solutions.


That's an excellent question and it depends upon ultimately how, how this particular program, this particular solution
is going to be used.


16 - Shared Data Approach Quiz
------------------------------

To get us there, let's think for a moment about the strengths and the weaknesses of the various approaches.


17 - Shared Data Approach Quiz Solution
---------------------------------------

I think one advantage that we may have is because all of the different parts are sharing the memory, sharing the data.


The porting may be easier, or like the interplay between components might be easier, but it seems like maintaining any
kind of change for the system in the long run is going to be more difficult than if you had the components kind of
isolated and the functionalities isolated.


>> So, [COUGH] we have shared data, it's all in memory.


That's going to be quite simple for all the components to get out the information.


It's also going to be very efficient.


Okay.


There's no there's no function calls involved in getting that data, you just go and get the data, okay.


On the other hand, if we wanted to change the way that that data is represented, every one of the components would
break, all right, because they all have to know how to get the data out.


So we have a plus with respect to efficiency and simplicity, and we have a negative with respect to resilience to
changes in representation.


18 - Evaluation
---------------

With respect to the three other solutions, we have advantages and disadvantages as well.


As far as the ADT, Abstract Data Type solution, it's very good, as far as maintainability and reuse.


Those particular components could be used in other applications by just, just plucking them out.


Remember, they've hidden away details.


On the other hand because things are hidden away you have to invoke them through function call interfaces which might be
more expensive, so you might pay a price in performance.


With respect to implicit implication, okay it has also maintainability advantages.


If you change the representation because the, the, the clients and the servers don't know much about each other you only
have to change them in one place.


You don't have to change change the others, which also facilitates reuse.


On the other hand, because it's implicit invocation and you don't know who you're talking to a lot of times, it's
sometimes difficult to think about or control what's going on.


And if you had to do some kind of debugging it might be tricky to know, you know, which of the components was
responsible for some kind of problem.


Also, as with the ADT solution, because you have these more or less abstract interfaces between things there may be a
performance hit.


With respect to pipe and filter, pipe and filter is very intuitive, easy to think about.


It's also easy to reuse because each of the filters along the way, you can plunk out and put into another, another
solution.


On the other hand if we wanted to make changes, such as making the system interactive pipe and filter wouldn't work at
all.


It, it's going to stream things, stream things through. also, it's not particularly space efficient because you have no
no place for you to store the data, which means you might have multiple copies of that data floating around as you're
processing.


So, each of the particular solutions has advantages and disadvantages, and in any particular sit, situation you want to
look at what's important to you.


Is performance important?


Is memory footprint important?


And, pick a solution that has the particular advantages that you need and avoids the particular disadvantages that might
bother you.


19 - Enhancements Quiz
----------------------

Another consideration is what's going to happen next.


If you're building a system and you've done a good job and that system is successful, you're customers are going to want
more.


Fact of life.


They're going to want enhancements and you can't really anticipate very well in advance what those enhancements are.


Okay?


If you could, then you could build your system in the first place so that it already had the enhancements in there,
okay?


So as another little quiz here see if you can list three ways in which this particular quick indexing tools might be
improved.


Three, three kinds of enhancements that you can imagine the customers wanting.


20 - Enhancements Quiz Solution
-------------------------------

So, I think, I guess in today's day and age, somebody, a lot of customers I could see wanting some kind of GUI interface
to be able to see this index.


>> Okay.


>> And then also, if we're going to have a GUI, there needs to be a smart, intuitive way to search through what we've
just sorted, the keywords that we've just sorted.


And, I think finally we want to a way to have that data persist.


So if we wanted to add more titles later, remove some titles out, because they're outdated or something then supporting
that as well.


>> We certainly wouldn't want to have to go through the whole parsing, sorting, cer, shifting process, anytime anybody
want to be using this.


>> Mm-hm. >> Okay.


So, in fact, there's a lot, there, there are all these needs and there's lots more.


For example it may be the case that the form of the input changes over time.


People might want to have input that if we're talking about titles, comes out of some bibliographic databases in a
different format.


We might want to use, re-use some of these components in other applications.


That's, that's a, a form of, of evolution as well.


We might want to for performance reasons, or, or other reasons change the processing algorithm, so that we do the
shifting of lines as they're read in or we wait until, doing the shifting until they're all read in.


We might want to shift lines on demand we might want to use an incremental rather than a batch sort.


That is, have some kind of sorted pre-structure that we add each title to as it comes in rather than when you get them
all in and do a sort.


You might want to add new functionalities such as we indicated before, in terms of stop words and eliminating those.


We might want to support deletions, like, like you mentioned.


We might want to use external stores, that is along the lines of persistence we might imagine the database on disc that
holds these either in their original format or in some partially processed format.


We might want to change the data representation.


Imagine that we are moving to a different library to support our our in-memory storage.


And we, so we might need a new representation of the lines and, and so on.


Variety of changes.


And the question then is, of the various approaches to the architectural breakdown of things, which ones are resilient
to which changes?


If you could anticipate the changes coming in, you could pick an architecture that, if not already able to provide that
particular change would be able to easily adapt to that change.


21 - Reusability Quiz
---------------------

So let me posit a hypothetical here.


Which of the four styles you think would be able to deal with a change having to do with the reusability of the
components?


22 - Reusability Quiz Solution
------------------------------

>> For the components to be reused, and potentially shifted, like you can shift their order around, or plug-and-play, it
sounds like a pipe and filter solution would be best for that.


>> Sure you can take any one of those filters and plug them into another application and as long as it had a single
input and a single output and it was line oriented ASCII or ASCII characters you can you can imagine very easily very
easily using it.


23 - Data Change Resilience Quiz
--------------------------------

Well, how about this, which of the four styles would be least able to cope with a change having to do with a different
data representation?


24 - Data Change Resilience Quiz Solution
-----------------------------------------

With the shared data model, because everything is being shared by all the components, and you're kind of pre-assuming
what it's going to look like, the data format, any change to that is going to cause a widespread change throughout your
entire system.


>> Sure. And I gave that one away before a little bit.


But whenever you have shared assumptions, if you violate an assumption, everybody that depended on that particular
assumption is broken.


25 - Deletion Quiz
------------------

And which if the four styles would be best able to cope with the change having to do with this interactive deletion of
titles.


26 - Deletion Quiz Solution
---------------------------

I'm not sure after like, I can't think definitively for any of the, the types where it may be more difficult for that
change to happen.


>> Think about adding an operation into into the architecture to do the deletion.


Is there one architecture which would be easy to find a place to do that deletion?


>> With the, the abstract data type solution, because we have these well defined interfaces and what they can do, if all
we need to do is add a delete operation to a particular, I guess, interface within that system, the ADT model seems to
support, will be able to support that type of change.


>> And it had a line data instructor right there, a line ADT.


>> Mm-hm. >> Just an operation to delete a line.


Okay? >> Right.


>> It goes into a single place and because of the abstract interface, nobody else depends upon that operation taking
place.


27 - Lessons
------------

So to take away from this, the bottom line, is that there are a variety of different architectural styles that can be
used to solve the same design problem.


And, in order to figure out which one to use you should be aware that each style has it's advantages and disadvantages,
and depending on the particular requirements, changes you have to deal with, you can pick the one that's best suited for
your particular situation.


