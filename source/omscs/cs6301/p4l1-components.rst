.. title: P4L1 Components 
.. slug: P4L1 Components 
.. date: 2016-05-27 23:57:20 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

P4L1 Components
===============


01 - Bottom Up Design
---------------------

So far in this course we have been primarily concerned with top-down design.


That is, when given a set of requirements come up with a set of pieces, connect them together and refine.


In this lesson we will go the other way.


Start with self contained pieces called components and put them together to build systems.


02 - Components
---------------

1


Pieces that we put together are called components.


2


However, don't get this use of the term components, confused with the one that


3 we talked about when we were discussing software architectures.


4


Here's the definition that we will use for this lesson.


5


A component is, an executable unit of independent production, acquisition and


6 deployment, that can be composed into a functioning subsystem.


7


The definition and other material for


8 this lesson is taken from the book by Clemens Szyperski, and from the paper by


9


Liwen Wang, both of which I have listed on the class resources page.


03 - Buy vs Build
-----------------

To place the use of components into context.


I want to describe a typical situation that often arises during industrial software development.


The decision has to do with acquiring software assets.


Should you construct them yourself?


Or buy them from somewhere else?


This is sometimes called the buy versus build decision.


04 - Buy Quiz
-------------

Below are some business factors to take into consideration when deciding whether to buy a software component from a
third-party vendor.


For each, determine whether the factor is enhanced or diminished if you decide to buy.


Put a plus next to factors that are benefitted and a minus next to factors that are diminished.


First, your uniqueness with respect to your competitors.


Second, the amount of your staff time required to develop the product of which the component is a part.


Third, your overall production costs.


And fourth, your control of the development process.


05 - Buy Quiz Solution
----------------------

When you buy a component from somebody else, you're giving up your competitive advantage.


You didn't build it yourself, so you can't put into it the bells and whistles that might give you that advantage.


On the other hand, the vendor can concentrate all their energy on that particular component and come up with a super-
specialized version.


So that's an, an advantage of buying.


Your development costs may also go down.


That is, the vendor can apply economies of scale, thereby reducing the price you have to pay for that, that component.


However, dealing with a vendor is a third party relationship, and the channels of communication that you have with the
vendor may not be as effective as the ones you would have if you did in-house development.


06 - Build
----------

Building means in house custom development.


The advantages and disadvantages mirror those of buying.


The build solution may cost you more, because you don't have the same economies of scale that a vendor might have.


However, you can tailor what you build to your own situation.


You also retain control of its intellectual property.


However, overall delivery risk is increased when you build things yourself.


07 - The Third Way
------------------

Buy versus build is a tough decision.


Sapersky however, describes a third way.


Using third-party components that you can customize during assembly.


In general with components, you get the risk and cost reduction benefits of the buy solution while enjoying the
flexibility of the build solution


08 - Third Party Quiz
---------------------

Here's a little quiz to get you thinking about the buy versus build decision.


In addition to buying complete applications or components, there are several other ways that third parties can provide
computational resources to a client.


Match the examples in column one with a category in column two.


Column one includes PThreads, the National Institute of Science and


Technology's Time Dervice.


Tom-Tom GPS, Checkstyle code checker and PHP.


The categories include open source software, turn-key equipment, IDE plugins.


Cloud-based services and software libraries.


09 - Third Party Quiz Solution
------------------------------

Well, PThreads is an example of a software library.


The NIST Time Service however, is a cloud based service.


You get the current time off of the internet.


Tom-Tom GPS is a piece of turn-key equipment.


Checkstyle is an IDE plugin.


And PHP is open source software.


10 - Characterizations of Components
------------------------------------

Now I'd like to take a minute to characterize components.


They are pre-existing and general, making them reusable in a variety of contexts.


The question arises, what does it mean to manufacture a component.


Well to manufacture a component you just have to copy it.


So the manufacturing costs are quite low.


You can configure a component with respect to your needs and target environment.


That is, there's a great deal of flexibility involved when you have components.


The components that property built can be easily composed with each other and with noncomponent code.


Components conform to a software component model that prescribes their syntax and semantics, and how they are composed.


We will look into example software component models a little later.


11 - Component Life Cycle
-------------------------

First, let's take a minute to look at the component life cycle.


Components are produced by external developers.


Hence, instead of the normal breakdown between development time and runtime, there are really three phases to consider.


Design time, deployment time and runtime.


At design time, components are specified and built.


During deployment, binaries are configured and deployed into target execution environment.


At runtime, components are instat, instantiated and executed.


As we shall see, major differences exist between component technologies depending on when composition takes place and
whether a repository for the components exists.


