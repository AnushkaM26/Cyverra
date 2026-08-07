class Solution:
    def orderOfLargestPlusSign(self, n, mines):
        grid = [[1] * n for _ in range(n)]

        for x, y in mines:
            grid[x][y] = 0

        dp = [[n] * n for _ in range(n)]

        for i in range(n):
            count = 0
            for j in range(n):
                if grid[i][j] == 1:
                    count += 1
                else:
                    count = 0
                dp[i][j] = min(dp[i][j], count)

        for i in range(n):
            count = 0
            for j in range(n - 1, -1, -1):
                if grid[i][j] == 1:
                    count += 1
                else:
                    count = 0
                dp[i][j] = min(dp[i][j], count)

        for j in range(n):
            count = 0
            for i in range(n):
                if grid[i][j] == 1:
                    count += 1
                else:
                    count = 0
                dp[i][j] = min(dp[i][j], count)

        ans = 0

        for j in range(n):
            count = 0
            for i in range(n - 1, -1, -1):
                if grid[i][j] == 1:
                    count += 1
                else:
                    count = 0

                dp[i][j] = min(dp[i][j], count)
                ans = max(ans, dp[i][j])

        return ans