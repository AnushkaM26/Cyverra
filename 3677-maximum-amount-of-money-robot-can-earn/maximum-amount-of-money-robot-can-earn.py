class Solution:
    def maximumAmount(self, coins):
        m = len(coins)
        n = len(coins[0])

        neg = -10**15
        dp = [[[neg] * 3 for _ in range(n)] for _ in range(m)]

        dp[0][0][0] = coins[0][0]

        if coins[0][0] < 0:
            dp[0][0][1] = 0

        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue

                val = coins[i][j]

                for k in range(3):
                    best = neg

                    if i > 0:
                        best = max(best, dp[i - 1][j][k])

                    if j > 0:
                        best = max(best, dp[i][j - 1][k])

                    if best != neg:
                        dp[i][j][k] = best + val

                    if val < 0 and k > 0:
                        best = neg

                        if i > 0:
                            best = max(best, dp[i - 1][j][k - 1])

                        if j > 0:
                            best = max(best, dp[i][j - 1][k - 1])

                        dp[i][j][k] = max(dp[i][j][k], best)

        return max(dp[m - 1][n - 1])