12 - Component Models
---------------------

Inherent in any component technology is that technology's component model, also called the component's framework.


A component model is a set of shared assumptions about the component syntax, semantics and composition.


Component syntax includes how components are specified, which need not be in the same language as the one in which they
are implemented.


The semantics prescribes what information is in the component's contract and what is the nature of the environment in
which the component runs.


Component composition specifies how components work with other components.


13 - Component Models Quiz
--------------------------

Here's a brief quiz on the component models.


You might have heard of WordPress, it is a content management solution for blogs.


Here are some requirements taken from the WordPress codex, for requirement stocking.


For each requirement, determine whether it concerns component syntax, component semantics, or component composition.


The first requirement states, any text output by the Action function, will appear in the page sources at the locations
where the action was invoked.


Secondly, use well-structured, error-free PHP and valid HTML.


The third requirement states, actions are triggered by specific events that take place in WordPress, such as publishing
a post, changing themes, or displaying an administration screen.


The action is a custom PHP function, defined in your plugin, and hooked that is set to respond to some of these events.


14 - Component Models Quiz Solution
-----------------------------------

Well, requirement one, about any text output by the action function will appear in the page source, that's an example of
component semantics.


That is, it describes what the component will do.


The second requirement concerning well-structured, error-free PHP and HTML, that's all about syntax.


And the third requirement stating how the actions integrate with PHP is concerned with component composition.


15 - Examples of Component Models
---------------------------------

Here are examples of some popular and representative component models.


First off, from the Sun Microsystems, now Oracle Enterprise Solution, there are Enterprise Java Beans also called EJB.


Included in this is J2EE and JSP, which is Java Server Pages.


Of course, they compete with Microsoft and


Microsoft offers COM, which is the component object model,


DCOM, the distributed COM, OLE, ActiveX, and COM+ for transactions.


Microsoft also offers .NET and in .NET there were technologies such as the common language infrastructure, CLI, and the
common language runtime, CLR, and ASP.NET.


An older component technology is CORBA and its component model is called CCM.


CORBA itself stands for the Common Object Request Broker.


And it comes from the Object Management group.


It includes an Object Management Architecture and an Interface Description Language called IDL.


Finally and more generically, there's web services.


These include web service description language, WSDL, Universal Description,


Discover and Innovation markup, also called UDDI.


And the Simple Object Access Protocol SOAP.


16 - Issues
-----------

To understand components better, we will now look at some of the issues that component vendor has to face when offering
a component technology to the marketplace.


The issues that we'll look at are configuration, versioning, extension mechanisms, callbacks, contracts, using objects
as components, scaling, and domain standards.


17 - Issue 1 Configuration
--------------------------

The first issue is configuration.


It may not be apparent from the discussion so far that components are typically configurable.


What this means is that the component vendor provides a means, such as a configuration file, by which the client using a
component can tailor it to a particular situation.


This gives to the designer a powerful means for managing design trade-offs.


For example, space versus time.


This flexibility that configuration gives comes at a cost, however.


Because configuration is a form of late binding, it becomes difficult to unit test the components in the actual usage
environment.


It is also more expensive to document and to deploy them.


18 - Issue 2 Versioning
-----------------------

The second issue is versioning, which can be tricky.


As new versions of the components are released, backward compatibility becomes a problem.


If you are a component vendor, you need to keep your customers up to date with changing standards, new programming
language releases, and enhanced features.


The question then becomes, to what extent should you remain compatible with previous versions?


Think of the issue from the customer's point of view.


They have a working product.


It will cost them time and energy to upgrade to a new version of your component, and there's a risk of breaking their
system if they do so.


If they don't need the new feature that you are offering, they're going to be reluctant to upgrade.


From your point of view, however, this may mean you've got to maintain and support a long history of previous versions
at additional expense.


Moreover, if there are multiple components involved, each with their own versions, you have an explosion in the number
of combinations you have to support.


What's a poor vendor to do?


19 - Versioning Strategy
------------------------

Vendors have come up with a variety of strategies for dealing with component versioning issues.


At a minimum, version numbers are used.


When deployment is performed the version number is used to perform a compatibility check.


Other strategies that vendors have taken include the following.


Some vendors have ad hoc compatibility rules.


That is the rules pertain to the particular version and change between versions.


Some vendors claim that they have immutable interfaces, that is the vendor promises never to change the interface.


Some vendors guarantee backward compatibility.


Changes can be made but old versions are guaranteed to continue working.


Some vendors have sliding windows of supported versions.


That is, they will, support the previous five versions or the previous three versions.


