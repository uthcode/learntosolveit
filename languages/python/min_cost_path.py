# min_cost_path.py - 26-04-2020 09:11

from typing import List

# Video: https://www.youtube.com/watch?v=lBRtnuxg-gU


class Solution:

    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        T = [[0] * n for _ in range(m)]
        # First left top corner cost is same.
        T[0][0] = grid[0][0]

        # First row in T
        for first_row_idx in range(1, n):
            T[0][first_row_idx] = T[0][first_row_idx-1] + grid[0][first_row_idx]

        # First col in T
        for first_col_idx in range(1, m):
            T[first_col_idx][0] = T[first_col_idx-1][0] + grid[first_col_idx][0]

        # Fill in the rest of the 2D matrix for T.
        for i in range(1, m):
            for j in range(1, n):
                T[i][j] = grid[i][j] + min(T[i-1][j],   # top
                                           T[i][j-1])   # left

        # value to reach the right most end
        return T[-1][-1]


if __name__ == '__main__':
    s = Solution()
    mat = [
        [1, 3, 1],
        [1, 5, 1],
        [4, 2, 1]
    ]
    print((s.minPathSum(mat)))
