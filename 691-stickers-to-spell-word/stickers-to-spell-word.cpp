class Solution {
public:
    int minStickers(vector<string>& s, string t) {
        int m = t.size(), n = s.size();
        vector<int> dp(1 << m, 100);
        vector<vector<int>> c(n, vector<int>(26));

        for (int i = 0; i < n; i++)
            for (char x : s[i])
                c[i][x - 'a']++;

        dp[0] = 0;

        for (int mask = 0; mask < (1 << m); mask++) {
            if (dp[mask] == 100) continue;

            for (int k = 0; k < n; k++) {
                vector<int> v = c[k];
                int nm = mask;

                for (int i = 0; i < m; i++) {
                    if (!(nm & (1 << i)) && v[t[i] - 'a']) {
                        v[t[i] - 'a']--;
                        nm |= 1 << i;
                    }
                }

                dp[nm] = min(dp[nm], dp[mask] + 1);
            }
        }

        return dp[(1 << m) - 1] == 100 ? -1 : dp[(1 << m) - 1];
    }
};