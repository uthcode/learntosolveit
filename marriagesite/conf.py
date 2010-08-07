# -*- coding: utf-8 -*-
# Configuration file for marriagesite

import string

allquotes = """\
I love being married.  It's so great to find that one special person you want to annoy for the rest of your life.  -- Rita Rudner
%%
Love seems the swiftest but it is the slowest of all growths.  No man or woman really knows what perfect love is until they have been married a quarter of a century.  -- Mark Twain
%%
Never take someone for grantes. Hold every person close to your heart because you might wake up one day and realise that you've lost a diamond while you were too busy collecting stones.
%%
Two souls with but a single thought, two hearts that beat as one - john keats
%%
A successul marriage requires falling in love many time, always with the same person.
%%
The beginning of love is to let those we love be perfectly themselves, and not to twist them to fit our own image. Otherwise we love only the reflection of ourselves we find in them. -- Thomas Merton
%%
The best and most beautiful things in the world cannot be seen nor even touched, but just felt in the heart. --  Helen Keller, The Story of My Life
%%
Love sought is good, but giv'n unsought is better.  -- William Shakespeare in Twelfth Night (Act III, Scene I)
%%
The goal in marriage is not to think alike, but to think together.  -- Robert C. Dodds
%%
Who here is god? You and me. Life is a penance. Love is god.For the theists, God is love .For the good among atheists, Love is the only god. --  Anbe Sivam Song.
%%
The throb of life is love. Without it, humans are bodies of bones clad with skin. Tiruvalluvar, Tirukkural: 80
%%
At the evening of life, we shall be judged on our love. --  John of the Cross, reported in the Catechism of the Catholic Church (2002), p. 231
%%
It’s a magical world, Hobbes, ol’ buddy... Let’s go exploring! –:Calvin and Hobbes
"""
quotes = map(string.strip,allquotes.split('%%'))
