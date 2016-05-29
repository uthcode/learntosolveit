.. title: Geeks in Black- The Code Review 
.. slug: Geeks in Black- The Code Review 
.. date: 2016-05-27 23:33:20 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

===============================
Geeks in Black- The Code Review
===============================


01 - Introduction
-----------------

Ladies and gentleman, I am Agent B.of MIB with an important announcement.


Thousands of alien bugs have been invading our code.


The invasion threatens our flight navigation systems.


Our financial infrastructure and our ability to play Candy Crush. [MUSIC]


To fight back, MIB has invented a secret weapon.


The code review and assembled a crack team of reviewers gather in our headquarters in New York City. [NOISE] Gentlemen,
would you now introduce yourself to the public, first our moderator.


>> Hello, I am Moderator, sometimes also called the controller.


My name is 3.8.


I'm a professor in computer science, and they call me 3.8 because it took me 3.8 billion years to evolve.


>> Next, our Reader.


>> Hi, I'm the Reader, Dr. Bug.


They call me Dr. Bug because I smash bugs.


>> Here's our recorder.


>> Hi, I'm Crazy Bob.


They call me Crazy Bob because I'm crazy about Ada.


I'm the tech lead on our avionics project.


We delivered 1.4 million lines of safety-critical Ada code.


>> Next we have Inspector Fra Elbertus.


>> Hi, I'm Fra Elbertus.


I'm the friar of doom.


I was the originator of the sticky net virus when I consulted for one of those three letter government agencies.


You haven't heard of sticky net because it was so evil, they had to redo it and call it Stuxnet.


>> And our other inspector, Byte.Me.


>> Hi everyone my name's Byte.Me.


I used to have a back story, but I pseudo RN'd it years ago.


I like coffee, code and Reddit.


That's about it.


>> Finally, I will also be an inspector.


Now ladies and gentlemen, let me show you the first invasion site.


A key piece of software infrastructure called BlankCount.java. [MUSIC]


02 - Part 1
-----------

Now I will turn things over to 3.8 to lead the attack against these bugs.


>> Is everyone ready, Crazy Bob?


>> I am ready, sir.


>> Bite Me? >> Ready to go.


>> Ready to roll.


>> Doctor Bug? >> I was born ready.


>> Oh, excellent.


We are all ready here.


So, let us start.


>> If I could interject something before we begin [LAUGH] I just would like to say, before we started this project, I I
advised management that we wouldn't be having a lot of these core problems that we've got now if we just use data.


We're on job aid it would really, you know, it would solve a lot of our integration problems and all.


And I just wanted to make that clear, that I told them before we began this project that we should do it, and here we
are looking at jobs.


So, I just wanted to make that clear before we got started.


>> Well, I mean, with that, just trying to read this Baloney Code that this guy wrote is unbearable.


>> Well I think we should just, >> I am just sick to my stomach.


>> We should just proceed with the review probably.


>> Oh, well, okay.


>> Gentlemen, let me remind you that I'm the controller here. [LAUGH] Thank you very much for your advice.


Dear reader, Doctor Bug, please talk.


>> We start with two imports in the code.


The first one is an import to the java.io package, all the classes in the package, and there's the right semicolon right
after that.


And there's another importer, which is to java.lang.System, which is used for the io, and another semicolon, so this
looks fine.


>> So line one, line one is actually not good coding style, because you should never import you're polluting the
namespace.


So we should never import asterisk, we should only import the classes that we're actually using.


>> Well, I think it's okay, all right, if we need to use multiple ones.


Do you want to spell them all out.


>> But then you're polluting, you're bringing in all these names that we really don't need.


So, I think it should be, what?


Java. I think the only IO class, let's see InputStream.read, so we should have java.io.InputStream.reader.


>> I think you're, you're wasting space by doing this,


I mean this is, why is it there?


>> And thanks for telling us about the semicolons, that's a, a big help.


>> Yeah I figured.


>> Can I continue?


>> Yes, please continue.


>> So should I record that as defect or, or we don't believe that's a defect?


>> I think you should I, personally, I gotta,


I gotta echo Crazy Bob here because if we move to the next line here, purpose, we have the slash star here for comment
style and then further on down we're going to use the slash slash, some consistency would be nice.


>> So, I think we should record that as an error.


>> But let's move on.


>> That's bad style.


>> Sure, sure.


