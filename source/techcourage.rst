=========================================
Technology and Courage by Ivan Sutherland
=========================================

**About the author**

::

    |copy| Copyright 1996 Sun Microsystems, Inc. Perspectives, a new and
    parallel series to the Sun Microsystems Laboratories Technical Report
    Series, is published by Sun Microsystems Laboratories, a division of Sun
    Microsystems, Inc. Printed in U.S.A. Unlimited copying without fee is
    permitted provided that the copies are not made nor distributed for direct
    commercial advantage, and credit to the source is given. Otherwise, no part
    of this work covered by copyright hereon may be reproduced in any form or
    by any means graphic, electronic, or mechanical, including photocopying,
    recording, taping, or storage in an information retrieval system, without
    the prior written permission of the copyright owner. TRADEMARKS Sun, Sun
    Microsystems, and the Sun logo are trademarks or registered trademarks of
    Sun Microsystems, Inc. UNIX is a registered trademark in the United States
    and other countries, exclusively licensed through X/Open Company, Ltd. All
    SPARC trademarks, including the SCD Compliant Logo, are trademarks or
    registered trademarks of SPARC International, Inc. SPARCstation,
    SPARCserver, SPARCengine, SPARCworks, and SPARCompiler are licensed
    exclusively to Sun Microsystems, Inc. All other product names mentioned
    herein are the trademarks of their respective owners. For information
    regarding the SunLabs Perspectives Series, contact Jeanie Treichel,
    Editor-in-Chief <jeanie.treichel@eng.sun.com>. For distribution issues,
    contact Amy Tashbook Hall, Assistant Editor <amy.hall@eng.sun.com>.


Editor's Notes
--------------

*About the series*

Perspectives series is a collection of essays written by individuals -- The
from Sun Microsystems Laboratories. These essays express ideas and opinions
held by the authors on subjects of general rather than technical interest. Sun
Microsystems Laboratories publishes these essays as a courtesy to the authors
to share their views with interested friends and colleagues. The opinions and
views expressed herein are solely those of the authors, and do not in any way
represent those of Sun Microsystems Laboratories, nor Sun Microsystems, Inc.

About the author 
----------------

Dr. Ivan E. Sutherland recently won the prestigious Price Waterhouse --
Information Technology Leadership Award for Lifetime Achievement, as well as an
honored place in the Smithsonian's Permanent Collection of Information
Technology (IT) Innovation. He is widely known for his pioneering contributions
in the field of computer graphics. His 1963 MIT Ph.D. thesis, Sketchpad, first
demonstrated the potential of computer graphics. In his work on a head-mounted
three-dimensional display at Harvard in the mid '60s, Ivan anticipated today's
virtual reality by 25 years. He is co-founder of Evans and Sutherland, which
produces the most advanced computer image generators now in use. As head of the
Computer Science Department at Caltech, he helped make integrated circuit
design an acceptable field of academic study. Dr. Sutherland is a member of
both the National Academy of Engineering and the National Academy of Sciences.
He received the ACM Turing Award in 1988 and holds several honorary degrees. 

In this paper, his spirit and joy are revealed.

*I, for one, am and will always remain a practicing technologist. When
denied my minimum daily adult dose of technology, I get grouchy. I believe
that technology is fun, especially when computers are involved, a sort of
grand game or puzzle with ever so neat parts to fit together. I have
turned down several lucrative administrative jobs because they would deny
me that fun. If the technology you do isn't fun for you, you may wish to
seek other employment.  Without the fun, none of us would go on.*

Notes from the Author
---------------------

This paper is essentially the text of a lecture I gave at Carnegie Mellon
University in 1982. It was the first, and nearly the only, non-technical
lecture I have ever given. At the time, I was deeply concerned that the ideas
I expressed would be of little interest or value. This paper was eventually
published in the Carnegie Mellon University Computer Science 25th Anniversary
Commemorative [15]. Continuing demand for informal copies suggests that
people, especially young people, may garner value from it. Perhaps experience
has something to offer youth. As I read this paper again for the first time in
many years, it brought me face to face with my own latest failures of courage.
Sadly, I have no more courage now than I had then, no better insight into
failures of courage, and no new ways to bolster courage. I was able to add
only citations to subsequently published work. Sun Microsystems Laboratories
reprints this paper with permission of the ACM press as a courtesy to those
who may wish a copy. The ideas are my own and represent no official position
of Sun Microsystems, Inc. or Carnegie Mellon University. The text is also
available on the World Wide Web. You may reproduce this document for any
not-for-profit purpose. Reproduction for profit or where a royalty is paid to
anyone requires prior permission from the author.

Ivan Sutherland Mountain View, CA December 1995

Technology and Courage
======================

Ivan Sutherland
===============

Sun Microsystems Laboratories 2550 Garcia Avenue Mountain View, California 94043

1 Introduction
--------------

Sutherland is a Scottish name. My ancestors came from the northernmost county
in Scotland, called Sutherlandshire, a land where cows grow long hair against
the cold, trees mostly refuse to grow at all, and the farmers cut peat to heat
their homes. I enjoyed the sunrise at 3 AM there one summer morning, it having
set about 11 PM the previous evening. Because the bonus of summer sunshine is
merely borrowed from winter, winter must be bleak indeed. A British friend who
was with me in Sutherlandshire remarked that Sutherlands there are "two for a
penny"; I had thought of them "a dime a dozen," but considering the pound to
dollar exchange rate, it's about the same value. I often wear a tie bearing my
family colors, the Sutherland tartan. Depending upon the listener, I claim to
wear it either a) because I own only one tie, which is not true, or b) as a
default to avoid having to choose a tie, which is true but unimportant, or c)
in honor of my late father who also generally wore such a tie, which is also
true and is my real reason: like my father before me, I am proud of my lineage,
and draw courage from identifying with my ancestors.

Nearly all of the talks I have ever given were technical. Because I am a
professor at heart, you can wind me up and I will easily go on for exactly 50
minutes on any of my several technical interests. I go on easily because I know
my subjects well, I know what is interesting about them, I know that I can talk
clearly about them, and I have had favorable responses from previous audiences.
Today, however, I want to do something very much harder for me. I want to
depart from my familiar technical fields to address a different subject:
courage. I direct my remarks to young people who may soon discover for the
first time that to do technology requires courage, and to my older colleagues
who, like me, have languishing technical projects and reports that seem less
important than today's urgent tasks. I am going to talk about the courage
required to do creative technical work, and because I have mainly my own
experience to draw on, this will be an intensely personal talk, revealing of my
own failures of courage. I ask you to apply to yourselves any lessons you may
learn. 

**1.1 What is Courage?**