Some vendors take a middle ground saying they're going to break compatibility only with major releases that include
major new features.


20 - Automobile Components Quiz
-------------------------------

To think about these third-party component situations, think for a minute about what third-party components the
automobile manufacturers rely on.


See if you can come up with a few and type them into the text box.


21 - Automobile Components Quiz Solution
----------------------------------------

Of course tires are manufactured by third parties, batteries, and the fluids in your car.


Sometimes the manufacturer will sell them, but also there are third parties that can supply oil and transmission fluid,
and windshield washer fluid, and so on.


Often, the brakes can come from third parties, typically mufflers do as well


22 - Issue 3 Extensions
-----------------------

The third issue has to do with Extensions.


Components are often extended by adding new features.


Recall that we met features and features diagrams when we looked at architectural views.


When the vendors add new features complicating situations may arise.


For example, the particular situation might require that there be exactly one instance of that particular component.


This is sometimes called a singleton extension.


If there are multiple components involved, we might want to ensure that at most one of the, one has this new feature
added to it.


Related to that is what happens if there are parallel extensions of, of multiple components in the same dimension.


If we do allow the same feature, feature to be configured into multiple components, we may need to be aware of the
possibility of resource contention, if each version, version of that component is trying to get access to the same
resource.


Sometimes there are non-orthogonal extensions, and we have to be careful of possible feature interactions, if a customer
configures in more than one new feature at the same time.


And then there are recursive extensions.


Some component models support adding components that can themselves be extended.


This may mean that the component vendor loses control of what components are actually deployed.


23 - Issue 4 Callbacks
----------------------

The fourth issue is concerned with a technical consideration, the use of callbacks.


A callback is an operation provided by the client.


When a specified event is detected by component, the client operation is invoked.


Callbacks can be a powerful tool that components can be use for interacting with a client, but they come with a price.


System integrity may be compromised during the time in which the client is in control.


Here is the situation.


24 - Invariants
---------------

Typically, the modules in a system are responsible for maintaining invariants.


That is, they have to make sure they are in a consistent state before and after executing each service they provide.


The same holds true for components, which are just third-party modules.


However, the presence of callbacks makes invariant maintenance much more difficult.


In particular, during the time when the client is handling the callback request, the component is vulnerable.


Because it has given up control to the client, there's a danger that the client may do something that breaks the
invariant, like make another call to the component.


25 - Callback Example
---------------------

Here’s an example.


If your client code is making use of the GUI toolkit component that allows the n users to type into a text box the
client code can register the name of a callback operation that should be invoked when the end user types into a, types
into the field.


During the period of this call the client callback operation has access not only to the event itself, but the other
elements of the component state, such as the type text, the specific text box, and even the pixel position of the cursor
on the screen.


The client can take advantage of this information to do things like suggest completions or fix spelling mistakes.


Imagine further that while com-, computing possible work completions, the client makes a direct call to the GUI
component asking it to display a message.


When the callback code eventually returns control the component there is no guarantee that the state of the text box is
the same as it was before.


It might not even be visible anymore.


26 - Callbacks Quiz
-------------------

To check if you understand this, try the following quiz.


Consider this sequence diagram describing a typical callback situation in which a Component captures a user event and
invokes a client method via a callback.


During the process, the Component is subject to corruption during which time period indicated by consecutive letters in
the left margin?


27 - Callbacks Quiz Solution
----------------------------

Well, the answer is between events D and E.


That is while the client is actually processing the callback itself.


28 - Callback Summary
---------------------

To summarize, the advantage of callbacks is that the component can provide a structured regime of calling within which
the client executes.


The regime can orchestrate the order of operations in a way that the client would have to do by itself using the tradi,
using a traditional approach.


For example, the regime might provide an event loop.


The cost of using callbacks is that the component state is exposed to the client at a time when it might not be
internally consistent.


That is, using callbacks makes it more difficult for components to guarantee their integrity.


29 - Issue 5 Contracts and Guarantees
-------------------------------------

The fifth issue has to do with the contracts the components provide and, and the guarantees they provide with them.


Because components are provided by third parties, there, there is an increased need for a clear specification of what
they are promising.


On the class resources page, there's a paper by that lays out the different levels of guarantee that a component
provider might promise.


30 - Level 1 Signature Contracts
--------------------------------

We'll take the four levels from the simplest to the most powerful.


The simplest form of contract that Boniyar calls level one guarantee is a syntactic or signature contract, in which the
names and arguments of the component operations are specified.


Thus guaranteeing it is possible to link components into an application.


Can't really imagine using components in which you don't have this, this level of guarantee.