Okay, Crazy Bob will record it.


Dr. Bug?


>> Okay, fine. okay, then the main class starts, which is >> Before we do that, let me complain about line 2.


I don't believe you have to import anything from java.lang, right?


I believe java.lang comes in automatically.


>> I believe that's correct.


>> So that's a useless, that's a useless import.


>> Okay, fine, that's what my mentor told me that I was supposed to do but that's okay.


>> Okay, so then we start with the main classes.


>> Maybe we should reconcile this common issue, before we move on.


As brought up by me.


>> I think so.


>> I mean.


That, that's just.


Don't you have coding standards and which would include how to write comments in your, in your.


>> I do and it's usually, just stick with one and then that's the way it goes for the rest of the, the comments.


>> The slash-star has so much history with it.


You know, we want, we want to reflect the fact that this is a historical artifact.


>> I don't know if I agree I,


I think not only that, I'm not sure what constitutes getting its own white space like an extra line here.


We move down further maybe we come back to this but


I have a couple places that I marked that I just don't quite understand.


>> Maybe Bite me is saying, let's go one down and come back to this.


Doctor, Bug please continue.


>> Thank you.


03 - Part 2
-----------

The next line, line 6.


The main class starts, which is called BlankCount.


And [COUGH] after that there's two constants that are being defined.


And one is the blank the other one is a sentinel.


And then we move to the main, which is actually the main the main body of the class and also the main method for the
program.


Everything is included into a try catch block, and the first instruction is actually to initialize the
InputStreamReader, ISR, with a new InputStreamReader and takes the system in stream as a parameter.


>> So I believe on that line, there's also a problem because that violates code the interface rather than
implementation, so they actually have the implementation class on the left, left-hand side.


It should be declared as the ab-,. . as the abstract interface and then the concrete implementation on the right-hand
side with the new.


>> So, now, other people agree?


>> Yeah, I agree.


Yeah.


Bob’s right.


>> Okay then there’s the code declares two integers next and count, and next is going to be use the as the next
character in sentence, and count is going to be used to count the number of blank counters, which is the main goal of
the, of this class.


>> I'm glad you stopped telling us that there's semicolons at the end of each line.


It's that helps.


>> Well I think it's important, correct?


>> So before the semicolons though, shouldn't we initialize these values like we have the ISR variable or both?


>> [CROSSTALK] Yeah we should initialize. >> All right, go.


>> Should we decide whether to character or an int?


The comment says character.


>> That's true. >> [CROSSTALK] Operation says int.


>> Yeah, that, that's excellent to pick that up.


>> Yeah. >> That's that comment problem again.


If you'd done slash star, maybe you would had written it right the first time.


>> Should, should we go for comments on the right side of the?


Or should we put them above?


If they get their own line, maybe it'd help us read it better.


I don't know. I, this is, this is going back to, to line four up above.


I, I don't, I'm not quite sure when we, when we want them beside the code, when we want them above the code?


>> Well, there is nothing in the standard that we use in the company, but that's fine.


I mean, if you want to pick a, you know, a way to do it >> We could make a standard.


>> [CROSSTALK] That's fine. We can make a standard.


>> We can make a standard right now.


>> I'd like a standard, yeah, mm-hm.


>> So what's, what's the standard?


We going to go slash, slash all the way or slash star?


Slash star seems a little more robust.


We can, you know?


You don't have to use as many slash slashes.


Javadocs uses slash star kind of, that kind of structure when you do.


>> I thought it was kind of old fashioned but that's okay.


We can use slash star. >> What's wrong with old fashioned? [LAUGH]. >> [LAUGH].


>> Okay, Dr. Bud continue please.


04 - Part 3
-----------

Okay let me get back to where I was.


Okay, so we declared the two variables, and then there's two print lines the first one >> Excuse me did, did the
recorder correct the comments?


To make, make note of the errors in the comments that, that >> Slash asterisk should our new standard coding as well.


>> Yeah these easier being pointed out, that we should be, it's said that they're characters but they were declared as
integers.


>> For int next, it says next character is that it?


>> Yeah. >> Put a line through.


>> The implication is that you're confused about characters versus integers.


>> Mm-hm, even though the representation was also signed.


>> Okay so as I was saying there is two print statement, the first one prints to the user, enter a sentence ending with
a period, and the second one says, follow each character buy a return.


