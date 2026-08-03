class Solution {
public:
    static const int MOD = 1e9 + 7;

    int limit;
    int dp[201][201][2];

    int solve(int zero, int one, int last) {

        if (zero == 0 && one == 0)
            return 1;

        if (dp[zero][one][last] != -1)
            return dp[zero][one][last];

        long long ans = 0;

        if (last == 0) {

            for (int take = 1; take <= limit && take <= one; take++) {
                ans += solve(zero, one - take, 1);
                ans %= MOD;
            }

        } else {

            for (int take = 1; take <= limit && take <= zero; take++) {
                ans += solve(zero - take, one, 0);
                ans %= MOD;
            }
        }

        return dp[zero][one][last] = ans;
    }

    int numberOfStableArrays(int zero, int one, int lim) {

        limit = lim;

        memset(dp, -1, sizeof(dp));

        long long ans = 0;

       
        for (int take = 1; take <= limit && take <= zero; take++)
            ans = (ans + solve(zero - take, one, 0)) % MOD;

       
        for (int take = 1; take <= limit && take <= one; take++)
            ans = (ans + solve(zero, one - take, 1)) % MOD;

        return ans;
    }
};