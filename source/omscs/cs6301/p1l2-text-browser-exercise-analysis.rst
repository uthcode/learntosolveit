.. title: P1L2 Text Browser Exercise (Analysis) 
.. slug: P1L2 Text Browser Exercise (Analysis) 
.. date: 2016-05-27 23:35:20 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

P1L2 Text Browser Exercise (Analysis)
=====================================


01 - Introduction
-----------------

Design is better learned than taught, this means that you actively try to solve design problems. And this course is
structured around a set of exercises that you should actively work on as you are watching them.


Let's jump right in and try to design a text browser application.


02 - Text Browser Exercise
--------------------------

Imagine the problem of browsing the text in a computer file. Imagine that no graphical user interface, GUI toolkit
supplies a single widget to do this.


Imagine that you would like to devise a cleanly structured solution.


03 - GUI Elements Quiz
----------------------

Assume that you do have a GUI library, such as Swing or


SWT, it just doesn't have a text browser widget in it.


From what atomic GUI components would you build your TextBrowser?


04 - GUI Elements Solution
--------------------------

Okay so for the GUI components of this text browser, we'll need some kind of window to display the text, and


I can foresee if the text is too large to fit in that window, we'll have a scroll bar that allows to, to move around in
the text document.


05 - FileManager
----------------

It turns out that we also need a component that's going to supply us the text.


Now, this isn't strictly in the GUI toolkit. But in order to make this thing work, we have to access the text somehow.
So we'll call that the file manager component. We're going to make some assumptions.


We're going to assume that you cannot hold the entire files contents in memory.


You're going to have to go to the disk to get it. And assuming you have at the operating level line oriented access to
the file. So in your, in your system libraries you have a way of, of reading the lines at anytime.


So you're going to need to have a module, that when requested can retrieve a limited length, consecutive sequence of the
file's lines.


And we're also going to assume we don't have to worry about opening the file or closing the file. Just the reading of
the file, supplying the lines.


06 - ViewPort
-------------

For your window component, we're going to call that a ViewPort, and you need to be able to use it, to display the
textual content graphically. And we're going to make some assumptions here, we're going to assume that the ViewPort
displays an inter, integer number of lines, and we're going to be, assume that it can be resized to be any length
between one and a 100 lines. And we're going to assume that all the text in the same font, is in the same font and has
the same point size. So these are simplifying assumptions to make the, make this particular exercise, you know, small
enough to fit in a lesson and also allow us to focus on just what the important issues are.


07 - ScrollBar
--------------

As far as the scroll bar is concerned, scroll bars are one graphical way of supplying numbers to other parts of an
application. Were going to use a traditional scroll bar in which there's it's going to be a vertical scroll bar and it's
going to have a movable part of it. That is the user can move a part called the handle which sits in a tray. So you can
move up and down, and we when we use the terms handle and tray to indicate that we can set, the user can set the
position in the file by by moving this handle up and down on the tray. The handle position denotes that part of the file
that should be displayed in the view port. So when you move it all the way up, you get the start of the file, and when
you move it all the way down, you get the end of the file. Also, the size of the handle in proportion to the size of the
tray denotes the portion of the file that is visible. So if all of the file contents fit into the viewport, you'd expect
the tray to be, filled up. And if we have a gigantic file, that in a very small window, we'd expect just a thin handle
to appear in the scroll bar.


08 - Use Cases
--------------

So we've, we've come up with three candidate structural elements.


Now, let's look at the behavioral side of this TextBrowser.


One way to get a handle on behavior is to imagine how the user will use the intended application. We call these
descriptions use cases.


09 - Use Cases Quiz
-------------------

So, what use cases can you imagine for this particular text browser application?


Can you list a few?


10 - Use Cases Quiz Solution
----------------------------

>> So you can resize the, resize the viewport. So those are the three primary use cases for this particular application
that we're going to consider.


11 - Analysis Model
-------------------

Once you have a handle on the major elements and behaviors you can begin to construct an analysis model. We'll use the
UML class-model diagram to express this analysis. A class-model diagram has rectangles for classes which we're going to
use the term components to indicate the structural elements. We're going to use classes to, denote the components.


Each rectangle is divided vertically into three compartments. One for the compartment name, at the top. One for its
attributes, in the middle.


And one for its operations, at the bottom. And then lines between the rectangles are going to denote relationships among
the components.


12 - Classes Quiz
-----------------

So to start the drawing of the model, why don't you come up with some classes to represent these three components and,
and put them into a drawing?


13 - Classes Quiz Solution
--------------------------

>> That, that we've chosen for those particular components.


14 - Operations
---------------

>> And, we could also specify, parameters, for those particular operations like, what's the size of the, viewport that
the user, would like to see?


Or, what's the position of the handle in the tray, when, when the user is using the scrollbar?


15 - Operations Quiz
--------------------

1


So can you add those those two operations into your diagram?


16 - Operations Quiz Solution
-----------------------------

