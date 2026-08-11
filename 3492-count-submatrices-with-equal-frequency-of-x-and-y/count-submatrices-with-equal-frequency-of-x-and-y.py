class Solution:
    def numberOfSubmatrices(self, grid):
        m = len(grid)
        n = len(grid[0])

        x = [[0] * n for _ in range(m)]
        y = [[0] * n for _ in range(m)]

        ans = 0

        for i in range(m):
            for j in range(n):

                cur_x = 1 if grid[i][j] == 'X' else 0
                cur_y = 1 if grid[i][j] == 'Y' else 0

                x[i][j] = cur_x
                y[i][j] = cur_y

                if i > 0:
                    x[i][j] += x[i - 1][j]
                    y[i][j] += y[i - 1][j]

                if j > 0:
                    x[i][j] += x[i][j - 1]
                    y[i][j] += y[i][j - 1]

                if i > 0 and j > 0:
                    x[i][j] -= x[i - 1][j - 1]
                    y[i][j] -= y[i - 1][j - 1]

                if x[i][j] == y[i][j] and x[i][j] > 0:
                    ans += 1

        return ans