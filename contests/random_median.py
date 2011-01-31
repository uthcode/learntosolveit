"""
The basic idea of the median algorithm is to pick one of the numbers in the
group at random, and count how many of the numbers in the group are less than
it. Lets say there are N numbers, and K of them are less than or equal to the
number we picked at random. If K is less than half of N, then we know that the
median is the (N/2-K) th number that is greater than the random number we
picked, so we discard the K numbers less than or equal to the random number.
Now, we want to find the (N/2-K) th smallest number, instead of the median. The
algorithm is the same though, and we simply pick another number at random, and
repeat the above steps.
"""
