import optparse
from timeit import Timer

from getlist import random_list

from selection import selectionsort
from insertion import insertionsort
from bubble import bubblesort
from shellsort import shellsort
from quicksort import quicksort
from mergesort import mergesort

from bisectionsort import bisectionsort

list_to_sort = random_list(1000)


def time_test():
    print 'selection sort:',
    selectionsort = Timer("gosort = list_to_sort[:];selectionsort(gosort)",
                          "from __main__ import list_to_sort, selectionsort;"
                          )
    print selectionsort.timeit(number=10)

    print 'insertion sort:',
    insertionsort = Timer("gosort = list_to_sort[:];insertionsort(gosort)",
                          "from __main__ import list_to_sort, insertionsort;"
                          )
    print insertionsort.timeit(number=10)

    print 'bubble sort:',
    bubblesort = Timer("gosort = list_to_sort[:];bubblesort(gosort)", 
                       "from __main__ import list_to_sort, bubblesort;"
                       )
    print bubblesort.timeit(number=10)

    print 'shell sort:',
    shellsort = Timer("gosort = list_to_sort[:];shellsort(gosort)", 
                       "from __main__ import list_to_sort, shellsort;"
                       )
    print shellsort.timeit(number=10)

    print 'quick sort:',
    quicksort = Timer("gosort = list_to_sort[:];quicksort(gosort)", 
                       "from __main__ import list_to_sort, quicksort;"
                       )
    print quicksort.timeit(number=10)

    print 'merge sort:',
    mergesort = Timer("gosort = list_to_sort[:];mergesort(gosort)", 
                       "from __main__ import list_to_sort, mergesort;"
                       )
    print mergesort.timeit(number=10)
  
    print 'bisection sort:',
    bisectsort = Timer("gosort = list_to_sort[:];bisectionsort(gosort)", 
                       "from __main__ import list_to_sort, bisectionsort;"
                       )
    print bisectsort.timeit(number=10)

    print 'sorted function on list:',
    sortedfn = Timer("gosort = list_to_sort[:];sorted(gosort)",
                     "from __main__ import list_to_sort"
                    )
    print sortedfn.timeit(number=10)

    print 'sort method on list object:',
    sortmethod = Timer("gosort = list_to_sort[:];gosort.sort()", 
                       "from __main__ import list_to_sort"
                      )
    print sortmethod.timeit(number=10)

if __name__ == '__main__':
    parser = optparse.OptionParser()
    parser.add_option('-t','--timeit',action='store_true',dest='timeit',default=False)
    options, arguments = parser.parse_args()
    if options.timeit:
        time_test()
    else:
        pass

