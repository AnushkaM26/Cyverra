import java.util.*;

class Solution {

    int MOD = 1000000007;
    int limit;
    Long[][][] dp;

    public int numberOfStableArrays(int zero, int one, int limit) {
        this.limit = limit;
        dp = new Long[zero + 1][one + 1][2];

        long ans = 0;

        for (int i = 1; i <= Math.min(limit, zero); i++) {
            ans = (ans + solve(zero - i, one, 0)) % MOD;
        }

        for (int i = 1; i <= Math.min(limit, one); i++) {
            ans = (ans + solve(zero, one - i, 1)) % MOD;
        }

        return (int) ans;
    }

    private long solve(int zero, int one, int last) {
        if (zero == 0 && one == 0) {
            return 1;
        }

        if (dp[zero][one][last] != null) {
            return dp[zero][one][last];
        }

        long ways = 0;

        if (last == 0) {
            for (int i = 1; i <= Math.min(limit, one); i++) {
                ways = (ways + solve(zero, one - i, 1)) % MOD;
            }
        } else {
            for (int i = 1; i <= Math.min(limit, zero); i++) {
                ways = (ways + solve(zero - i, one, 0)) % MOD;
            }
        }

        dp[zero][one][last] = ways;
        return ways;
    }
}