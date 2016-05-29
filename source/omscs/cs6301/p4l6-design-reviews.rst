.. title: P4L6 Design Reviews 
.. slug: P4L6 Design Reviews 
.. date: 2016-05-28 00:02:20 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

P4L6 Design Reviews
===================


01 - Introduction
-----------------

High quality designs become more important as the size of the application being designed grows. But as the size grows,
so too does the likelihood of some kind of design flaw occur. It therefore becomes essential to validate the designs and
the most common way of doing so is with design reviews. This lesson looks at design reviews, the participant's roles.
The process of performing them and general guidelines for producing effective reviews.


02 - Exercise Intro
-------------------

Let's begin with an exercise.


We'll use a code example instead of a design example, but the principles of reviewing are the same.


The following code is written in Java.


It computes the sin function for argument x to accuracy e using a Maclaurin series expansion.


In the example, line numbers appear in parentheses at the beginning of each line.


They are not part of the program but are there so we can refer to the lines.


03 - Defects Quiz 1
-------------------

Here is the example program.


As an exercise, write down any defects you detect alongside the relevant line number.


There are no wrong or right answers for this quiz.


04 - Defects Quiz 2
-------------------

For the same program, indicate the types of errors found at each marked line.


Mark b for bugs, d for documentation issues, v for violations of coding standards, or i's for inefficiencies.


Note for multiple errors, use comma separated entries.


05 - Defects Quiz 2 Solution
----------------------------

It turns out there're at least 13 different defects in this short piece of code, starting with line number 1.


First off, you can't meaningfully get a double precision result from a single precision argument.


This is just a bug.


In line 2, there's a documentation problem.


In the comment, the word declaration should be instead, method.


Also in line 2, in the comment, there should be a space after the right parenthesis in sine of x, and this is an
example, another example of a documentation problem.


Also on line 2, the comment should mention that the algorithms use the Maclaurin series expansion.


Finally on line two, the comments should actually include what the series looks like in terms of x minus x cubed over 3
factorial and so on.


These last two are both other examples of documentation problems.


Lines 5 and 6 are an example of another bug.


In this case, some analysis will indicate that the given solution won't work for negative values of x.


On line 6, to conform with the standards of the rest of the program, there should be spaces around the equal sign.


This is a coding standard violation.


Line 6 also illustrates an inefficiency.


The variable term gets initialized twice.


Actually, the initialization on line 4 is the superfluous one.


On line 8, there's another inefficiency.


It makes use of exponentiation, which in these sample, simple circumstances, could be replaced by a more efficient x
times x.


Also in lines 8, because the value of x doesn't change inside the loop, the computation of x times x could be moved
outside of the loop, thereby improving efficiency.


On lines 9 and 10, there's another bug.


The returned value produced by the algorithm is wrong because the test comes before the accumulation.


Line 10 illustrates another inefficiency in the computation of sum.


The exponentiation is merely doing the job of alternating signs.


Surely, there's a simpler way to do that.


Also on line 10, another inefficiency.


Multiplication is used to flip the values of the sign and this is inefficient also.


06 - Observations
-----------------

I expect that no one of you found every one of these defects.


But that, the class as a whole noticed most or all of these problems.


I also expect that some of you have noticed problems that are not on the list.


The point is that groups do better than individuals.


This is sometimes called the many eyes phenomenon.


There's a cost, however.


If 200 people each look at 13 lines of code for


15 minutes, this amounts to more than one week of staff time.


At current loaded salary rates, this might cost a company thousands of dollars.


Is it worth it to a company to spend that much money to find these problems?


Would a smaller group size have worked just as well?


Would more time per person have worked better?


Notice also that there were all kinds of defects.


I intentionally didn't tell you in advance what the word defect meant, but here there were bugs.


There were documentation issues.


There were inefficiencies, and there were even violations of coding standards.


Software engineers have studied defect detection and concluded that team review efforts can be cost effective way to
find defects.


However, the reviews must be done in a systematic fashion.


07 - Reviews
------------

A review, which can also be called an inspection or a walkthrough, is a systematic reading of a software development
artifact.


Reviews can be a cost-effective way of finding defects in the artifact, and reviews complement other verification
techniques such as testing and proofs.