Many activities require courage, a human trait we find admirable. We admire the
courage required to explore a wilderness and so great explorers become famous:
Lewis and Clark, Admiral Byrd, Amelia Earhart, and John Glenn, for example. We
also admire political courage, as exhibited by Abraham Lincoln or Winston
Churchill, or more recently by Mikhail Gorbachev.  Taking financial risks in
business also requires courage, as exhibited by Lee Iacocca, although less so
when someone else's money is at risk. Changing to a new job or a new school
requires personal courage, especially so when making a home in a new city. What
is courage? Courage is what it takes to overcome fear.  Fear is an emotion
appropriate to perceived risk. Thus, to exhibit courage one must both perceive
a risk and proceed in spite of it. Suppose a child has fallen through the ice
on a lake and could be saved if reached. A person who walks out on the ice
believing it to be very thick requires no courage because he perceives no risk
even though others may think him courageous. A person who correctly perceives
that the ice is thin and stays off it likewise exhibits no courage; rather we
call his action prudent or cowardly, depending on whether or not the ice is, in
fact, too thin for safety. Courage is required only of a person who proceeds to
rescue the child in full knowledge that the ice is thin.


**1.2 Courage in Technology**

Exploring the horizons of technology requires courage because research carries
risks, even if we cannot always articulate them in advance. Generally they are
not physical risks, although physical risks exist in some fields of science.
Often they are not immediate personal financial risks, because these may be
borne by the university, an industrial employer, or the government sponsor of
the work. Usually the risks are more subtle but no less strong: they are social
and emotional risks, risks to reputation and to pride; they are risks that are
felt but difficult to identify and describe. In addition to the risk to
reputation and to pride, the very nature of research poses its own special
risk. In research, we daily face the uncertainty of whether our chosen approach
will succeed or fail. We steep ourselves in elusive, mysterious, and unnamed
phenomena, and we struggle to unravel very complex puzzles, often making no
visible progress for weeks or months, sometimes for years. We strive for
simplicity and clarity in a cloudy and often baffling world. The special risk
of research starts with the high probability that any particular attempt will
fail and follows from the resulting experience of repeated failure. Research
carries a special risk of discouragement. 

**1.3 Failures of Courage**

When you have inadequate courage for a task, you can work up your courage,
reduce the real risk, reduce your perception of the risk, or leave the task
undone. I use all four methods. All too often, however, I leave tasks undone
because I don't recognize that my courage is inadequate to the risks I feel but
don't verbalize. Our universities provide mechanisms, both formal and informal,
for reducing the risks of research and for building up the courage of
researchers.  Our free enterprise system also provides mechanisms to encourage
entrepreneurs to undertake new challenges. Each of us also has ways to conserve
and bolster his own courage. The body of this talk is my list of some of these
mechanisms.  I suggest that you can draw on them as well as invent some of your
own, and that by doing so you may be better able to face the difficult
challenges technology offers.


2 External Encouragement
------------------------

Because individuals are often unable to get things done without encouragement,
society has devised many forms of encouragement. There are rewards of money,
fame, acclaim, recognition, status, or love. Prizes, statues, certificates,
medals, and honorary titles are some of the adult equivalents of the gold
stars we got as children for good work. Large offices, with carpets, maybe
with windows, and with or without a flag or fancy plants in them are also
symbols of status. There are also punishments for inaction. Often we formalize
such rewards and punishments in the form of written or unwritten contracts.
Contracts often contain deadlines. Deadlines help inspire us to extra effort
because the task must be done on time. In some research, deadlines are
absolute: a space mission to study Halley's Comet must be launched on time,
but softer, self imposed deadlines are also useful for raising the urgency of
tasks.

An architect friend of mine taught me the word "charette," meaning the
feverish activity immediately preceding a deadline. The term comes from the
French name for the horsedrawn carts in Paris that carried architectural
students with their architectural models from their workshops to their
examinations, still feverishly finishing the models "en charette." In the
vernacular English we can speak of "having a charette," and, of course, there
is a verb form: "charetting it up." Without a deadline there can be no
charette. A designer friend of mine is completely unable to function without a
deadline to work against. Several times I have asked him to do simple tasks
for me, designing a letterhead, for example, "when he had time." Until I
figured out that he works only against a deadline, I got no result at all. Now
I ask him for something by a particular date and he usually delivers on time.
Evidently, he can work only "en charette." 

The fellowship of people in groups offers encouragement. Groups of
people will even do things that single individuals wouldn't do; lynchings and
riots are an extreme form of this. Group activities seem easier. Boards and
committees share not only knowledge, but also responsibility, and thus increase
their participants' willingness to undertake risk. Moreover, the fellowship of
such groups makes working more fun. Is this because man is a social animal, or
is this why we call man a social animal? I always thought that working with a
partner or with a few colleagues was better than working alone, in part because
I can rarely think about difficult subjects without verbalizing them to someone
else. I like to collaborate with someone to whom I can express my ideas, even
poorly formed ones, and from whom I can draw a fresh look at them. The names of
my companies bear witness to my need to collaborate: the Evans and Sutherland
Computer Company and Sutherland, Sproull, and Associates, Inc. I owe much to my
partners in these enterprises. 

**2.1 Encouragement in Academia**

One of the beauties of a university such as Carnegie Mellon University is that
it abounds with mechanisms to encourage people to do research. Some of these,
like formal classes, reduce the risk of learning new things. Some of them,
like observing other people at work on other research tasks, can bolster a
graduate student's courage to do likewise. Others, like the traditional
academic tolerance of nonconformity, reduce the social risk of entertaining
new ideas.  The university provides mentors. My former student, Dan Cohen,
called me for advice nearly 15 years after getting his Ph.D., asserting that
he wanted counsel from his "faculty advisor." I demurred, claiming that I had
stopped being his advisor more than a dozen years ago. Not so, he said, "it's
a tenured position." Because attachments between students and faculty become
strong, contact with the mentors provided by the university is valuable
indeed, almost as valuable as contact with students. I have learned far more
from my students and gained more pleasure from them than I have ever offered
in return. 

Formal Mechanisms Among university classes, I find the study seminar most
interesting for several reasons. Such a seminar gathers together a group with
similar interests who read up on a subject and pool their knowledge at regular
meetings. By providing a series of regular meetings and homework assignments,
the study seminar provides deadlines for its participants. Working together
with colleagues reduces the labor required from each participant and makes the
learning experience more pleasurable. Finally, working in a group reduces the
perceived risk inherent in the new material. The immigration course in Computer
Science at Carnegie Mellon University is one of the best examples of a formal
way to help new graduate students get started.

It forces them to learn about what facilities are available, it gives them the
opportunity to meet and get to know the people they may work with, and it
introduces them to the existing research projects. By providing a broad range
of background knowledge and forcing the students to do a small warm-up
project, it not only reduces the risk of learning what equipment is available
and how to use it, but it also builds confidence. I applaud the makers of the
immigration course for finding such an effective way to launch would-be
researchers. The university also offers formal mechanisms to encourage
graduate students to keep going when the going gets tough. One of these in
Computer Science at Carnegie Mellon University is called Black Friday. As I
understand it, Black Friday is a knock-down-drag-out meeting of the faculty at
which each and every graduate student is individually discussed to detect
those making inadequate progress.

