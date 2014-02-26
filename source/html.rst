==========================
Hyper Text Markup Language
==========================

The current version in use is HTML 4.01. Always quote attribute values in the
HTML.Use lowercase tag names. Common html attributes are class, id, style and
title. Search engines use headings to index the structure and the content of
the webpages. Browsers automatically adds an empty line before and after
paragraphs. Use the  <br/> tag if you want a line break (a new line) without
starting a new paragraph.

In XHTML, XML and future versions of HTML, elements with no end tags are not
allowed. Even though  <br> works on most browsers, <br/>  is more future proof.
With HTML you cannot change the format of the output by adding extra spaces
etc. The browser will remove extra spaces and extra lines when the page is
displayed.

What is the difference between bold and strong tags. what is the difference
between emphasize and italics tag.  <del>will delete</del>  and  <ins> will
insert </ins>  this text.  Of other tags, code defines the computer code text.
bdo - bi directional override tag defines the display direction of text, <bdo
dir="rtl"></bdo> or <bdo dir="ltr"> </bdo>. <q> Quotation</q>  tags are used
for short quotations. Browser will insert quotation marks. For long quotations,
the  <blockquote>  tag is used.

<blockquote> 
It was a JOKE!!  Get it??  I was receiving messages from DAVID LETTERMAN!!
YOW!!
</blockquote> 

The style attribute is new to HTML attribute. It introduces CSS to HTML.  These
tags should be avoided,  <center>, <font> and <basefont>, <s> and <strikeout/>
and <u>.  These attributes should be avoided, align, bgcolor, color. Use styles
instead.

Hyperlink is a reference to the resource on the web. When the name attribute is
used, the <a> element defines a named anchor inside a HTML document.

Always add a trailing slash to subfolder references. If you link like this:
href="http://www.w3schools.com/html", you will generate two HTTP requests to
the server, because the server will add a slash to the address and create a new
request like this: href="http://www.w3schools.com/html/" 

<a name="section">This Section</a>  wont create any visible differences, but
when accessed like this  <a href="#section">Go to Section</a>  that will lead
you to the named section. img tag is empty. It contains attributes only and no
closing tag.

Definition list starts with dl, dt denotes definition term and dd stands for
definition description.  <fieldset> tag is to make the form as  group with a
caption in the form of a <legend> tag.

The World Wide Web Consortium (W3C) has listed 16 valid color names for HTML
and CSS: aqua, black, blue, fuchsia, gray, green, lime, maroon, navy, olive,
purple, red, silver, teal, white, and yellow. <link>  tag goes inside the
<head> section.

Styles don't smell or taste anything like HTML, they have a format of
'property: value' and most properties can be applied to most HTML tags.

But, if you remember, the best-practice approach is that the HTML should be a
stand-alone, presentation free document, and so in-line styles should be
avoided wherever possible.

aqua, black, blue, fuchsia, gray, green, lime, maroon, navy, olive, orange,
purple, red, silver, teal, white, and yellow. transparent is also a valid
value.

In the CSS, a class selector is a name preceded by a full stop (.) and an ID
selector is a name preceded by a hash character (#).

The difference between an ID and a class is that an ID can be used to identify
one element, whereas a class can be used to identify more than one.


CSS
---

Lochlan: it's easy to write though..
Lochlan: if your html is structed well
Lochlan: you target elements at the top of your css, like body, h1, h2, p, ul, ol
Lochlan: give classes to elements that are repeated
Lochlan: target with .className
Lochlan: and give IDs to elements that only appear once on the page (like structure divs) #wrap
Lochlan: with css you effect the position and other styles of the element that you target
Lochlan: that's the basics



Questions
---------
a) What could be a reason for nesting of div elements.
b) fieldset tag?

W3C's Documents
---------------

http://www.w3.org/standards/webdesign/

Chessboard design
-----------------

http://designindevelopment.com/css/css3-chess-board/
http://www.w3.org/TR/html4/interact/forms.html