That is, they find, tend to find problems that the other techniques don't find.


The purpose of a review is to detect defects, which, depending on the artifact, might be called bugs or faults.


Reviews may also be used to check adherence to corporate or governmental standards.


Reviews should not be used to educate staff members, report status or fix the detected problems.


Reviews can be applied to different kinds of artifacts produced during the software development.


These include requirements documents, specifications, architectural designs, detail designs, new code, fixes, test
plans, and documentation itself.


Effective reviews are systematic.


It is not sufficent, sufficient to just have a meeting and talk about an artifact.


People's time is expensive and group meetings are especially so.


Here are the recommended steps to take for an effective review.


08 - Step 1 Planning
--------------------

First off is planning. During the planning phase, participants are selected, a meeting is scheduled, roles are assigned,
the specific artifact, or part of an artifact is specified. And the materials, that is, the artifact, the review form,
and any background materials, are distributed to the, the participants. This planning should be complete about five days
before the scheduled meeting, to give time for the participants to prepare.


09 - Step 2 Preperation
-----------------------

The second step is the preparation itself. During this preparation period, the participants should individually study
the material, noting any potential defects. The idea here, is to save time in the meeting by having the participants
detect particularly superficial type problems that can be reported to the, reported before the meeting. And not have to
take time during the meeting to go over them. The expected rate of individual review should be about ten pages of text
or 100 lines of code per hour.


10 - Step 3 Review
------------------

The third stage is the review itself. The actual meeting takes place.


In general, it should last no more than two hours, lest fasi fatigue set in and effectiveness, overall effectiveness be
reduced.


The rate of review at the meeting should be approximately the same, as that used for individual preparation. During the
review meeting, the individually noticed defects should be collected. In most cases they should not be further discussed
at the meeting. The detailed meeting process will be described after we discuss the roles of the participants.


11 - Step 4 Rework
------------------

After the meeting is over, there's a rework period.


The artifact's author should investigate the issues that are raised. And, if, in fact, they are defects, they should be,
corrected or at least saved in an issue tracking system for later correction on a subsequent release.


12 - Step 5 Follow Up
---------------------

And finally, there's a follow up process. The author of the artifact should report to the moderator the results of the
reworked process.


The moderator should confirm that the fixes have been properly implemented.


Also, the moderator should collect data on the review itself.


Such as the number and types of defects detected, the number of participants, and the total time spent reviewing. This
data should be recorded and saved, so that the process of reviewing itself is being reviewed and, and possibly improved
if it, if it can be.


Finally, the moderator should suggest these improvements to the review process.


And, take them up with, the organizational, quality people, so that o, over time, the effectiveness of the review
process itself can improved.


13 - Roles
----------

In formal reviews, the participants play specific roles, including that of a moderator, a recorder, a reader, and 3-6
reviewers.


14 - Moderator Responsibilities
-------------------------------

The job of the moderator, in addition to those already mentioned, concerning preparation and follow-up, include the
following. The moderator should determine whether the participants have done the necessary preparatory work. If
necessary, the moderator should abort the review if the team is not prepared. Why, after all, go through an expensive
meeting if it's not going to be effective?


The moderator should also evaluate whether the work to be reviewed is actually ready for review. Let's say it's a code
review. And the organization has guidelines that say, before code review the code must be completed, it must be
successfully compiled and it must go through unit tests, the moderator can then check whether those events have happened
and if not, send it back and reschedule the meeting. A moderator is responsible for running the meeting. Keeping the
participants on track, arbitrating any differences, and managing time. Moderation is a skilled activity and moderators
typically have under, undergone some kind of training at the task.


Finally, moderators should be technically competent, but not necessarily expert on the specific artifact of technology
being reviewed.


15 - Recorder
-------------

Another important role during a review meeting is that of the recorder.


The recorder is responsible for making a record of the issues raised during a review. Note that it may not be possible
to determine in a review meeting itself whether an issue represents a defect. This determination may require some
offline research. It is the job of the recorder to proactively clarify the issues raised. During the course of a heated,
heated discussion, this may be difficult. Several different issues may intertwine more of a two seemingly different
concerns may actually reflect a common question.


