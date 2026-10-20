=================================================
4.8 getch and ungetch handling pushback character
=================================================

Question
========

Suppose that there will never be more than one character of pushback. Modify
getch and ungetch accordingly.


.. literalinclude:: cprogs/ex_4.8_getch_ungetch_pushback.c
   :language: c


Explanation
===========

This program maintains a character buffer `char buf=0` which holds a single
character from the input. The function `ungetch(c)` when called places the
character in the input and `getch()`, if it finds the character in the buf,
returns it or it calls `getchar` to get character from the user.


Visualize the Full Solution
---------------------------

.. raw:: html

   <iframe width="100%" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%23include%20%3Cstdio.h%3E%0A%0Achar%20buf%20%3D%200%3B%0A%0A/*%20getch%3A%20get%20a%20%28possibly%29%20pushed%20back%20character%20*/%0Aint%20getch%28void%29%0A%7B%0A%20%20%20%20int%20c%3B%0A%0A%20%20%20%20if%28buf%20!%3D%200%29%0A%20%20%20%20%20%20%20%20c%20%3D%20buf%3B%0A%20%20%20%20else%0A%20%20%20%20%20%20%20%20c%20%3D%20getchar%28%29%3B%0A%0A%20%20%20%20buf%20%3D%200%3B%0A%20%20%20%20return%20c%3B%0A%7D%0A%0A/*%20ungetch%3A%20push%20a%20character%20back%20into%20input%20*/%0Avoid%20ungetch%28int%20c%29%0A%7B%0A%20%20%20%20if%28buf%20!%3D%200%29%0A%20%20%20%20%20%20%20%20printf%28%22ungetch%3A%20too%20many%20characters%5Cn%22%29%3B%0A%20%20%20%20else%0A%20%20%20%20%20%20%20%20buf%20%3D%20c%3B%0A%7D%0A%0Aint%20main%28void%29%0A%7B%0A%20%20%20%20int%20c%3B%0A%0A%20%20%20%20c%20%3D%20'*'%3B%0A%0A%20%20%20%20ungetch%28c%29%3B%0A%0A%20%20%20%20while%28%28c%3Dgetch%28%29%29%20!%3D%20EOF%29%0A%20%20%20%20%20%20%20%20putchar%28c%29%3B%0A%0A%20%20%20%20return%200%3B%0A%7D&codeDivHeight=400&codeDivWidth=350&cumulative=true&curInstr=0&heapPrimitives=false&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=true"> </iframe>

Try It
======


.. raw:: html

   <figure style="margin:0;border:1px solid #e2e8f0;border-radius:8px;overflow:hidden"><iframe src="https://coddy.tech/embed-editor?lang=c&theme=light&layout=stacked&code=I2luY2x1ZGUgPHN0ZGlvLmg-CgpjaGFyIGJ1ZiA9IDA7CgovKiBnZXRjaDogZ2V0IGEgKHBvc3NpYmx5KSBwdXNoZWQgYmFjayBjaGFyYWN0ZXIgKi8KaW50IGdldGNoKHZvaWQpCnsKICAgIGludCBjOwoKICAgIGlmKGJ1ZiAhPSAwKQogICAgICAgIGMgPSBidWY7CiAgICBlbHNlCiAgICAgICAgYyA9IGdldGNoYXIoKTsKCiAgICBidWYgPSAwOwogICAgcmV0dXJuIGM7Cn0KCi8qIHVuZ2V0Y2g6IHB1c2ggYSBjaGFyYWN0ZXIgYmFjayBpbnRvIGlucHV0ICovCnZvaWQgdW5nZXRjaChpbnQgYykKewogICAgaWYoYnVmICE9IDApCiAgICAgICAgcHJpbnRmKCJ1bmdldGNoOiB0b28gbWFueSBjaGFyYWN0ZXJzXG4iKTsKICAgIGVsc2UKICAgICAgICBidWYgPSBjOwp9CgppbnQgbWFpbih2b2lkKQp7CiAgICBpbnQgYzsKCiAgICBjID0gJyonOwoKICAgIHVuZ2V0Y2goYyk7CgogICAgd2hpbGUoKGM9Z2V0Y2goKSkgIT0gRU9GKQogICAgICAgIHB1dGNoYXIoYyk7CgogICAgcmV0dXJuIDA7Cn0&credit=0" width="100%" height="500" style="display:block;border:0;width:100%" title="C code editor by Coddy" loading="lazy"></iframe><figcaption style="box-sizing:border-box;padding:5px 12px;font:11px/1.4 system-ui,-apple-system,sans-serif;color:#64748b;background:#f1f5f9;border-top:1px solid #e2e8f0;text-align:right" dir="ltr">Powered by <a href="https://coddy.tech/embed" target="_blank" rel="noopener" style="color:#0077ff;font-weight:600;text-decoration:none;">Coddy</a></figcaption></figure>

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20single%20global%20%27saved%27%20holds%20at%20most%20one%20pushed-back%20char%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Astatic%20int%20saved%20%3D%20-1%3B%0Avoid%20ungetch%28int%20c%29%20%7B%20saved%20%3D%20c%3B%20%7D%0Aint%20%20getch%28void%29%20%20%20%20%7B%20int%20c%20%3D%20saved%3B%20saved%20%3D%20-1%3B%20return%20c%3B%20%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20ungetch%28%27A%27%29%3B%0A%20%20%20%20printf%28%22getch%3D%25c%5Cn%22%2C%20getch%28%29%29%3B%20%20%20%20%20%20%20%2F%2A%20A%20%2A%2F%0A%20%20%20%20printf%28%22getch%3D%25d%20%28empty%29%5Cn%22%2C%20getch%28%29%29%3B%20%2F%2A%20-1%20%2A%2F%0A%20%20%20%20ungetch%28%27B%27%29%3B%0A%20%20%20%20ungetch%28%27C%27%29%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%2F%2A%20overwrites%20B%20%2A%2F%0A%20%20%20%20printf%28%22getch%3D%25c%5Cn%22%2C%20getch%28%29%29%3B%20%20%20%20%20%20%20%2F%2A%20C%20%2A%2F%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