The laggards are then given formal notice to move forward or leave. By
increasing the risk of inaction, the threat of Black Friday forces students to
bolster their courage and get on with their work. My advice for a new graduate
student seeking to get started in research is to join an ongoing research
group. Of course there is an opportunity cost to joining up with a particular
group: you can't then join others. But it matters far less what a new student
does than that he do something. If the first two or three things don't work
out, you can always switch to another group or another project. The key thing
is to get involved in something, get some basic knowledge, and get started. 

**2.3 Talking and Writing**

A thesis proposal can provide a starting mechanism for a thesis project: it
can serve as a guide to the proposed research. It indicates that some thought
has gone into what to do, even though the real work may not yet have started.
Most important, the thesis proposal can serve as a point of discussion between
proposers and their advisors, both formal faculty advisors and student
colleagues. Accepting the thesis proposal is in and of itself a way for the
faculty to encourage a student to get on with the work. All too often, thesis
proposals are an afterthought to research already done, becoming at best an
outline of the thesis document. I far prefer them earlier as a guide to the
research itself. Academia provides mechanisms to encourage publication of
which the strongest one is known as "publish or perish." A new, untenured
faculty member must obtain tenure or leave the university after a fixed period
of time, but to obtain tenure one must publish. A journal editor I know once
remarked that she sits on the tenure committee of every university in the
country.  Tenure itself can be encouraging. A young and talented friend of
mine, a computer scientist by training and a tenured professor of Computer
Science at a major institution, has recently become interested in combustion.
He commented to me recently that he feels guilty for pursuing studies so far
outside his departmental boundary. I hope you share my feeling that he should
follow his interests exactly where they lead. That is, after all, precisely
what tenure should encourage him to do. Universities also provide a host of
places where talking about research is easy. Seminars provide a knowledgeable
and usually friendly audience for new ideas. By providing peer pressure to
participate and share results, seminars can encourage students to practice
talking about their work. Even in an informal seminar, the first few
presentations take an extra batch of courage, but with practice comes
familiarity and skill, a better assessment of the minimal risk, and increasing
comfort. I have often seen student speakers literally shake before and during
their talks. Practice in teaching is a good way to learn how to present ideas
to groups. Graduate student teachers not only staff undergraduate classes, but
also learn to speak in public. One hopes that they do not damage the
undergraduate students too badly. Practice in writing is also valuable,
starting in high school or undergraduate English classes. All too often
technical writing has to be a part of graduate education. 

**2.4 Informal Interactions**

One of the difficult lessons of graduate school is the lesson of autonomy from
the faculty. At first, a graduate student may feel unable to question his
mentors, but by the end of graduate training, that same student will be able to
take his place as a researcher in their ranks. Graduate school is the place
where the distinction between mentor and student begins to blur, and faculty
and graduate students become colleagues.

Informal interaction between students and faculty helps students join the
ranks of full-fledged researchers. I recall playing with blocks at Claude
Shannon's house when he was my thesis supervisor. Although at the time I
thought of it as recreation, and he may also have, it provided me with courage
because I saw his less daunting facets, his human side. He became my friend as
well as supervisor, and this made him more approachable and raised my
confidence.

Universities encourage informal social interactions. Although some social
functions may seem to be just for play, they help us get to know each other,
and by knowing each other, we become better able to share our burdens of
discouragement. We provide each other with courage. Within the fellowship
provided by such social functions we can gain insight into the habits of our
mentors and friends, and can discuss ill-formed ideas that would be too risky
to reveal in a more formal context. 

In Academia, it's Hard to Stop Some academics go on and on doing the same
research year after year, often as a continuation of their thesis work.
Academia seems to me deficient in mechanisms to help people stop old and stale
projects. Sometimes their sponsors withdraw support and sometimes their peers
suggest change. More often, however, academics continue working on old things,
turning away only when they find newer and more interesting projects. 

**2.5 Encouragement in Business**

A person with the courage to start a new business is called an entrepreneur.
When I was a child, my parents offered high praise for he who was
"enterprising." By starting several companies myself, and through my work in
venture capital, I have observed many ways that entrepreneurs work up their
courage to the point where they are ready to start a business. The most
important formal mechanism, nominally intended to present the prospects of the
business to the financial community, is called the business plan. A business
plan is very much like a thesis proposal. It says what its proponents intend
to do, what they plan to spend, what competition they expect, and what return
they anticipate. Its preparation requires that the entrepreneurs do the basic
work that is needed to assess the business risks.  Its approval encourages the
entrepreneurs to begin by providing not only the capital required, but also
the moral encouragement of the supporting investors.  In effect, the business
plan records the entrepreneur's estimate of the thickness of the ice. The
financial backers of an enterprise back it only after examining its prospects
with "due diligence."

Sometimes it seems to me that a plan is so obviously timely and the
entrepreneur's ability so obviously great that little further diligence is
due.  My venture capital friends, however, often forget what "due" means, and
treat due diligence as if it were a single noun denoting the collection of
paper that justifies investment in the business. They may say, "let us gather
some due diligence," and they have files of due diligence. It seems to take
due diligence about one inch thick per million dollars invested. Ultimately,
the financial backers of a new business must express their faith in the
entrepreneurs and have the courage to invest. They should exercise due
diligence in making their own estimate of the thickness of the ice. Although
business plans are rarely followed in any great detail, they are nevertheless
very useful. They build courage in the entrepreneurs by letting them plan a
real business and see its potential profit. They provide a way for financial
backers to understand the proposed business, milestones for measurement of
progress, a common ground for discussing changes in plan, and a common target
for both entrepreneurs and backers to seek. The plan's real function is to
endow everyone with the courage to proceed. It turns out that a large fraction
of new businesses fail, just as a large fraction of research ideas fail.

Fortunately for our society, our collective courage keeps us trying, even
trying things that prove imprudent. Were we a more cautious lot, a much slower
pace of scientific and industrial progress would prevail. If you don't fail
regularly you are not trying hard enough things. The trouble, of course, is
that it is emotionally much harder to restart after a failure because the
risks seem clearer. This may be why the energy and enthusiasm of youth are so
important in research and in new businesses. 

**2.7 Business Incentives**