The recorder will often ask for clarification until he is satisfied that he understands the essence of the problem being
discussed.


16 - Recording Form
-------------------

The recorder typically makes use of a form for recording issues. The for includes for each issue raised, it's location
within the artifact, it's description, it's type and it's severity. Issue types are artifact dependent for code review
for example there may be logic issues, library issues, standards conformance issues and so on. Severity levels are also
typically pre-defined, and some suggested ones are listed on the next slide.


17 - Severity Classification
----------------------------

Each organization should determine it's own severity classification, based on its release and artifact peculiarities and
whatever source issue tracking system or source control system that they have. Here's one possible schema.


It includes three different levels. The least severe is that minor re, rework is required. That this rework can be
verified by the author.


This would be the case if there were questions about the comments or standards conformance, something like that. A
somewhat more severe level would be where there's conditional rework that it would be verified by the moderator.


And then, for major rework situations, reinspection is required. And here a guideline would be that if greater than 20%
of the document or 20 hours of work or 100 lines of code have been affected then a rereview might be required.


18 - Reader
-----------

Another review role is that of the reader. Reviews should be systematic and thorough. One way to deal with this need is
to explicitly address each part of the artifact being reviewed. For example, in the code review, each line should be
individually looked at. The reader is the person responsible for enforcing this thoroughness by leading the participants
through the artifact and for each part paraphrasing what, what the artifact is expressing for that part. The
paraphrasing should be its, should be descriptive, and not try to say why that particular part is there. Some
organizations run their reviews with the artifact's authors being the readers. Other organizations make sure that
someone else does the reading. I think in the case of the first type of organization, the thought is that an author
might buy us the discussion by emphasizing certain things, the author felt as important, even at the expense of perhaps
hiding some details which need to be looked at more carefully.


In either case, the reader should use impersonal pronouns such as it, referring to the artifact, rather than referring
directly to the author with I, or he, or she, or something like that. Personalizing a review by using I and, and you,
and, and so on, can raise the defensiveness level of the participants thereby reducing the review's effectiveness.


19 - Reviewers
--------------

The other participants in the meeting are the reviewers.


These ae the people responsible for raising the issues. Not to say that the, the moderator or the recorder or the reader
can't list some issues, but their, their primary focus is going to be on their other, on, on their individual roles,
whereas the reviewers, the job here is to do exactly that. To review the artifact and to point out raise, raise issues.


Typically a meeting will have three to six reviewers, fewer run the risk of not having enough eyes on the target and
more can be overkill.


Right not being effective as far as the, the time invested in, and the number of defects found. Reviewers should raise
issues by asking questions, as opposed to saying that's a problem. They should not explicitly suggest improvements, but
rather ask if the author thought about doing things in an alternative fashion.


The viewer should not blatantly assert defects, but ask what would happen under different circumstances.


By taking a questioning attitude, the team can productively raise issues without getting diverted by emotionally driven
debates.


20 - Review Meeting
-------------------

So those are the participants.


Now, let's talk for a minute about the review meeting itself.


For a effective reviews, the review meeting should be itself, be structured.


This includes the following steps.


First off, introduce the participants to each other.


They might not previously know each other.


In particular, one effective strategy would be to bring in a member of a different team. who's, you know, has a similar
level of expertise, but to, to put a different set of eyes that may not be biased by the you know, common understanding.


Second, is a statement of objectives by the moderator.


This is a reminder that the purpose of the meeting is to raise concerns over specific artifacts.


And not get diverted into problem-solving or, or other other issues.


Third is an evaluation of the preparedness to determine whether the meeting can go forward.


This involves checking with the reviewers as to whether or not they had done their preparation, and to collect their
issues that they've already found.


And also to check whether the artifact itself is ready for review.


Next is the systematic review itself using some means of ensuring thoroughness, and we'll look at some of those in a
minute.


This is where the term walk-through is very important.


The actual going through the artifact in a very systematic step by step fashion to make sure the whole thing is covered.


During this process it could be recording of results in the form of the issues raised on the review form.


After the systematic review, but still inside the meeting, there should be some kind of summarization, often led by the
recorder of the issues raised, including a determination of severities and priorities.