>> We have a typo.


>> Yeah, I guess, buy should not really be buy, >> And also probably, follow, should be capitalized, right?


I mean it's a separate sentence so you're trying to [COUGH] write it as a sentence.


>> Or it should be all on one line, because you're, you're breaking at interest and it's ending with a period oh, okay,
I see.


>> But it also, it's interesting,


Interest in it is ending with a period doesn't have a delimiter at the end where it's follow each character by a return
does have a delimiter.


>> Should that be, have a colon there?


>> It seems like we're really getting stuck on minor details.


>> I think so too, let's move on, let's move on back to Dr.


Bug, please continue.


>> So a character is, misspelled.


>> It's charcter.


>> Just making, I think it's making for bad user experience, we don't, we don't, you know >> Yeah, actually I think I
was just copy and paste in here from someone elses code, but that's fine.


Yeah, I think it's. [LAUGH] >> Is that what we do now?


Is we copy, copy from other people's [CROSSTALK].


>> Well, it's just this, you know?


This was [CROSSTALK].


>> Whose was it that we copied from?


>> It was part of a log, I mean, I think it was actually Crazy Bob's code, but [LAUGH] I could be wrong.


>> It wasn't my code because it's not in native. [LAUGH] >> Yeah. >> It was a native piece of code.


>> In fact, if we could just back go back and revisit, 13 and


14, you know, this initialization problem wouldn't even be occurring because you can't have uninitialized data in aid.


So if we'd actually done what we said, what I said originally, we wouldn't be having these problems.


>> You, you're absolutely right, I forgot about that.


Crazy Bob bring, brings up some excellent points, about this lousy code we're looking at.


>> I have to say, actually, I'm pretty sure that in Java, when you declare a lock of variable like this, it gets
initialized automatically to zero.


But I might be wrong.


>> That's the instance variables that are initialized, and the local variables are not initialized.


>> Okay, maybe I'm wrong then >> Even if there are automatically initialized, good code behavior would be that you
actually initialize them so everybody doesn't have to remember whether it works or not.


>> Well, just, you know, I was used to developing data, so that's reality.


>> Yeah [LAUGH].


>> Okay, let us continue Dr. Bug.


05 - Part 4
-----------

>> Okay, so after this there's a next gets the first character in the string using the read method.


Also in this case, suitably followed by a semicolon.


I hope that makes you happy.


>> Oh, I'm very happy with that.


>> That's great. And and then we print line in which we print this character that we just read.


>> Okay, so, for, for 19 should we?


This extra white space around next.


This kind of goes back to, to line ten where we have some extra white space between the two brackets for, for the
string.


Is there a, what do you want to do there?


We, we always want to have pad space around the functions, or the arguments into the function?


>> Yeah, I guess that's something the editor data, that's not much fine with, you know, doing it with all the spaces.


>> It's not consistent. [CROSSTALK]. >> Again, we need to have a standard of some kind.


>> I think so. >> It's obvious you don't have any kind of coding standards.


>> Yes. [CROSSTALK]. >> Most of this is copied code. [CROSSTALK].


>> Yeah, it was copy and paste.


So, so a hodgepodge of, of different styles.


>> So, this old one is kind of no, no empty spaces around those variables.


>> And the no copying of code from, from random forums online.


That might be a good idea.


>> Is that okay Dr. Bug from now onwards?


>> Isn't that, doesn't that mean we're going to have to re-code stuff that we might save energy by copying?


>> Well maybe if as long we're copying internal code that has the, the standard, the standard applies.


Maybe we need to write something that's a standard checker for our internal use on it.


>> [INAUDIBLE] Dr. Bug? >> Okay, so after this we enter into a while loop with the given condition.


And the, at that point once we get into the while looper we check if the next character that we read is a blank.


>> Actually, we have a problem here, we should be stopping when the next doesn't equal the sentinel, otherwise we're
just stopping maybe immediately.


Do we ever enter this loop?


>> Unless the first character is the [INAUDIBLE].


>> Our count, our count will be zero.


We're not going to count the blanks if we, because we want to stopiat a period, correct?


We're going to read the number of blanks in a sentence and stop.


At least that's how I'm reading it.


>> Oh, oh yeah sorry about that one.


Yeah I was coding in a hurry.


I'm sorry and it's yeah, you, you're right.


This should be the, the while next is not a sentinel.