Our system of capitalist free enterprise provides equity incentives. It is
amazing to me how effectively stock ownership motivates hard work, and more
important, how common ownership of identical stock makes people pull together.
If you and I both own the same type of stock, I can make a return if and only
if you do, and thus my objective becomes to make you rich. This is the power of
the capitalist system that raised our standard of living to the highest in the
world. In addition to stock ownership, income and bonus incentives to business
people often help keep their minds focused on their essential tasks.
Commissions for sales people are very common, probably because selling takes so
much courage to face the high risk of rejection by the potential customer.
There is almost nothing I like less than selling, particularly against
competition that undoes my sales pitch as soon as I turn my back. Amazingly,
salesmen with a commission program will keep at this difficult task; I can only
conclude that they draw courage from the commission. Presidents of companies
often have bonus programs tied to the profitability of the company. Such plans
let the president do well if and only if the shareholders do well, and thus
encourages him to keep the shareholders' interests at heart. Contracts are an
essential ingredient of modern business. Contract milestones often include
partial payments and thus powerful encouragement to getting on with the job.
Contract deadlines can include penalty clauses. For example, the repaving
contract for the Golden Gate Bridge included penalty clauses of tens of
thousands of dollars per hour for delay in reopening the bridge to traffic each
day. Social incentives also work in business. I spend much of my time as a
consultant and have discovered that one of my tasks is to provide deadlines to
my client's employees. My visits provide the deadlines for "charetting it up,"
for getting all of the reports done, for getting the presentations ready, and
for getting on with the work. I can and do provide praise for good work. I like
to think I have something technical to contribute also, but even if I did not,
the deadline and appraisal value of my visits may easily make them worthwhile
to my clients. It is not accidental that the word "company" as applied to a
business enterprise is the same word that we apply to social occasions, as in
"having company" or "keeping company" or "being company." Indeed, the Hudson's
Bay Company, chartered in May 1670, was literally called "The Governor and
Company of Adventurers of England Trading into Hudson's Bay." The corporate
form of business as we practice it has a Board of Directors to provide policy
guidance. The board is elected by the owners of the company, the shareholders,
and in turn, the board elects the officers of the company who manage its
day-to-day affairs. In a very real sense, such boards along with the corporate
officers are the Company of Adventurers who do our business. The board meets
quarterly or monthly or, if necessary, more often. My experience suggests that
the most effective boards have a measure of fellowship that helps them seek
wise decisions together. When business prospects seem good, there is often
humor at board meetings. It may be that the number of jokes told at board
meetings is an important, albeit unreported, leading indicator of the business
climate.

**2.8 Stopping a Business**

Unlike academia, the capitalist system of free enterprise provides a very
clear mechanism to detect when to stop, namely lack of profits. Businesses
fail when customers refuse to purchase their products: as one of my venture
capital partners says, when "the dogs just don't like the dog food." In fact,
most businesses fail; few succeed. But even in business, it can take courage
to stop. Investor courage is required to withdraw support from a failing
business and its employees, but support must be withdrawn if the prospects do
not warrant further investment. An investor friend of mine said he got into a
multi-million dollar unsuccessful investment "one nickel at a time." He
couldn't stop. Personal courage is required to admit that one's skills do not
match the business needs. I have admired two chief executives who gracefully
turned over control of their businesses to others after realizing their own
inadequacy; more often the incompetent hang on far too long. When a business
fails, there are legal details to tidy up as well as odds and ends of value to
be sold. Individuals who do this well can extract value for the owners of the
business that might otherwise be lost, but it is hard to do a good job while
carrying the sense of defeat and loss of a failed business. I think that the
most subtle form of the courage to stop is to know when to sell a security. My
portfolio of investments is dear to me; they are like old friends, the family
dog, or my ancient automobile. I shudder to part with one. Nevertheless,
prudent management requires that I sell those that are not destined to be
winners and use the funds instead to buy better equities. The hard part of
course, is deciding which are not to be winners. It takes courage to sell
stocks, far more than it takes to buy them.


**2.9 Investment Courage**

I believe that investment courage is in short supply in the United States
today, individually, institutionally, and nationally. Our collective failures
of courage are, I believe, the cause of our decreasing economic success
vis-à-vis our international competition. Long-term projects take more courage
than short-term ones because the greater uncertainty of the distant future
seems riskier, whether or not it really is. Our industrial and governmental
institutions are not, I believe, making the courageous long-term investments
in education, training, research, development, equipment, and infrastructure
required for long-term economic strength, and as a direct result, we are
losing a global economic war. One reason for the shortsightedness of business
in the Unted States today is that the profit sharing plans for executives
consider only immediate profit and not longterm growth. Another reason for
business shortsightedness is that the judgement of shareholders about winners
and losers is based on quarterly results instead of long-term gains. Are you
aware for example, that although the trading rate on the New York Stock
Exchange is slow enough to turn over all of the securities represented in
about two years,1 many companies trade rapidly enough to turn over in six
months or less? I am particularly offended that pension fund holdings turn
over quite quickly even though pension funds, above all, should take a
long-term view. We seem unable to make the long-term investments required for
economic strength. Is this because, as some say, our cost of capital is too
high? John Maynard Keynes showed that investment decisions are largely
independent of the cost of capital, but depend only on expectations of future
return. Is our inability to face long-term investment related to our
uncertainty about the future of a world harboring nuclear weapons? It can't
be, for other nations make long-term investments. Is our inability to face
long-term investment related to our ethnic diversity, our view of an end to
our abundant supply of raw materials, or is it a symptom of a general
breakdown in family values? I don't know the reasons, but the facts seem
plain: we lack courage, and nations with more courage are eating our lunch.

In 1990 there were 83,605,000,000 shares represented on the exchange with a
total capital value of about $2,814,429,000,000. About 150,000,000 shares trade
each day with a value of about $5,000,000,000.

We desperately need ways to encourage investors to hold onto securities for
longterm gains, and by so doing, encourage them to take an interest in, indeed
demand, that their companies invest for long-term growth. We desperately need
governmental investment in the intellectual infrastructure of an educated
populace confident of the long-term future. We have become a "now" nation to
the extent of jeopardizing our future.

3 Self Encouragement
--------------------

So much for the institutional mechanisms for helping courage surmount risk. Now
let me turn to some more personal ones. I offer the confession that I feel both
inadequately equipped with these mechanisms and all too often unable to apply
those I have. What I find interesting about the need for personal courage in
advanced technology is its elusive nature. When my courage has been strong,
going forward seemed easy; courage seemed unnecessary perhaps, even irrelevant.
When my courage has failed me, however, something else seemed to be wrong; I
could always generate many valid reasons for not moving forward. Courage and
cowardice in technology have seemed to me attributes of other people. I have
been able to recognize them in myself only in hindsight and only by careful
introspection. By describing how my own failures of courage feel to me, I hope
to help you recognize such failures in yourselves. I seek to encourage you. I
mean that literally. I seek to extend your courage by making you aware of your
need for it and by describing some symptoms of its failure. I will offer some
ways to reduce your need for courage, to marshal what courage you can muster,
and to husband your store of it. 

**3.1 Courage to Start**

It's often hard to get started. I always find it hard to start a lecture and so
I cover my difficulty by telling a story. I select a story in advance, one that
is relevant to my topic, familiar enough to me so that I won't muff it, can
establish common ground with my audience, and will make them laugh. If it
works, my story builds rapport with my audience, but more important, their
response encourages me, or literally gives me the courage, to get on with my
topic. How often have you found it hard to get started on something? Have you
ever thought of that difficulty as a failure of courage? Recognizing that there
are risks in starting anything new helps reveal the difficulty of getting
started as a reluctance to overcome those risks. Recognizing that it takes
courage to get started may help in identifying the excuses you have as excuses,
and not reasons. 

**3.2 What it Feels Like to Me**