Finally a determination of who is responsible for looking into these issues.


In many cases it will be the author.


But it may be that in certain cases somebody else gets assigned to do that.


There should also be an agreement about how resolution will be verified.


With respect to is it the moderator's responsibility?


The author's?


Or is there going to be a view review


21 - Thoroughness
-----------------

A key determinant of a successful review is how thoroughly the participants examine the artifact. There are variety of
means that have been devised to encourage this thoroughness. Line by line coverage of, of the code or the documents
involved. similarly, if, if it's a, a diagram is being, reviewed or going through systematically on the visual elements
of a diagram.


If we're talking about the early stages, the requirements document, it may be the use cases, and making sure all the use
cases are going through.


Another technique for ensuring or promoting thoroughness comes at things from a little bit different point of view. And
this is a check list based reviews.


The checklist is based on common def, types of defects, either derived from common industrial practices, or company
specific empirical data. So for example, if it's a code review there and the company has a history of problems with
correctly interfacing with libraries then it might be that you add a check list for making sure that library interfaces
are looked at a little bit more deeply.


And one, one other one is coverage of verification conditions.


This is kind of a specialized, checklist. Verification conditions were invented as part of a clean room software
engineering methodology by IBM.


A verification condition is a rule that obtains in a particular situation. For example, when a loop is encountered
during a code review, a specific verification condition is to examine whether the loop is guaranteed to terminate under
all circumstances.


22 - Metrics
------------

Reviews, like design, testing, and coding, are software development activities.


As such, they can be measured to see how effective they are.


The key statistics to compute are the following. First off, the review rate in lines of artifact reviewed per staff hour
spent reviewing. Second is defect rate in the number of defects detected per staff hour spent reviewing.


Then from those numbers the defect density is the defects per line of artifact.


This can be used to indicate whether the process of producing that artifact is leaving too many defects in it. And then,
process yield is computed by comparing the review detected defects to total defects, or how do you know what the total
defects are? One way of getting a total defect includes those defects detected by other means, such as testing and those
that are eventually reported by users of the delivered product.


23 - Process Data
-----------------

1


Reviews are an early step in an organization's effort to improve the quality of


2 it's products it produces.


3


A more sophisticated step is to review the review process itself.


4


That is, to collect data on the effectiveness of the reviews and


5 use it to improve the review process.


6


Among the data that might be collected are the following.


7


What was the artifact being reviewed and


8 at which stage of the development process does the review take place?


9


What was the date and time of the review and how long did it last?


10


Who were the participants and how much preparation time did they spend?


11


How many issues were raised, how many of them turned out to be defects,


12 what were their types, and what were their severities?


13


Organizations can also collect subjective data


14 by distributing post review effectiveness questionnaires to the participants.


15


Finally, for large organizations, it makes sense to store this data in


16 a database for aggregate analysis over time.


24 - Alternative Review Styles
------------------------------

There are many different styles of review. Here’s a brief list of some notable ones. The class resources page points you
to further information about them.


What we’ve been talking about are sometimes called Fagan reviews. Fagan was an IBM researcher, her, who first studied
them and proposed the structuring that we’re, we’re talking about. But a a more recent and alternative approach is
called pair programming, which is part of extreme programming, an agile development method and this was studied by
Laura, Laurie Williams.


It suggests that review is part is performed synchronously with, with coding or developing of an artifact by having a
partner looking over the coder's shoulder pointing out problems at the time that that coder is, is, is doing his or her
job or that the designer is doing their design. Another alternative is what's called pass-around reviews. These are
typically conducted by email.


This is often applied in open source projects where the people aren't collocated and the source code management system
alerts participants to take a look when a new change or new file has been checked into the source control system.


And in any of these approaches there's a possibility of applying tools.


Tools might be differencers to compare versions the source control management system itself as I've, as I've indicated,
and there're also program analyzer tools that can provide enforcement and feedback and examples here are Lint. You may
have heard of the Lint program or CodeCheck, which is a plugin into Eclipse.


25 - Guidelines   Participants
------------------------------

Reviews have become a common part of everyday software development practice.


As such, much has been learned about how to perform them.