And I, yeah and I have to apologize, because I kind of came through that when I was going through.


I should have looked at that more carefully while doing the reading.


>> Or maybe you just copied somebody's while loop and didn't even bother to check what it was about.


>> Well, in this case I think it's actually my fault so, sorry about that.


>> Oh. >> Cannot blame everything.


>> We're so happy you apologized.


>> Cannot blame everything on Bob.


>> If we could just for a second revisit every other thing we've talked about previously.


I just so, I'm supposed to be recording the severity, so


I assume all the severity of everything up til just now is minor.


Is everybody good?


And this is our first really major severity.


>> That sounds reasonable.


>> Defect. >> Mm-hm.


>> What are our severity levels?


>> Well, according to our little log here, we only have major and minors.


>> Okay. >> [LAUGH] >> So then, yeah, I would agree with that.


I, some, some of the things that were tried to put in between but we don't have an in between, so I think you've got it
right.


It's the best we can do with what we've got.


06 - Part 5
-----------

So then, I guess you know, this, there is a bug there definitely.


And then if next is equal to blank which is the character we want to count the count is incremented using the plus, plus
operator. [COUGH] Then we read the next character again using the read. function, the read method on on the stream.


And then it would print the character that we just read.


>> Should we really be printing all these characters on a new line every time?


Or do we want the sentence to actually look like the characters are one after another in a sentence?


>> You have to say that was not specified.


So I made that decision but.


It didn't sound like a very good decision.


I mean, you think you're going to have this, [LAUGH] this line of characters, vertical line of characters coming out
that you, then it's difficult for you to check if the sentence that I put in, that was the sentence, try to figure out
you know, if it actually caught them all and, and, and- [CROSSTALK].


>> Kind of drives-


>> Right now it's a vertical line of integers, it's not even characters.


>> Yeah, that's true.


>> So, it's-


>> Even worse.


>> Right. >> Yeah, you're right, okay.


Okay, okay, that's fine.


I didn't realize that, that was going to be printed as an integer.


You're probably right.


And so it should be really printed as a character. [CROSSTALK].


>> You didn't realize.


I mean, you never even ran your code once on your test.


>> I did run it I just, the input wasn't just that.


>> It's like students who appear in science class.


It just compile it doesn't work.


>> I mean, this is one of the advantages of- [CROSSTALK]. [LAUGH].


>> This is actually, you know, one of the advantages of inspection.


I mean, this code, is could just, part of a larger piece of code and so we're just reading it right now and didn't
really. [COUGH]. >> Go through a serious testing phase.


Yeah, I compiled. [COUGH].


>> To make sure there were no syntactic errors.


>> We can continue from here.


>> We can continue.


Thank you. [COUGH] Okay, so at this point-


>> We're going to get bite me to go see if he can compile it and see if it even compiles.


I'm not even sure if it compiled yet.


>> Well, it may have of compiled.


I can't remember.


The last time I checked I know it didn't work.


It didn't give us what we wanted.


>> It does compile though.


I mean I'm positive about that.


>> Okay, okay.


07 - Part 6
-----------

Okay. So now at this point that we exit from the loop, which means that we encounter the sentinel which is the, marks
the end of the, of the sentence. [CROSSTALK]. >> Are we guaranteed to exit?


>> Well-


>> You know, we'll, w'll have to fix the condition that we identified.


>> But assuming that we, we fixed it, what happens if last character is not a sentinel?


>> Well, we tell the user, right, that he should follow, that he should enter sentence, end it with the period.


>> That's right, the user are always right.


>> With their responsibility, right?


You have to take care of all the possibilities here.


>> Well, as you might recall on a keyboard and a computer, the period and the comma are right next to each other, and
frequently people punch the wrong one.


It's called a slip in, in the cognitive world, and they put a comma in and then this thing loops forever.


>> I was thinking, in fact, if there was an enda file without a, without a sentinel at the end.


>> Even better.


>> Yeah, I guess then what we'll get, an exception exit, right, and catching the exceptions, so.


>> Without printing anything out?


>> Well, you know, the, the user will figure out that they did wrong.


We gave them instructions.


I mean, I don't know.


If we want to account for all the possible behaviors, sure, I mean, just you know, let's agree to do that.


>> Hey, listen son, this is Aviaonic software we're building here and that means planes crash if we can't-