31 - Level 2 Correctness Contract
---------------------------------

More powerful is, a correctness guarantee, in which the pre and post conditions are specified by all, for all callable
operations, thus guaranteeing that the component operations successfully execute.


We've seen OCL is a good candidate for expressing correctness contracts.


32 - Level 3 Collaboration Contracts
------------------------------------

Level three has to do with collaboration contracts in which allowed interactions among components are specified.


Addressing issue, issues such as synchronization, liveness and deadlock.


The set of allowed interactions for a components complies that component's protocol.


33 - Level 4 Quality of Service Contracts
-----------------------------------------

The highest level of guarantee, also the one that's hardest to provide, is called the quality of service guarantee.


In these guarantees, non-functional requirements are addressed, such as availability, mean time between failures, mean
time to repair, throughput, latency, data integrity, and capacity.


Such an example of such a guarantee would be that the component operates with a throughput of some number of
transactions given in a, in a given time period.


34 - Guarantees Quiz
--------------------

To test your understanding of this, consider the following snippets taken from the Oracle documentation of the format
method in the Java PrintStream class.


Classify each of these snippets as to the guarantee level.


The first snippet states data formats are not synchronized.


It is recommended that you create separate format instances for each thread.


If multiple threads access a format concurrently, it must be synchronized externally.


The second snippet is a snippet taken directly from the Java code for


PrintStream format method, including its arguments and the name of the method.


The third snippet comes from the context of the throw's IllegalFormatException.


It states that if a format string contains illegal syntax, a format specifier that is incompatible with the given
arguments, insufficient arguments given the format string, or other illegal conditions, then the IllegalFormatException
is thrown.


35 - Guarantees Quiz Solution
-----------------------------

Well the first snippet, which has to do with synchronization, is a level three guarantee stating what the collaboration
conditions are.


Snippet B, which is actual program text, has to do with level one guarantee saying, what are the names and types of the
arguments, so they can be linked in when you actually run your program.


And the third one, even though it states something about the syntax of the format string, is really a level two
guarantee talking about the correctness contract between the client and this particular class.


36 - Summary of Contracts
-------------------------

To summarize contracts, when purchasing a third-party component.


The customer needs to know what he or she is getting.


One way to do this is to see a specification of the component that covers all four levels of guarantees.


The alternative is to learn about restrictive limitations later when it may be quite expensive to overcome them


37 - Issue 6 Objects as Components
----------------------------------

The sixth issue is also technical in nature.


It has to do with using objects as components.


It is tempting to identify objects and components, and many component technologies do exactly that, for example,
JavaBeans.


After all, both objects and components represent encapsulated state that supports operations.


However, there are problems that arise when using objects to implement components.


38 - Object as Component Problems
---------------------------------

We've already seen the problems with callbacks.


And, of course, object-oriented programming language can have lots of callbacks.


And an object which has the ability to make calls to self or this, which are self-referencing methods, compounds this
problem.


In general, with objects, it becomes much more difficult to guarantee contracts in the face of object callbacks and
inter-method calls.


The problem is even worse in the presence of multi-threading.


Other problems like inheritance and fragile base class definitions are discussed in the next few slides.


39 - Inheritance Dangers
------------------------

We have previously talked about the danger of using inheritance to implement generalization.


If objects are used for components and if inheritance is used inappropriately, then subclass objects may violate
component contracts.


40 - Fragile Base Class Problem
-------------------------------

Another problem with using objects for components is known as The Fragile Base Class problem.


This occurs when a new version of a component changes one of, of its base classes.


Our existing derived class is broken.


Imagine you've been using an object-like component by deriving from one of its base classes.


Now your component vendor says that the new release of the component has changed the base class.


Can you continue to run?


Do you have to recompile?


Do you, do you have to rewrite?


41 - Issue 7 Industry Scaling
-----------------------------

The seventh issue has to do with scaling and here I mean scaling in the sense of the industry scaling up.


As the component entry grows and evolves, a raft of new questions arises.


For example, accounting.


How should component use be charged, particularly in clients in which there are multiple components coming from
different vendors.


With respect to deployment and configuration, how are components packaged and how is configuration performed?


There's lots of packaging technologies out there such as RPM,


DMG, EPKG, Nix, and OSG.


What about disputes?


How do you deal with an unhappy customer if multiple components with different vendors from different vendors are
involved?


How about quality of service?


How are quality of service guarantees satisfied when multiple inde-, independent components are used?


And then there's fault containment and air handling.


How do components detect and contain faults when they are not in control, in overall control of execution?


42 - Issue 8 Domain Standards
-----------------------------

