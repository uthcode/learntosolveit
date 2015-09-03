===============================
Process each word in a sentence
===============================

Question
--------

Find words in the sentence and process each word.

Solution
--------

.. literalinclude:: ../../languages/python/files_processing_every_word.py
   :language: python
   :tab-width: 4

.. runcode:: ../../languages/python/files_processing_every_word.py
   :language: python
   :codesite: ideone

Explanation
===========

The program creates a REGEX for matching words and uses regex.finditer(line)
to find all the words matching the regular expression in a line.

Running the program over itself produces the output like this.

::

    import
    re
    WORD_REGEX
    re
    compile
    r
    w'-
    def
    do_something_with_word
    word
    print
    word
    def
    words_in_file
    file_name
    with
    open
    file_name
    as
    fh
    for
    line
    in
    fh
    for
    word
    in
    WORD_REGEX
    finditer
    line
    do_something_with_word
    word
    group
    0
    def
    main
    words_in_file
    '
    files_processing_every_word
    py'
    if
    __name__
    '__main__'
    main

.. git_changelog::


.. seealso::

   * :python-suggest-improve:`files_processing_every_word.py`
   * :python-better-explain:`files_processing_every_word.rst`