Okay, so what do you have for the viewport?


>> So for the viewport, we've added our resize operation and we've left some space for, you know, this new position that
we'll be giving it.


>> Okay and what remember we said that the viewport is an, can hold an integer number of lines of text, so it makes
sense that we express the size in terms of the integer data type.


>> Okay. >> What's the return type of this operation?


>> I guess we could return the new verified size or like maybe a Boolean that it successfully executed.


>> Or nothing at all.


You know, in this case, we're performing the operation for its effect rather than its return value.


Okay, so we'll use the UML void type to indicate that there's no return value of interest to us here.


>> And I guess that I had a question in regards to, if we're going to list some types for the arguments and then also
the return values, but without getting too implementation specific.


We're going to use types that are UML-based and not language-based.


You know integers for Java, for instance, might be expressed a certain way.


It might be different than another language, right?


>> So we're not, we're not, we're not concerned with implementation data types, however, the particular tool that you
may use to actually draw this, might express the UML types in terms of programming language types.


So for example Argo UML does make exactly that choice and map the UML types to, to Java types.


But for purposes of doing an analysis model we're concerned with kind of the concepts and we're willing to abstract away
those implementation details.


>> Okay.


>> So how about the other use case in terms of moving the scroll bar handle?


So that's added to our rectangle for the scroll bar and


I indicated that there would be an argument for the new position of the handle.


And it-


>> And a, and a return type?


>> So void two.


>> Okay.


>> Based on our last one.


>> Now, conventionally the operations go in the lower, the, the lowest of the three compartments rather than, than the
middle.


But UML is actually flexible and you can have anything between one and number of, of boxes there and you can use them
however you want.


Your particular tool may, may differ.


There are some subtleties here which ultimately we're going to have to, to deal with.


The requirements didn't say only that the size of the viewport was an int.


It said that that int must be between 1 and 100.


So the UML diagramming notation doesn't allow us to express that, and we would have to use some other mechanism to to
get at that particular detail.


And also our GUI tool kit, when it's dealing with the scroll bar is, is probably going to return some kind of pixel
position.


But we're at, we're at the analysis stage and not the design stage, and so we're just going to, once again, assume that
we could deal with, with numbers between between 1 and, 1 and 100 as the particular position of the scroll bar handle.


17 - Visible Attributes Quiz
----------------------------

This kind of, of approximation or obstruction is typical, particularly at the analysis stage, and you should feel
comfortable with, with making these decisions so you can focus on the, the important details and avoid getting bogged
down in some of the nuances of things.


The third part of the class model is the attributes and what we'll do here is, as far as an analysis model is concerned
is we are going to try to capture in attributes, those parts of the application which the user can actually see.


And those are called percepts, and so we're going to try to understand what all the percepts are, and model each one of
those as an attribute. And so in this case, can you think of, for the viewport, what is, what it's percepts are?


18 - Visible Attributes Quiz Solution
-------------------------------------

>> So, if we were ultimately going to implement this thing, we'd have to make sure that that particular percept was
updated when we change to a file of a different size or we change the view port window size. So we have these four these
four percepts that are going to correspond to attributes.


And we can assign them to the particular components that we're, we're modeling.


19 - FileManager
----------------

So when we do this, we have, with the ViewPort, we have its height as a percept and we have its contents a, as a
percept. For the scroll bar, we have the position of the handle is a percept and also the size is a percept. But we
don't currently have any percepts for the FileManager, and in fact the user doesn't directly see the file manager.


However if we took our 40,000 foot view of the system, and, and we said what is external to the system and what is
internal to the system. The user is external to the system. Users, is, is the one that's going to be taken advantage of
the, of the system. But also, the file system itself, the operating system is external to the system and the operating
system is the one with which the FileManager component has to deal. So we're going to treat the operating system as an
external acto,r and the FileManager is going to interact with that external actor.


And as far as the FileManager is concerned, it has an attribute which is the document. Providing that as a, as a
resource to the rest of the system, and it's, it's, it's It also has an interface to this external actor, that is, the
actor has to provide that, that document. So we have an attribute there which is, the document which is a sequence of, a
sequence of lines.


20 - Relationships
------------------

So we have so far, developed a diagram that has some classes or components, some operations, and, and attributes which
correspond to the percepts.


That's the easy part really in doing the analysis.


The hard part is dealing with the relationships. These are the relationships among the components. In a UML analysis
model, you should be concerned with three types of relationships. Associations, aggregations, and generalizations.


21 - Relationships Quiz
-----------------------

One way of getting at these relationships is to determine which components have responsibilities for handling the two
user actions.


The use cases and corresponding operations can provide answers to these questions.


However, each of these events is just the first step in the text browser's response.


For each of these two actions, determine what subsequent events you would expect to see.


So if, so for example, if the user is resizing the window, or moving the scroll bar, not only do we expect the window
size to be different, or the scoll bar position to vary, but we want this, the rest of the application to respond
somehow.