>> Sure. >> Characters in a sentence.


>> That's fine.


You've kind of been on my back the whole time, but that's fine.


I mean if, if you think we should account for the, for this thing.


We'll, we'll account for that.


Do you want to mark it down as as a problem?


>> We might send-


>> Crazy Bob, if you don't mind.


>> Maybe we need to send this guy back to the IT department.


>> I think we have read the point.


I think we have read the point.


Doctor Bug gets the point, right Doctor Bug?


>> Yeah. I, I get the point.


Yeah. There's no need to kind of reiterate every time like three or four times but, anyways.


Okay so where were, was I


08 - Part 7
-----------

Okay, we exit the loop and, well, I'll take into account, I guess, if there is a point or if there's not a period at the
end we might have an exception, we'll take that into account.


Then the, the code brings a new line, and then-


>> But for, for, for the 31, 31, the commenter, are we assuming that we were going to search something here with the,
the use of the word assert or is that just, is that a,-


Well I know it was more like a note for myself that the count is a a blanks because that is the conditions that should
be verified here,


I mean I might, may make that into an assert later on.


>> Weren't you for my own edification an amazing, these one, two, three, four, Four print lines in a row, tell me what
you're expecting to see coming out of each of those.


>> I'm just expecting to see well, some white space.


>> That's about it.


So the first one will be a blank plane.


>> Yeah. Just, you know, to kind of put some distance between the list of.


>> Okay, then the second one will.


>> Let's just say the number of blank.


>> Is.


>> Is, blanks is and then print the number of blanks.


>> Should be printing to a count.


>> Yeah, no, you're right, it should.


As I said, I mean, I was kind of kind of writing this in a hurry, and yeah, this should be, this should be count.


>> And, it would be on the next line.


>> Mm-hm. >> And, it would be on the next-


>> It won't be width contiguous with the text.


>> Yeah.


>> Well hold up that, that's [CROSSTALK].


>> No, actually no. [INAUDIBLE] >> Oh, I'm sorry, print.


>> [CROSSTALK] Couldn't we just combine all these into one. [CROSSTALK].


>> Yeah, I should probably, yeah. [CROSSTALK].


>> Couldn't we just combine all four of these into one? [INAUDIBLE].


>> Sure, we could use, you know, slash n and then, is slash n is >> Slash n.


>> [CROSSTALK].


>> Sure, yeah, we could use slash n.


Is that allowed in the kind of code standard that we use?


>> You just told me there weren't any standards and so, yeah.


>> This is just a little amusing.


>> [CROSSTALK] much of, yeah.


Mm-hm.


>> Okay, so this can be connected, concatenated in one line, maybe, I thought that this was going to improve
readability, but that's >> We don't have to use that.


>> Maybe that's not, that's not the case.


>> The other side of this, this paper.


>> We have an extra log sheet.


>> You going to run out of room?


>> I got it. >> Okay, because,-


>> I anticipated ahead that we would have many defects.


>> Well, obviously, that's been the case.


>> Maybe you're being too picky, but fine.


>> It looks like dogs barks, repetition precedes it. [LAUGH]. >> Well let's continue for now.


09 - Part 8
-----------

>> Do we mentioned that line 34 prints the wrong?


>> Yeah. >> It prints that. [CROSSTALK] Prints next to the [INAUDIBLE]. >> Yeah.


>> Yeah. >> Sorry. >> You need to make a note of that, though.


>> Can we put? >> Who's checking the the recorder?


>> [CROSSTALK] Crazy Bob. [INAUDIBLE] here?


Major, major, our majors are what we had the not equal to sentinel.


That needs to change.


>> Right. >> We're not checking for a period or have the exception.


>> We're printing every character on new line as an int.


>> Okay, that's pretty good.


>> There's questions about whether the loop even terminates in the network between the wrong variable.


>> Okay. I shouldn't catch, can, are we going to, you know, catch beyond its own line or catch comes after, you know,
on, on line 36 there.


Should, should we, is there, do we want to talk about a standard for that?


>> I personally like this style.


I mean, the, I think this is the, the new style or whatever.


I like this line.


This where the, the opening curly brace is on the same line and then the close curly brace on [INAUDIBLE].


>> Actually, Crazy Bob and I talked about that a lot and we thought that, that was a, a nice way to put the code.


And again, we wanted to define the standards as different we can do it in [INAUDIBLE].


