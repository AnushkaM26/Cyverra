class Solution:
    def countSubmatrices(self, grid, k):
        m = len(grid)
        n = len(grid[0])

        prefix = [0] * n
        ans = 0

        for i in range(m):
            row_sum = 0

            for j in range(n):
                row_sum += grid[i][j]
                prefix[j] += row_sum

                if prefix[j] <= k:
                    ans += 1
                else:
                    break

        return ans