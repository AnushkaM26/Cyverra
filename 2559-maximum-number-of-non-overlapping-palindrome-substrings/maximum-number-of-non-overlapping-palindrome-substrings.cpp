class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<vector<bool>> p(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1]))
                    p[i][j] = true;
            }
        }

        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; i++) {
            dp[i + 1] = dp[i];
            for (int j = 0; j + k - 1 <= i; j++) {
                if (p[j][i])
                    dp[i + 1] = max(dp[i + 1], dp[j] + 1);
            }
        }

        return dp[n];
    }
};