The last set of issues has to do with domain standards.


One area of ongoing concern is the component, in the component marketplaces, the role of domain standards where there's
a tension between proprietary solutions and open standards.


Dominant vendors try to lock in customers with proprietary technology, while the competition promotes the use of
standards to encourage customer migration.


In the longterm the community benefits from standard solutions.


However, such standards take a long time for approval and penetration.


43 - Proprietary or Domain Quiz
-------------------------------

1


Here's a short quiz about this issue.


2


For each of the technologies below, enter a P for


3 proprietary technologies and D for domain standard.


4


The technologies include HTML, Direct3D, UNIX, OpenGL, Java and JavaScript.


44 - Proprietary or Domain Quiz Solution
----------------------------------------

1


First off,


2


HTML is a domain standard, maintained by the World Wide Web Consortium.


3


In contrast, UNIX is proprietary.


4


It was first developed by AT&T and later sold to various other companies.


5


Direct3D is a propriety graphics API, for


6 rendering 2D and 3D graphics which was designed by Microsoft.


7


Contrary-wise, OpenGL is an open standard graphics API and a competitor to 3D.


8


The other two are interesting.


9


Java, which originally started in an open fashion,


10 being released by Sun Microsystems, is now proprietary.


11


Whereas JavaScript, which originally started from Microsoft,


12 was put into the public domain.


45 - Component Framework
------------------------

Earlier I mentioned the role of component frameworks.


Let's now take a look at some prominent frameworks to get a better feel for how the vendors are addressing the issues we
have raised.


46 - Shared Attributes
----------------------

These frameworks typically all provide late binding, persistence, encapsulation and sub-typing.


They provide support for communication among components including events, channels and uniform data transfer mechanisms.


They also offer some form of component transfer packaging, such as JavaJar files, ComCab files, or CLI assemblies.


They all provide a way of describing deployments such as via configuration file.


This description is also typically available at runtime via mechanisms such as


Reflection or metadata.


Any given framework provides a way of serving, of serving components such as an application server model like EJB,


COM+ and CCM or web server models like JSP and ASP.Net.


47 - Comparison of Differences
------------------------------

The framework vendors however had made some design decisions that differentiate their approaches.


For example, they often differ on memory management.


Java and CLR provide garbage collection, COM provides reference counting, and


CORBA doesn't provide anything at all.


As far as container managed persistence is concerned,


Java has Enterprise Java Beans.


CORBA has CCM, but CLR and Compost don't provide anything.


The vendors also have various approaches for the versioning, some of them freeze, some of them have version numbers,
some of them have compatibility rules, and some of them allow for side-by-side execution.


Some other differences include the target environment for the component frameworks.


J2EE and COM target servers.


COM also targets client and desktop machines, whereas CORBA targets legacy applications.


They all also differ in terms of their development environments.


J(2)EE uses WebSphere, which is the commercial version of Eclipse.


And .NET uses Visual Studio .NET.


As far as protocols are concerned, Java and CORBA support IIOP and XML.


Java supports, also supports RMI.


COM and CLR support DCOM.


And CLR supports XML and SOAP.


48 - Comparison of Supported Variability
----------------------------------------

It is also important to look at how the component frameworks differ in as far as their support for variability is
concerned.


Recall that one of the key advantages of components and their late finding is the fact that there's some flexibility
provided to their customer.


As far as Java and


CLI are concerned, they use a single virtual machine for all platforms.


Many languages can generate byte codes that target those particular platforms.


COM also supports many languages, but on Microsoft platforms only.


CORBA supports, supports multiple languages, but each of the, each of the languages must its own IDL binding.


Each platform must also have an object request broker running on that particular platform.


49 - Future Directions
----------------------

The component marketplace is real and more continue to grow.


This is going to bring customers the benefits of well-defined, tested and supported, and documented solutions.


Nevertheless, there are some ongoing concerns that need to be addressed.


How about liability?


When a system that uses a component fails, how is liability apportioned among all the vendors that have provided
components to it?


Quality guarantees.


How can cross cutting quality of service requirements be addressed in a multiple component environment?


If the quality of service has to do with performance which of the components is responsible for providing the
performance guarantees?


Well all of them.


And the third question to be looked at.


Contract persistent over versions.


What is the white balance between new versions and support for incompatible exis, existing features?


50 - Summary
------------

The advent of viable component marketplace has opened up a whole new approach to building software applications.


Providing some of the flexibility that comes with building your own solution without incurring all the associated risks.


You can therefore expect components and their frameworks to be part of the design thinking that goes into many future
development projects.