I feel many different risks in getting started. One common one is that, being
ignorant in the new field, I will make a fool of myself. Many years ago when I
was a ham radio operator, poor operators were called "lids" and were viewed
with some contempt. Faced with such contempt, how was I to learn? Well, for a
while I was a lid. Poor computer programmers are likewise looked on with some
contempt; I have heard their programs described as "wedged." Whenever we start
something new, we must risk being "lids" or writing "wedged" programs. The
risk is real and has kept many people from setting out in new directions. We
prefer to continue with familiar things because they are, on the whole, less
risky than new ones. But my failures of courage to start have never felt to me
like cowardice. Rather, I have been able to invent a host of reasons for not
starting, all perfectly rational, and all quite valid if irrelevant. There are
never enough funds to start the project, and the equipment available is never
quite right. Often the programming languages available do not suit the need,
especially if the procrastinator happens to be expert at making programming
languages and can fix the problem by doing something familiar rather than
getting on with the main task. Are you merely building tools or are you doing
something directly productive? Everything we do has an opportunity cost of
other things not done.  I often use that cost as a reason for procrastination,
thinking that I am too busy, or that the investment of my time to learn
something new is too great. It took me a long time to work up the courage to
face a drawing program on my personal computer because I was just too busy to
"take the time." While I was learning the drawing program I would not be
meeting any of the hundred other demands on my time. In retrospect, I wish I
had learned the drawing program earlier, for not only has it given me great
pleasure, but also it has permitted me to explore some geometric ideas I would
not otherwise have been able to consider. It is all too easy to overemphasize
opportunity cost as a cover for fear; the truth is that I avoided learning to
use the drawing program simply because it was unfamiliar and I risked
frustration and failure. I may have been more sensitive to this risk than some
of you might be, because I achieved some fame from writing an early drawing
program [7]. It would be especially embarrassing for me if I should ask dumb
questions about a drawing program. My unwillingness to learn new things,
risking frustration or failure, is related to another familiar phenomenon.
People love their home towns, the model of car that they drive, the type of
computer they already own, and are especially fond of the text editor most
familiar to them, especially EMACS. We base these loyalties not on comparative
analysis, but on our hidden fears of the unknown.  Make no mistake, it takes
courage to learn a new computer program--you face the risk of frustration at
least, and seeming stupid if you ask dumb questions. By the way, for some time
now I have been far too busy to learn "Excel." 

**3.3 Overcoming Risks**

One start-up aid I have often used is ignorance; to use this approach I avoid
ever measuring the thickness of the ice. I have often been told that it was a
very courageous act to start the Evans and Sutherland company. Had the company
failed, it might have been called foolish rather than courageous, but it
certainly didn't feel courageous to me at the time. I simply had no idea of the
risk I was undertaking. I believe that before people have children they have
little idea of the risks or they might never start. Raising a family is a
courageous act, but only for those who know how hard it is. One of the wonders
of graduate students is that they haven't yet learned all of the things that
can't be done, and so they are willing and able to do some of them.  A warm-up
project is very helpful in getting any new research going. Do something fairly
easy and carry it all the way through from beginning to end.  When I was a new
graduate student at MIT in 1961, I did a project on solving arbitrary wall
mazes by computer. It involved a few thousand lines of computer program and
some simple equipment. Later on, my warm-up project saved me time in my thesis
work by helping me avoid problems that I had solved before.

More important, my warm-up project gave me valuable experience and the courage
that comes with experience. After finishing it, I knew that I could write a
complex computer program and make it work. My warm-up project encouraged me to
go on to the larger programming task involved in thesis work [7] and it
encouraged my sponsors to support the more complex project. My point is that a
warm-up project not only teaches, but also encourages. Some universities,
including MIT, even require a Master's thesis, a formal warm-up project,
before the student embarks on a Ph.D. Remember, "programs are like pancakes­
throw the first one away." 

**3.4 Procedures**

I used to hate washing dishes. I would delay as long as possible. Eyeing the
daunting pile of dishes, I would say to myself, "I'll be here forever at this
dumb task." The enormity of the task deterred me from starting. I still dislike
washing dishes, but I now get the dishes done promptly because I learned a
simple procedure for doing the job from my wife's uncle. The procedure starts
out "Wash first dish..." I have a similar procedure for starting travel
vouchers, it goes "Record first expense..." Each of my little procedures
embodies two different aids to getting started. By invoking a familiar
procedure I reduce my need for courage. By breaking the task into smaller tasks
through emphasizing that only the first dish need be washed or the first
expense need be recorded, I reduce my estimate of risk. Both mechanisms work.
These sources of courage are sometimes called "discipline," especially when
being taught to the young. Discipline relies on a practiced use of routine
subgoals to avoid defeat by fear. Its highest form comes when the Lieutenant,
charging up a heavily defended hill, says, "Follow me men!"--and they do. 

**3.5 Courage to Go On**

"When the going gets tough, the tough go shopping," is the caption to a cartoon
mocking all inveterate shoppers. Its humor comes from our certainty that when
the going gets tough, it takes courage to go on rather than to go shopping.

**3.6 What it Feels Like to Me**

When I get bogged down in a project, the failure of my courage to go on never
feels to me like a failure of courage, but always feels like something
entirely different. One such feeling is that my research isn't going anywhere
anyhow, it isn't that important. Another feeling involves the urgency of
something else. I have come to recognize these feelings as "who cares" and
"the urgent drives out the important." For me, the urgent often takes the form
of a crowded desk that must be cleared. All those letters to write, a
timesheet to bring up to date, bills to pay, checkbook to balance, personal
computer disk to back up, and a host of other easy little routine tasks are
available to help me avoid the difficult big task at hand. Another sense I
have is of the abundance of time remaining to think about the major research
task; after all, the due date for my report is a year or more away.  The other
tasks with closer time horizons seem more urgent and thus should get more
attention. I cower behind my routine little tasks to avoid the risks of
failure associated with working on my main projects. If your research feels
less important than other tasks, examine your courage. Your research may
indeed be unimportant, and it's OK to abandon projects as unsuccessful. In
fact, I believe it takes courage to abandon projects. To remain in research,
however, you must substitute some other research task for the abandoned one
and not simply involve yourself in trivia, however urgent. When examined
critically, the urgency of the little tasks is never so great as I suppose,
nor is the risk of the big tasks so overwhelming. Many successful researchers
recognize that and refuse to let the urgent drive out the important: Alan
Newell of Carnegie Mellon University and Fred Brooks of the University of
North Carolina come to my mind as examples; they share an admirable ability to
decline trivia. 

**3.7 Overcoming Risks**

