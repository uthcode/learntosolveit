=============
Min Cost Path
=============

Question
--------

Given a m x n grid filled with non-negative numbers, find a path from top left
to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Problem Source: https://leetcode.com/problems/minimum-path-sum/

Solution
--------

.. literalinclude:: ../../languages/python/min_cost_path.py
   :language: python
   :tab-width: 4


Explanation
-----------

.. youtube:: lBRtnuxg-gU


Visualize
---------

* `Visualize Min Cost Path in PythonTutor`_


.. _Visualize Min Cost Path in PythonTutor: http://www.pythontutor.com/live.html#code=from%20typing%20import%20List%0A%0A%23%20Video%3A%20https%3A//www.youtube.com/watch%3Fv%3DlBRtnuxg-gU%0A%0A%0Aclass%20Solution%3A%0A%0A%20%20%20%20def%20minPathSum%28self,%20grid%3A%20List%5BList%5Bint%5D%5D%29%20-%3E%20int%3A%0A%20%20%20%20%20%20%20%20m%20%3D%20len%28grid%29%0A%20%20%20%20%20%20%20%20n%20%3D%20len%28grid%5B0%5D%29%0A%20%20%20%20%20%20%20%20T%20%3D%20%5B%5B0%5D%20*%20n%20for%20_%20in%20range%28m%29%5D%0A%20%20%20%20%20%20%20%20%23%20First%20left%20top%20corner%20cost%20is%20same.%0A%20%20%20%20%20%20%20%20T%5B0%5D%5B0%5D%20%3D%20grid%5B0%5D%5B0%5D%0A%0A%20%20%20%20%20%20%20%20%23%20First%20row%20in%20T%0A%20%20%20%20%20%20%20%20for%20first_row_idx%20in%20range%281,%20n%29%3A%0A%20%20%20%20%20%20%20%20%20%20%20%20T%5B0%5D%5Bfirst_row_idx%5D%20%3D%20T%5B0%5D%5Bfirst_row_idx-1%5D%20%2B%20grid%5B0%5D%5Bfirst_row_idx%5D%0A%0A%20%20%20%20%20%20%20%20%23%20First%20col%20in%20T%0A%20%20%20%20%20%20%20%20for%20first_col_idx%20in%20range%281,%20m%29%3A%0A%20%20%20%20%20%20%20%20%20%20%20%20T%5Bfirst_col_idx%5D%5B0%5D%20%3D%20T%5Bfirst_col_idx-1%5D%5B0%5D%20%2B%20grid%5Bfirst_col_idx%5D%5B0%5D%0A%0A%20%20%20%20%20%20%20%20%23%20Fill%20in%20the%20rest%20of%20the%202D%20matrix%20for%20T.%0A%20%20%20%20%20%20%20%20for%20i%20in%20range%281,%20m%29%3A%0A%20%20%20%20%20%20%20%20%20%20%20%20for%20j%20in%20range%281,%20n%29%3A%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20T%5Bi%5D%5Bj%5D%20%3D%20grid%5Bi%5D%5Bj%5D%20%2B%20min%28T%5Bi-1%5D%5Bj%5D,%20T%5Bi%5D%5Bj-1%5D%29%20%20%0A%0A%20%20%20%20%20%20%20%20%23%20value%20to%20reach%20the%20right%20most%20end%0A%20%20%20%20%20%20%20%20return%20T%5B-1%5D%5B-1%5D%0A%0As%20%3D%20Solution%28%29%0Amat%20%3D%20%5B%0A%20%20%20%20%20%20%20%20%5B1,3,1%5D,%0A%20%20%20%20%20%20%20%20%5B1,5,1%5D,%0A%20%20%20%20%20%20%20%20%5B4,2,1%5D%0A%20%20%20%20%5D%0Aprint%28s.minPathSum%28mat%29%29&cumulative=false&heapPrimitives=false&mode=display&origin=opt-live.js&py=3&rawInputLstJSON=%5B%5D&textReferences=true



.. git_changelog::


.. seealso::

   * :python-suggest-improve:`min_cost_path.py`
   * :python-better-explain:`min_cost_path.rst`

