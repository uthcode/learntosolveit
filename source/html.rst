====
HTML
====

:: 

        * The current version in use is HTML 4.01
        * Always quote attribute values in the HTML.
        * Use lowercase tag names.
        * Common html attributes are class, id, style and title.
        * Search engines use headings to index the structure and the content of the
          webpages.
        * Browsers automatically adds an empty line before and after paragraphs.
        * Use the  <br/> tag if you want a line break (a new line) without starting a
          new paragraph.
        * In XHTML, XML and future versions of HTML, elements with no end tags are not
          allowed. Even though  <br> works on most browsers, <br/>  is more future
          proof.
        * With HTML you cannot change the format of the output by adding extra spaces
          etc. The browser will remove extra spaces and extra lines when the page is
          displayed.
        * What is the difference between bold and strong tags. what is the difference
          between emphasize and italics tag.
        * <del>will delete</del>  and  <ins> will insert </ins>  this text.
        * Of other tags, code defines the computer code text.
        * bdo - bi directional override tag defines the display direction of text,
          <bdo dir="rtl"></bdo> or <bdo dir="ltr"> </bdo> 
        * <q> Quotation</q>  tags are used for short quotations. Browser will insert
          quotation marks. For long quotations, the  <blockquote>  tag is used.


        <blockquote> 
        It was a JOKE!!  Get it??  I was receiving messages from DAVID LETTERMAN!!
        YOW!!
        </blockquote> 


        * The style attribute is new to HTML attribute. It introduces CSS to HTML.
        * These tags should be avoided,  <center>, <font> and <basefont>, <s> and
          <strikeout/> and <u>.  These attributes should be avoided, align, bgcolor,
          color. Use styles instead.
        * Hyperlink is a reference to the resource on the web.
        * When the name attribute is used, the <a> element defines a named anchor
          inside a HTML document.
        * Always add a trailing slash to subfolder references. If you link like this:
          href="http://www.w3schools.com/html", you will generate two HTTP requests to
          the server, because the server will add a slash to the address and create a
          new request like this: href="http://www.w3schools.com/html/" 

          <a name="section">This Section</a>  wont create any visible differences, but
          when accessed like this  <a href="#section">Go to Section</a>  that will lead
          you to the named section.

         img tag is empty. It contains attributes only and no closing tag.

        Definition list starts with dl, dt denotes definition term and dd stands for
        definition description.  <fieldset> tag is to make the form as  group with a
        caption in the form of a <legend> tag.

         The World Wide Web Consortium (W3C) has listed 16 valid color names for HTML
          and CSS: aqua, black, blue, fuchsia, gray, green, lime, maroon, navy, olive,
          purple, red, silver, teal, white, and yellow. 

        * <link>  tag goes inside the <head> section.

Project Idea
============

* In your webpage, have the 8 queens generated. No gifs. Also have keyboard
  accesskey attribute.