The inability to produce a new idea is a special risk in research. I have
found that a change of scene helps to gel my thoughts on a new subject. I
escape from the local pressures by going far away in an airplane, or not so
far to a quiet library, or even closer to the seclusion of my study,
particularly early in the morning. The important thing about all these
retreats for me is that I can cast aside the urgent problems; the phone won't
ring, the checkbook can't be balanced, and I can focus on my larger tasks with
a fresh mind. After each of two extended "vacations" in Australia, I returned
with patentable ideas [8, 9], and on a third such trip developed a new
algorithm for building vector quantization code books [13]. I sometimes
jokingly start out describing these ideas by saying, "When I was lying on the
beach..." The combination of a change of location, rest, and lack of
distraction seems to be effective for me. Some universities formalize such
changes as sabbatical leave.  This kind of change of scene works locally too.
Enjoy letting off steam with your family or your drinking buddies. Perhaps it
will give you a fresh viewpoint on your technical problems or at least more
courage to face them. I have often "helped" friends debug their computer
programs merely by asking for an explanation of how the program works. Midway
through the explanation, my friend will strike his head and say, "Oh, that's
the bug." I did nothing but provide the encouragement for one more look at how
the program was supposed to work. Pride offers personal encouragement. We all
have pride in a job well done. I often feel like the child learning to tie his
own shoes determined to do it himself. I think, "I'll show them that I can do
it," so strongly that I must work hard at my task to satisfy my own pride.
Take pride in your work.  When the going gets tough, discipline is another
good mechanism for going on.  My algorithm for washing dishes continues with
the sequence "...WHILE dishes remain, DO wash next dish..." Notice again the
two aids offered by this procedure. First, it makes the task routine; I have a
known procedure to apply.  Second, it limits the task to considering only the
next dish, thus reducing my perception of the risk. Effective novelists write
for several hours every day, successful musicians practice several hours every
day, and successful athletes train several hours every day. Should not a
successful researcher discipline himself to research for several hours every
day? The novelist writes a chapter a day, the musician does his scales and his
selections each day, and the athlete does his setting up exercises and his
main event. Each uses routine subtasks. I believe which particular routine sub
tasks you choose are far less important than that you discipline yourself to
do them regularly. My technology heroes have the courage to devote a period
each day to the important tasks, leaving the merely urgent ones to fester if
necessary.

You can set your own personal deadlines and provide yourself rewards for
meeting them. This mechanism works less well for me, but I do sometimes use
it, often in the most childish way. If I work hard today, I'll permit myself a
drink before dinner or dessert afterwards. In fact, I find that when I am
really engaged in interesting work I forget to eat, but when my work is overly
stressful, I gain weight. Do not overlook family and friends as an explicit
source of encouragement. Affection from family and friends can provide
confidence to face the world outside. A great man once said to me, "Get your
priorities right: family, friends, business, in that order." Another great man
told me, "If things aren't right at home, nothing is right." I find that I am
best able to do creative work when I feel cared for and happy; it is as if I
can devote my finite store of courage either to solving technical problems or
personal ones, but not both at once. 

**3.8 Courage to Talk or Write**

Perhaps the hardest part of research is talking about it, writing about it and
publishing it. Here we really get down to the big risks. When all is said and
done, will my reputation outlast my publishing this very paper? Suppose
someone thinks that my ideas about courage are bad. Suppose I am criticized
for them.  Suppose my writing is inadequate or unacceptable. In truth, it's
often easier to start a project or get on with it than it is to present the
results. Robert Heinlein, author of Stranger In a Strange Land, said in an
editorial on professional authorship that you have to send stories, articles,
and novels to editor after editor and risk rejection slips or you'll never get
published. I know several unpublished authors of incomplete novels. There is
less risk in "writing the great American novel" than in sending it to a
publisher and waiting for it to be rejected. 

**3.9 What it Feels Like to Me**

My own failures of courage to talk or write do not, to me, seem like failures
of courage at all.  Rather, it seems to me that my ideas are unworthy, that no
one would be interested, or that they are not yet well enough expressed.
Recall the maze solving work I did in 1960 as a warm-up project. I was so sure
no one would care about it that I never "bothered" to publish it until 1969
[5]. It turned out that my 1960 work drew questions even many years after
publication, so someone must have cared.

This very talk is another example for me. The chronology of this paper is
shown in Table 1 on the next page. I first began to think about these ideas in
the mid 70's, but it took me until 1982 to first express them publicly. I
wouldn't have done that except that my good friend, Marc Raibert, invited me
to give an informal talk to some new graduate students. That being a low risk
event, I agreed. Next thing I knew the "informal talk" had turned into a
"distinguished lecture" complete with TV camera and an auditorium full of
people, but I was committed, and I talked. Six years later, I finally worked
up the courage to get the video tape transcribed. I was, and still am,
literally too afraid to look at it myself. Now, two more years later, I am
writing the ideas down more formally.

**3.10 Overcoming Risks**

It may be that everyone is embarrassed by his own writing, especially at the
start. That courage to get a paper done is made up of a subcourage to start and
a subcourage to go on, and a subcourage to stop perfecting it. The hardest part
of writing seems to be getting the first rough draft. Of course it won't be
perfect. Of course it won't be complete. But at least a first draft gives you
something to work with and can encourage you to go on. Apply everything you
have learned here to the task of getting that first draft. I have learned three
tricks that make talking and writing easier. First, J. C. R. Licklider taught
me to treat an unfamiliar topic by making lists of things to say. I call this
kind of presentation the "enumeration special." For example, in this paper I
describe four kinds of courage: to start, to go on, to talk or write, and to
stop. The enumeration special is effective, though trite. Second, my late
mother offered advice on the choice of words in English, pointing out that
Anglo-Saxon words have more punch than Roman ones. Just try to think of a Roman
swear word. Unfortunately, technologists seem to think that polysyllabic
circumlocutions are better than short words. Pick Anglo-Saxon names for things
and they will last. Third, because English was spoken long before it was
written, good English writing is always easy to read out loud. I am always
suspicious of single words or phrases placed in parenthesis because they have
no spoken equivalent. Examine each use of the symbols "(" and ")" in your
papers. Do they destroy your ability to read the writing out loud? Could you
rephrase what you have to say in plain English, for example, by using a phrase
instead of a single word in parenthesis? I suspect that parentheses creep into
English writing when the author is either too lazy or too muddled to write down
exactly what he means. Different types of publications are available to
document ideas. Every technical organization has an internal report series.
Technical material for a wider audience appears in conference proceedings,
journal articles, or books. However, I have found greatest value from the least
formal type of publication possible, informal memos. My group at Harvard in
1966 named its series of internal memos the "display file," a pun not only on
the name of the part of computer memory that stores the output picture but also
on the open file cabinet in which we kept these memos for easy access by any
member of our group. My associates and I have used display file memos ever
since to record new ideas, new mathematical formulations, new circuits, and
anything else that strikes our fancy, including local procedures for ordering
lunch. Our series of display file memos has become my archive of familiar
things from the past, an archive to which I turn from time to time for
reminders. Some of them have later become patents, some full-fledged papers,
and some portions of books. Initially, however, each was just my record of some
little idea not always well expressed. 

**3.11 Learning from Others**

Although it obviously takes courage to expose your ideas to criticism, it takes
even more courage to learn from the criticism. The not-invented-here (NIH)
syndrome is rampant in technology. People cling to their own ideas. Naturally,
you and I don't do that, it's just that our ideas, like our favorite text
editor, are better than others.

A good way to learn clearly from what others say to you is to play back their
words immediately to them. I used this mechanism with the industrial sponsors
of the Silicon Structures Project at Caltech. Twice a year we presented our
results at a two day sponsor's meeting. We used the last half day as a feedback
session where each sponsor's representative made comments about our work. I
took careful notes. After each sponsor had spoken, I played back what I thought
he had said. The sponsors liked the immediate feedback because they knew that I
had heard their comments and because they got a chance to correct my notes. I
learned this trick in a class on domestic relations, but it serves well in
nearly any context. 