>> Guess that mix-up coding were discussed between the two of you.


>> Just [INAUDIBLE].


>> That's interesting.


Well, we named-


>> We were talking about how ADA, you know, ADA doesn't even use these curly braces.


I mean, you, we could begins and ends and then it's really clear exactly where these blocks are beginning and ending.


We wouldn't having all these crazy Java problems that we've got.


>> Which you know Crazy Bob.


It's from pre-Civil War era.


So.


>> Yeah. >> We, you, you need, need to be careful when you listen to him.


You know, one thing that's bothering me.


I keep looking at this thing, is that here's a piece of code, you're claiming that you read it.


But there's no header in this code that says, you know, this is a Doctor Bug's code, the revision of the code.


Any of that kind of information, which is typical in, in software engineering, and we know who's it is, how it's
revised.


If other people been making new versions of it, we know who they are, what the dates of, of, of each revision, original
development art, et cetera.


None of that is in here.


>> So that ten years from now the maintainers can call you up in the middle of the night and, and ask you what you were
thinking?


>> Could the number of bugs in this code is clear- [CROSSTALK]. >> Right, no Java down here.


>> In this case it might be appropriate if you also put the sources of the different places you visited [INAUDIBLE] copy
and pasted code.


That might be.


>> Okay, that was just a minor.


I mean I really copy a coupled of things, not too much.


>> [CROSSTALK] Oh. Okay.


>> But that's sure.


I mean I, I-


>> Like the while statement that's incorrect.


>> Mm-hm.


Yeah. >> Yeah. >> Well, I think I told you before that the while statement is actually my mistake. [CROSSTALK].


>> The point has been made, very good to talk about continuity.


>> Okay.


So, at this point yeah.


That the cases.


>> We're going back to line 36,


I believe it's improper to catch just a generic conception.


You're supposed to catch the most specific catch you're actually expecting.


>> Generic catching, catching generic conceptions is just catching generic conceptions.


That's just to cover your behind kind of thing.


>> Yeah.


>> [CROSSTALK] Actually trying to catch IO exceptions.


I believe there should be IO exception to the rule. [COUGH]. >> Yeah I was just trying to be comprehensive, because you
know, this way an exception that happens will be caught.


>> Sure. >> We need an exit-able system without printing anything is also really bad.


I mean, we should be writing to the logger.


>> In the case of where the exception was raised.


>> Yeah, in the case where the exception was raised.


I'd call that, definitely, a major.


Both of them.


I don't know if my colleagues agree with that or not.


>> So, we need to catch specific, and then have a generic catch that follows?


Is that what we're saying?


>> We just catch the ones we were actually expecting.


>> What about the ones that we don't expect?


We're not, we won't get any information about those will we?


>> Well you know if we were using eta they have a catch all at the end that we could always. [CROSSTALK]. >> There. >>
Well enough with this eta stuff.


>> [LAUGH]. >> I think we are using Java and so we'll have to deal with that.


Again I think we should make that also part of the quoting standards.


10 - Part 9
-----------

Are we debugging code here or are we building coding standards?


Are we building coding standards or debugging code?


>> I dunno. It seems to me that I'm being blamed on a lot of things, that just you know, depending on the fact of having
a standard or not but it's [INAUDIBLE].


>> Research says building standards significantly reduces the number of errors in software.


And so, we should.


Make a note that there are no standards existing in this group, and that they ought to be done.


Here's some suggestions, but that's a bigger problem than what we're addressing here.


>> [COUGH] While you're starting it, let's continue it Doctor Vaughn.


>> At this point we just you know, there's just brackets to c lose catch statement And then the method, and then the
classes, and then that's it, the codings.


>> What is the exit status if everything runs correctly?


>> Oh, it just says it's fine.


>> Shouldn't we be setting an exit status of zero.


>> I think that's probably by default or something.


>> Is it? I don't know, I'm not so sure.


>> I don't know I thought it was by default.


That's what told me.


>> Yeah, but- [CROSSTALK]. >> That was for in our job.


So, you have to be. [LAUGH].


>> Well, while we're [COUGH] mention printing to a log.


Shouldn't we, for the, when we're printing the characters in the while loop.


Shouldn't that, isn't that debug information.


Does the user even need to see that?


They just really need to see the count, right?


Shall we be worried about what's being print to kind of the logger and then what's printed to standard out?