So, can you lay out what other things you would expect to happen?


22 - Relationships Quiz Solution
--------------------------------

>> Ultimately, each of those responses represents a relationship between the, the corresponding components.


23 - Number of Lines Quiz
-------------------------

Let's start with the relationship between the viewport and the file manager.


So at any particular moment of time, we have a, a number of lines in the file, and we have a number of lines displayed.


What is the number of lines that are actually displayed in the Viewport as a function of the window size and the number
of lines in the file?


24 - Number of Lines Quiz Solution
----------------------------------

>> Okay, so of given the size of the, the number of lines in the file. [BLANK_AUDIO]


>> Okay. >> Okay? And we can't express this in the diagram.


We'll have to use some other mechanism and that mechanism is called OCL which is the Object Constraint Language.


This is a part of UML that's a textural part that allows us to more price, precisely express various of the requirements
that we have to deal. And we're going to have to kind of bring that into our, model in order to deal with this
particular situation. The fact that the number of lines shown depends on both the file size, and the viewport size,
indicates that there's a relationship between these two components. We call this the lines visible association. We can
show it's existence graphically with a label line between the two classes.


25 - LinesVisible Association
-----------------------------

1


It's in UML, it's an association.


2


We can't, as I said,


3 we can't express this entirely within the graphical notation.


4


We'll use UCL to do this, OCL to do this.


5


And later in the course we'll look more carefully at OCL.


6


For now, here's what the relationship looks like.


7


It says that as far as this particular association, the LinesVisible


8 association, is concerned, there's, a fact or there's an invariant


9 that must hold that the size of the viewports must be equal to the minimum


10 of the size of the file manager and the size of the, of the viewport.


26 - Another Association Quiz
-----------------------------

The lines visible association indicates that the contents of the viewport must come from the file manager, but it
doesn't really say what lines.


These, those lines are determined by the position of the scroll bar handle.


See if you can state in English what this relationship must be.


And, and here's a couple of hints for you.


We already know how many lines, we just, we just got that.


>> Right.


>> And so if we can come up with the first line that's displayed, okay?


>> Mm-hm. >> Then we can determine the rest of the lines that are displayed by just adding in the number of lines.


Okay? >> Right. >> So how would you, how would you say this?


27 - Another Association Quiz Solution
--------------------------------------

>> Okay. >> Okay? Ultimately, we would have to translate this into mathematics, or express the mathematics in OCL. But
for now our expectation is that that percentage of the way down in the tray indicates the percentage of the way down in
the file.


28 - Explanation
----------------

Determining the top line, top visible line and the number of lines together tells us which lines will be displayed.


This determination is based on the attributes of the viewport, its size, the file manager, its document size, and the
scrollbar, the handle positions.


Hence there is an association, a three way association, amongst all three components. You can also call that a ternary,
as opposed to binary, association.


Let's call this association displays, as in the view port displays the contents provided by the file manager and
determined by the scroll bar


29 - Displays Diagram
---------------------

1


In UML you can use a a diamond


2 to indicate associations that have more than two participants.


3


Here there's three participants.


4


It's the display's association, and we've added in the OCL that gets down to


5 this particular mathematical details as to what, what actually gets shown here.


30 - Handle Association Quiz
----------------------------

The final property we must describe has to do with the size of the handle in the scroll bar. So what is this particular
association as to the size of the handle and it's association with the, with the other components?


31 - Handle Association Quiz Solution
-------------------------------------

I tried to put a little mathematics into this to try to understand it.


So, say we have a document that's 1,000 lines long.


And our viewport is 100 lines high, high.


Then our handle would need to be one-tenth of the tray as we scroll.


So the size is dependent on that relationship between, how many lines can currently be displayed by the viewport, and
how many lines in total does the document have?


>> Kay, sounds, sounds good.


The size of the scroll bar handle with respect to the size of the scroll bar tray indicates the portion of the
document's lines provided by the file manager that are currently visible in the viewport.


We're going to call this the handle proportion association, and it's also a ternary association.


32 - HandleProportion
---------------------

1


Here's what it, what it looks like, and the OCL is provided as well.


33 - Subtleties
---------------

>> Okay. And in fact, if you go play around with actual web browsers out there, and, and with word processing editors
and so on, you can see both of these behaviors. However, if we're designing the application, we have to make the
position about which one of those two behaviors we actually intend that the, text browser to have. Okay. So, this
process of modeling has forced us into thinking about something, which we might not have otherwise thought about, which
is one of the, one of the the, the benefits of doing the modeling.


It forces you to think through subtleties of things.


34 - Summary
------------

This exercise has illustrated the construction of an analysis model for the text browser problem. We haven't yet begun
to solve the problem, which is what design is all about. To begin thinking about design ask yourself, what is the key
design question with which any implementation of the text browser must deal? We're not going to answer that question
right now, but we will come back to this a little while later, and maybe by that time you will have thought through what
it would take to actually to do a design here.


