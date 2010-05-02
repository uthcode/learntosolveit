================
Perl Programming
================

Links
=====

* `Perl Tutorial`_.

.. _Perl Tutorial: http://www.comp.leeds.ac.uk/Perl/start.html

* scalars are the variable and you prefix them with $ like $variablename
* Double Quote strings do the processing of the variables within it.
* Single Quote strings do the literal substitution of the the variables.

:: 

        $hello='Hello,World';
        print "$hello\n";

* Interestingly, I had named that program as `hello.py`. :) It obsviously would
  work. (Magic spell perhaps).
* Arrays are denoted by @ character.
* push(@arrayname, `"value"`) is a good way to add "value" to the array
  `@arrayname`.
* push function returns the length of the new list.

:: 

        @newarray = ("one","two","three");
        print push(@newarray);

        Output: 3

* just the @arrayname returns the length.
* opposite of push is the pop, which returns the last element.
* having the array within `" "` processes the values and returns them space
  separated. The delimiter can be changed by changing `$"` variable.

::

        @foodlist = ("dosa","idly","parota","kesari","poori");
        print push(@foodlist)."\n";
        print pop(@foodlist)."\n";
        print @foodlist."\n";
        $val1 = @foodlist;
        print $val1."\n";
        $"='-';
        $val2 = "@foodlist";
        print $val2."\n";

        OUTPUT:
        5
        poori
        4
        4
        dosa-idly-parota-kesari

* The index of the last element can be got by `$#@arrayname`.
* To read from a file, perl uses angled brackets.

:: 

        $file = '/etc/passwd';
        open(INFO, "$file");
        @lines = <INFO>;
        close(INFO);
        print @lines;

* Do while loop, getting from the STDIN.

:: 

        print "Password? ";
        $a = <STDIN>;
        chop $a;

        while ($a ne "Senthil")
        {
                print "Sorry, try again:";
                $a = <STDIN>;
                chop $a;
        }
        print "Good Guess: $a \n";

* chop function removes the last character of the string.
* Programming Exercise. Appending # in front using `$"` and appending line
  numbers, 1,2,3.. and 01,02,..039 while printing lines from a file.


::

        $file = '/etc/passwd';
        open(INFO, "$file");
        @lines = <INFO>;
        close(INFO);
        $"="#";
        print "#@lines";

        $lineno = "0001";
        open(INFO,"$file");
        while ($line = <INFO>)
        {
                print "$lineno $line";
                $lineno++;
        }
        close(INFO);


* One of the most useful features of Perl is its powerful string matching facilities.
* Regular expression is contained within /'s and matching occurs with =~ operator.
* =~ is match, !~ is does not match.
* $_ is the current string, which /regex/ would act upon.

:: 

        $_ = "Sharma is in Australia right now, probably playing rugby";

        if (/Australia/)  # This is the match expression.
        {
                print "Down under";
        }

* In regex, \b stands for word boundary. get the meaning of it properly.
* Special read only variables, $`, $& and $' represents what was matched
  before, during and after the search.
* Associative Arrays are like dictionaries.
* Unlike list array, the associative arrays are indexed by {} probably because
  they are fancier.

:: 

        %associative = ("one",1,
                        "two",2,
                        "three",3);

        print $associative{"one"}."\n";

        @listarray = %associative;

        print "@listarray\n";
        print $listarray[0]."\n";
        print $listarray[1]."\n";

        %newassociative = @listarray;

        print $newassociative{"three"}."\n";

* there is keys function, values function and each function (key, value).
* functions are called subroutines.
* the subroutine is called with the & character in front of its name.
* Parameters are passed in the special @_ list variable and individual elements can be accessed by $_[index] value.

:: 

        sub mysub
        {
                print "Hello,World\n";
        }

        &mysub;

        sub mysub2
        {
                print @_;
                print $_[1];
        }

        &mysub2("Hello",1,"World");
        
* Result of the subroutine is always the last thing that was evaluated. Its
  fun! No return statement. In case of print as the last it is 1.
* variables can be made local with the local function.

:: 

        sub inside
        {
                local($a,$b) = ($_[0], $_[1]);
                $a =~ s/\ //g;
                $b =~ s/\ //g;
                (($a =~ /$b/) || ($b =~ /$a/));
        }

        print &inside("henry", "Man and his hen rye");

* The rule is simple: in Perl, parentheses for built-in functions are never
  required nor forbidden. Their use can help or hinder clarity, so use your own
  judgment.
* qw - quote each of the words.
* whitespace is generally insignificant in any perl programs.
* my defines the variables inside it to be private within the enclosing block.