>> Well, I see that you're kind of changing the specs on me but yeah.


If there has to be a logger then yeah the model will have to change.


>> Well, it says right here, the purpose.


Count the number of blanks in a sentence.


>> Right, I know. >> It doesn't say a purpose.


Write out all of the things.


>> Hm. >> You know, as you're going along.


>> So is the comment wrong or the spec wrong?


>> Well, it's a, that's an excellent question.


I would say that the I believed what I read there.


But I could be incorrect.


>> Yeah, that's the spec I got.


>> Since this is a program without a specification.


I think he just invented it, you know, just. [CROSSTALK] So he said I need to do this.


He said, okay I can do that. [CROSSTALK] I can copy code from various places and hack this thing together.


>> This way it was nice for the users to see what [INAUDIBLE] but it doesn't have to be the case.


>> I don't know what kind of users you've been around.


>> Oh, you know, users that can put a period at the end of the sentence. [CROSSTALK].


We did and Dr. Bug, anything else for this?


>> That's sound perfectly good.


11 - Summary
------------

Crazy Bob will you please summarize all the bugs have you found?


>> All right. So, I'll read.


I'll read basically the type, the severity, the location and then the description.


So, this was wrong.


Minor, line one, don't import asterisk.


Wrong, minor, line two, useless import or useless import of .java.lang.


Stylistic minor, line 12.


Program to interfaces not implementations.


Missing minor.


Lines 13 and 14, no initialization of variables.


Stylistic minor 13 and 14 integer versus character.


Style minor lines four, seven and eight.


We discussed all about our standard coding style and comments should be slash, slash asterisk.


>> No, shouldn't.


>> I'm sorry. >> I kind of agree with said that we should go with, maybe, a minor plus plus or some kind of other
severity.


If, if styling is, is important as we kind of talked about maybe that should be somewhere between major and minor.


>> Okay.


Okay. >> Really need to crack down on that.


Make sure that one just doesn't get washed away.


>> Yeah.


>> And also before you go to the next one Crazy Bob, please read the meaning of the redispositions again.


So the first one is what?


The first one is the line number.


The second sources.


>> Yeah. >> So our line numbers are four, seven and eight.


That's where the comments were.


>> No, I wasn't being clear.


>> On the form?


>> They're on the forum.


>> Oh first, oh this one.


This is just the number.


>> Okay. >> Like consecutive number.


>> All right.


>> Of the defect that we found.


Then the type, so there's missing, wrong, extra usability, performance, style, clarity or question.


And then there's the severity, either major minor, and then we can add plus plusses, or minus minuses if you'd like.


And then it'll locate the actual line number of the code.


So then we have style minor line 16.


Follow should be in capital letters.


And character was misspelled and buy was misspelled.


And then stylistic minor line 19 inconsistent space in white space around, and then we talked again about needing a some
kind of coding standard for white space. then, wrong major plus.


On line 20 the equal equal should be not equal per our loop condition.


Then wrong again, major lines 19 and


28, we're printing every character on a new line as an integer.


Then stylistic major line 20.


We had a question about whether this loop ever even terminates, and we should be checking for some kind of enda file.


Stylistic minor line 31.


The assert comment is confusing.


Stylistic minor lines 32 through 35.


We should catonate all that system out into one line. [COUGH] Then wrong implementation major line 34.


We're printing the wrong variable.


Style again, minor everywhere is our brace placement standard.


We need to come up with something, some kind of standard.


>> Mine are plus plus maybe I don't know.


>> Then another plus plus.


>> And then style minor everywhere, there's no java.doc author tags or any other information on the code.


Stylistic major line 36, we should catch specific exceptions rather than generic exception.


Stylistic major, line 37, we should log exceptions instead of just exiting immediately.


Stylistic, again major, line 39, we need an exit status on our success.


Stylistic minor, lines 19 and


28, we should not be printing debug information to the console.


And then I added another important one that I think is important, major everywhere our implementation should've been in
Ada.


>> Oh, that's a minority report.


>> [LAUGH] Very good.


>> So, I think the code passes, right?


>> Thank you team.


I can certainly breathe easier now that we have squashed these bugs.


Ladies and gentlemen, I'm afraid I'm going to have to neuralize you to protect the identities of our team members.
[MUSIC] [SOUND]


12 - Credits
------------

