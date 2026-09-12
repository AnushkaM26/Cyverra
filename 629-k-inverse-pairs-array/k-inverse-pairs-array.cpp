class Solution {
public:
    int kInversePairs(int n, int k) {
        const int mod = 1e9 + 7;

        vector<int> dp(k + 1), ndp(k + 1);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            long long s = 0;

            for (int j = 0; j <= k; j++) {
                s += dp[j];

                if (j >= i)
                    s -= dp[j - i];

                s = (s + mod) % mod;
                ndp[j] = s;
            }

            dp.swap(ndp);
        }

        return dp[k];
    }
};