**3.12 Courage to Stop**

The risk of stopping work on a project is also large. First, there's the loss
of the goal you will never reach.  Second, there's a loss of face in giving up
a task in which you have believed.  Third, there's the waste of the time you
have already invested in the project and the knowledge about it you have
gained. Fourth, there is the criticism you may face for having wasted the
investment. Finally, there is the risk of having to find something new to do. 

**3.13 What it Feels Like to Me**

Failures to stop don't feel like failures of courage to me. Rather they feel
like I'm still "doing my thing." I'm involved with the people and they have
become meaningful to me. I know the vocabulary. Success, it seems, is always
just a month or two away. I know that with just a little more effort, we can
make something really good. The incremental reward always seems to outweigh the
incremental effort.

**3.14 Overcoming Risks**

Ted Meyer and I once noticed that every architecture for a computer display
system can be improved for just a little more money [6].  This kind of
observation offers a reason to stop a research program because it has proven to
be recursive. Another example of a good reason to stop is that you are proven
wrong. Martin Newell and I once spent days trying to prove a geometry theorem
until we discovered a counter example. No wonder it was so hard to prove.

I stopped doing graphics research just after Bob Sproull, Bob Schumacker, and I
wrote A Characterization of Ten Hidden Surface Algorithms [3]. We discovered
that the task of computing which surfaces of a solid object are hidden and
which are visible is a sorting problem. Moreover, we were able to build a
taxonomy for hidden surface algorithms on the basis of the types of sorting
used and the order of variables sorted. Realizing that new hidden surface
algorithms would merely be elaborations on sorting killed my interest in the
problem. Since then, of course, younger and more courageous people have made
ever more beautiful pictures at a pace I cannot hope to match. Maybe the truth
is that I stopped for lack of courage to compete; I don't think so, but I'll
never know.

4 Rewards
---------

**4.1 The Emotional Side of Research**

One of the greatest thrills for me is when a new idea emerges. In 1986, at
Imperial College in London, I was working with complementary metal oxide
semiconductor (CMOS) integrated circuits. I was attempting to design circuits
that would operate very fast, but I had inadequate computer support for
simulating them. Because I couldn't simulate the circuits, I had to think
about the problem instead. Fortunately for me, the circuits I was working on
used a lot of Muller C elements and XOR gates, both of which are symmetric
with respect to ones and zeros at input and output.  Because of this symmetry,
I began to notice that my logic gates behaved as amplifiers, and that the more
complex a logic gate was, the less good it was at amplification. The simplest
inverter makes the best amplifier. It seemed as though each gate had only so
much ability to exert "effort" and could put that effort either into
amplification or into doing logic, but not both. Once I understood the idea, I
gave it the obvious name: "logical effort." Using the idea of logical effort,
and without going to the trouble of optimizing them, I can predict quite
accurately the least possible delay for most CMOS logic circuits, literally on
the back of an envelope. If the optimum circuit is required, I can easily
compute the transistor sizes required for least delay.  More important, I can
decide how to change the topology of the circuit to reduce overall delay.

I want to describe what it felt like to make this discovery. I had worked on
the problem for some months, designing many circuits. About a week before I
finally understood and was able to name logical effort, I began to sense a
distinct and strong feeling that there was an important idea to be found. I can
only describe the feeling as smelling the idea inside the complexity. Much as a
dog is sure a bone is buried beneath the earth, I was sure there was something
simple and beautiful beneath the complexity of my task; I had but to dig it
out. But the idea wasn't captured until I wrote a very crude paper about the
idea for my friend and colleague, Bob Sproull. Bob, I was sure, would be able
both to understand the still slightly vague idea, and to help enunciate it.
Moreover, I was sure that he would not dump criticism on me. From then on, it
was all much easier. The very name, logical effort, captured the essential
feature of the idea. Bob and I formulated the idea, that is, expressed it as a
formula, as the ratio of the electrical capacitance at the input of the logic
gate to the current at its output normalized to the corresponding ability of an
inverter. This ratio turns out also to express how much slower than an inverter
each type of gate will be if driving a gate identical to itself. More complex
logic gates turn out to have higher logical effort; the theory quantifies how
much higher. My second paper on the subject was more understandable, and with
subsequent exposure to a number of students, Bob and I have made the idea of
logical effort very easy to teach. We are now trying to work up the courage to
finish our book on the subject. Naturally it feels as though we do not have the
time.2 Those of us who come after and have the advantage of previous discovery
often forget just how hard those discoveries were. When Steinmetz first used
imaginary numbers to describe alternating current, only very few people
understood the required math. Now every undergraduate electrical engineer
becomes familiar with the square root of minus one, although they spell it j,
rather than i, as mathematicians do. Many of my young friends at Apple Computer
know the Gouraud shading [10] and Phong shading [11] algorithms. When I asked
them who Gouraud and Phong were, none knew that both were graduate students at
the time of their discoveries, nor even thought of them as real people.
Certainly they don't remember, as I do, how hard we thought it would be to make
beautiful pictures by computer before Gouraud and Phong. It's always much
easier in hindsight. Indeed, I think of scientific progress as the reduction of
subjects from complete mystery to teachable form. 2. 1995 update: Still no
book, but we did publish a paper [14] on the subject.

The best personal sources of courage are self confidence and comfort with
yourself and your peers. In some people, these develop early. In others, they
never appear. If you can find things that bolster your own self confidence, you
can use them to good effect. I find that I have only so much room for taking
risks. When I can reduce the risk in some places in my life, I can more easily
face risk in other areas. I provide myself the courage to do some things by
reducing my need for courage in other areas. In effect, I husband my courage.

**4.2 Technology as Play**

The basic personal start-up mechanism for research has to be curiosity. I find
myself curious about how something works, or I observe something strange and
begin to explore it. Because I am fond of symmetry, when I observe some simple
symmetry, I am almost inexorably drawn into exploring it. For example, one day
Don Oestreicher, who was then a graduate student, and I noticed that the number
of random wires expected to cross the midsection of an N terminal printed
circuit board is N/4 independent of whether the wires connect two or three
terminals on the board. This comes about because although the probability of
crossing is higher for wires connecting three terminals, 3/4 rather than 1/2,
the number of wires is correspondingly reduced from N/2 to N/3. This simple
observation led us to explore other wiring patterns, gather some data from real
printed circuit boards, and eventually to publish a paper [4] called How Big
Should a Printed Circuit Board Be? Follow your curiosity. Beauty provides
another form of personal encouragement for me. Some of the products of research
are just pretty, although mathematicians prefer to use the word "elegant." The
simplicity of E=MC 2, the elegance of information theory, and the power of an
undecidability proof are examples. I got interested in asynchronous circuits by
discovering a very simple form of first in first out (FIFO) storage that has
rather complete symmetry [1,8]. It simply amazes me that my simple and
symmetric circuit can "know" which way to pass data forward. The beauty itself
piques my curiosity and flatters my pride. Simplicity is to be valued in
research results. Many students ask, "How long should my thesis be?" It would
be better for them to ask, "How short can it be?" The best work is always
simply expressed. If you find something simple to explore, do not turn it aside
as trivial, especially if it appears to be new. In a very real sense, research
is a form of play in which ideas are our toys and our objective is the creation
of new castles from the old building block set. The courage to do research
comes in part from our attraction to the simplicity and beauty of our
creations. I, for one, am and will always remain a practicing technologist.
When denied my minimum daily adult dose of technology, I get grouchy. I believe
that technology is fun, especially when computers are involved, a sort of grand
game or puzzle with ever so neat parts to fit together. I have turned down
several lucrative administrative jobs because they would deny me that fun. If
the technology you do isn't fun for you, you may wish to seek other employment.
Without the fun, none of us would go on. I tried to capture the spirit of
research as a game in my paper about our walking robot [2]. Unfortunately, the
editors removed from my paper all of the personal comments, the little poem
about the robot by Claude Shannon, the pranks and jokes, and in short, the fun.
The only fun they left was the title: Footprints in the Asphalt. All too often,
technical reports are dull third person descriptions of something far away and
impersonal. Technology is not far away and impersonal. It's here, it's
intensely personal, and it's great fun.

