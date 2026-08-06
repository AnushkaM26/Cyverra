class Solution {
    int MOD = 1000000007;

    public int countPalindromicSubsequences(String s) {
        int n = s.length();
        long[][] dp = new long[n][n];

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                if (s.charAt(i) == s.charAt(j)) {
                    int left = i + 1;
                    int right = j - 1;

                    while (left <= right && s.charAt(left) != s.charAt(i)) {
                        left++;
                    }

                    while (left <= right && s.charAt(right) != s.charAt(i)) {
                        right--;
                    }

                    if (left > right) {
                        dp[i][j] = dp[i + 1][j - 1] * 2 + 2;
                    } else if (left == right) {
                        dp[i][j] = dp[i + 1][j - 1] * 2 + 1;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1] * 2 - dp[left + 1][right - 1];
                    }
                } else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                }

                dp[i][j] %= MOD;
                if (dp[i][j] < 0) {
                    dp[i][j] += MOD;
                }
            }
        }

        return (int) dp[0][n - 1];
    }
}