What follows in this lesson are some dos and don'ts of gleaned from actual experience. We begin with some about the
participants. First off, reviews should not be used for personnel eva, evaluations.


If participants feel that what they say about someone else's code will affect their performance rating or salary, they
may be reluctant to speak. For this reason managers should in general not attend review meetings unless they have
participated technically in the production of the artifact being reviewed.


Or they're outside of the participant's reporting hierarchy. Similarly, in general it is not a good idea to allow non-
participant observers in review meetings as they can provide distractions. Don't treat a review as an opportunity for
training new staff members. This will reduce the productivity of the review session. Instead, hold a separate meeting
with the trainee.


The author of the artifact being reviewed should not be the moderator or recording. These are specialized tasks that
require full concentration.


Some organizations also require that the author not be the reader.


26 - Guidelines   Content
-------------------------

Here are some guidelines about which topic should be avoided during your review.


If possible, avoid discussions of, of style. These can be a lot of fun, and there's a lot of flaming going on, but
people have strong feelings and consistency is more important, that is, consistency of, of style, is more important that
what particular style is emp, is employed. Avoid problem solving during review meetings. The goal of the meeting is to
raise as many issues as, as possible. Solve the problems offline or at another meeting.


Avoid use of the word you and any phrasing that might raise defensiveness.


27 - Guidelines   Process
-------------------------

Here are some guidelines about the review process itself. First off, spread out the reviews over time.


Performance degrades if reviews are too concentrated. A practical limit for the duration of a review is the smaller of
250 lines of code, or 2 hours of, of artifact reviewing. Each type of review should have its own criterion for
thoroughness, which should be determined in advance of the meeting.


You can, treat the review as a go, no go decision activity. That is, the review meeting should end with a decision about
whether or not the artifact is ready for the next stage of the development process.


In fact, some organizations require the reviewers to sign off on the acceptability of the artifact, thereby improving
accountability.


28 - Effectiveness
------------------

Code reviews are an effective technique for detecting defects in artifacts.


Collected data indicates that for typical formal review, as described above, between 70 and 90% of defects are found.
That is, if we're talking about a code review of all the defects in that code, the review meetings are going to find
between 70 and


90% if you have effective reviews. Of course, there is a cost which amounts, in typical situations, to between 10 and
20% of the total cost of development.


This cost is largely due to the staff time involved in the preparation work and the review meting itself. The above data
notwithstanding, defect detection rates vary dramatically depending on the specific rule goals, artifact complexity and
how effective the meanings are themselves.


29 - Other Costs and Benefits
-----------------------------

In addition to the numeric data, there are several other benefits and costs to be aware of. Individual skills can be
enhanced by looking at other people's artifacts. There's some evidence to suggests that lightweight reviews, those
involving the author and a couple of other people doing desk checking, are more effective in finding defects per staff
hour. Of course, this does not mean that more total defects are detected and when using them, it is more difficult to
collect overall organizational data.


Your organization is going to have to learn from trying out various approaches as to what's the most effective approach
within that organization.


You should also be aware of the so-called ego effect. That is, the knowledge that an author's artifact will be reviewed
tends to improve the quality of the delivered artifact. That is if you're going to show what you're doing to somebody
else, you're going to make it better. However, there's a danger of damaged egos when an author is confronted with his or
her defects. Collectively, there is also what is called the big-brother effect, in which stress levels are raised
because people know they are being watched and measured.


30 - Summary
------------

The later that a software development problem is detected, the more expensive it is to fix it.


Hence, we want to find problems as early as possible in the process.


Reviews are a cost effective way to find problems in all kinds of artifacts, including design documents.


Going further, we want to detect deep problems if we can.


And reviews run the risk of revealing shallow problems with a document self or with superficial aspects of the design.


To reveal deep problems requires exposure of the design to experienced designers who are among the most highly paid and
time stressed people in the development process.


Therefore it makes sense to have the design review be as focused and well-run as possible.


To do this reviews should be institutionalized.


By that I mean, they should be a formally defined process element and part of the corporate culture.


By doing so, the short-term costs involved in conducting reviews will be more than offset by the eventual saving on
reduced maintenance and increased customer satisfaction.