5 Acknowledgements
------------------

This is where I get to recognize my friends, my sponsors and my sources of
encouragement. Thanks to Sara Kiesler whose critical reading was key in making
this paper presentable. Thanks to my partners in business, Dave Evans and Bob
Sproull, for a lifetime of intellectual stimulation and friendship. Special
thanks to my brother, Bert Sutherland, who has both taught and encouraged me
since we were boys. I also thank my children, Juliet and Dean, and the few
other close friends without whose encouragement I would not have been willing
to talk or write about these ideas. The work reported here was supported by
Sutherland, Sproull, and Associates, Inc., independent consultants in computer
hardware and software, and by Advanced Technology Ventures, private investors
in high technology start-up companies.


----------

September 16, 1982 Mid-1983 Mid-1987 April 8, 1988 January 28, 1990 June 1990
September 1990

First presented as a distinguished lecture at CMU Publication suggested by my
daughter, Juliet Video tape obtained from CMU Transcribed from the video tape
Edited into this paper Published by CMU Presented at the 25th anniversary
celebration of the Computer Science Department at CMU


Table 1: 
--------

Chronology of This Document
===========================

My pride demands that this written form of my ideas be perfect. I sought long
and hard for an Anglo-Saxon word combining the ideas of disclose, publish,
report, and talk about. I have finally chosen the compound "talk or write" to
mean all of them, focusing most on public oral presentation, for it seems to
take the most courage. I fear criticism of my choice. In addition, I fear that
you will think my ideas irrelevant, stupid, or even wrong. I fear coming to an
end of this work; at some point I shall have to release this paper to the
publisher and I will have lost a good friend. But in both of these failures of
my courage, during my procrastinating period I did not feel afraid. Rather, I
believed simply that no one would be interested; my ideas seemed unimportant,
irrelevant, and immaterial. I'm still reasonably sure no one will care about my
ideas on courage, but my deadline approaches. Who among my audience has
unpublished work that "no one will care about?" Who among my audience has a
paper partly written but not yet "quite right?" Who the hell are you to judge?
The rule for research is that you get credit only for ideas you have disclosed,
not for ideas kept secret. It is absolutely true that the paper never submitted
is never rejected, but of course, it is never published, either. I believe that
it is better to be the published author of a slightly flawed document than the
unpublished author of a perfect one. Because I spell in original ways and my
handwriting is illegible, writing has always been a great embarrassment to me.
When I got a typewriter half of the problem went away; long ago I learned to
type faster than I can write by hand. With a computer spelling checker that
will make suggestions I am even better off, but not yet free of risk. I
remember well when Claude Shannon, my thesis supervisor, chastised me for
spelling the top to bottom measurement of an electrical wave form "peek to
peek" rather than "peak to peak." I had put, as my Victorian aunt used to say,
"a blot in my copybook." Even today, I'm not sure which spelling is which and
had to look them up in a dictionary because my spelling checker cannot
distinguish cognates. I also once spelled naval incorrectly in a letter to my
brother who was then in the Naval Reserve. Unfortunately, I put that blot on
the outside of the envelope. 


2. 1995 update: Still no book, but we did publish a paper [14] on the subject.

References [1] Sutherland, I.E. "Micropipelines." Communications of the ACM.
June 1989. [2] Sutherland, I.E., and Ullner, M.K. "Footprints in the Asphalt."
The International Journal of Robotics Research. Vol. 3, No. 2. Summer 1984, MIT
Press. [3] Sutherland, I.E., Sproull, R.F., and Schumacker, R.A. "A
Characterization of Ten HiddenSurface Algorithms." Computing Surveys: Journal
of the ACM. March 1974. Summarized in Naval Research Reviews. June 1975, pp.
21-23. [4] Sutherland, I.E., and Oestreicher, D. "How Big Should a Printed
Circuit Board Be?" IEEE Transactions of Computers. Vol. C22, May 1973, pp.
537-542. [5] Sutherland, I.E. "A Method of Solving Arbitrary Wall Mazes by
Computers." IEEE Transactions on Computers. Vol. C18, No. 12, December 1969,
pp. 10921097. [6] Myer, T.H., and Sutherland, I.E. "On the Design of Display
Processors." Communications of the ACM. June 1968, Vol. 11, No. 6, pp. 410-414.
[7] Sutherland, I.E. "Sketchpad--A ManMachine Graphical Communication System."
Proceedings of the Spring Joint Computer Conference, Detroit, Michigan. May
1963, and MIT Lincoln Laboratory Technical Report #296, January 1963. [8]
Sutherland, I.E. "Asynchronous First-In-First-Out Register Structure." United
States Patent 4,837,740, June 6, 1989. [9] Sutherland, I.E. "Reaction Control
Valve." United States Patent 4,622,992. November 18, 1986. [10] Gouraud, H.
"Computer Display of Curved Surfaces." University of Utah, UTEC-CSc-71-113.
June 1971, and in IEEE Transactions C-20, 623, June 1971. [11] Phong, B.T.
"Illumination for Computer-generated Images." University of Utah,
UTEC-CSc-73-129, July 1973, and in CACM, 18(6):311:317, June 1975. [12] May,
Rollo. The Courage to Create. Bantam Books, New York, 1975.


[13] Sutherland, I.E. and Sproull, R. "Comparison for Codebook Generation
Techniques for Vector Quantization." [14] Sutherland, I. E. and Sproull, R.
"Logical Effort. Designing for Speed on the Back of an Envelope," IEEE Advanced
Research in VLSI, C. Sequin, ed. MIT Press, 1991. [15] Sutherland, I.E.
"Technology and Courage," CMU Compter Science. A 25th Anniversary
Commemorative. Ed. Rashid, R. ACM Press, 1991. Technology and Courage is also
available on the World Wide Web.

.. |copy| unicode:: 0xA9 .. copyright sign
