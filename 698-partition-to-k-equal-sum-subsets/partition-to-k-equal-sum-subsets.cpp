class Solution {
public:
    bool canPartitionKSubsets(vector<int>& a, int k) {
        int n = a.size(), sum = 0;
        for (int x : a) sum += x;

        if (sum % k) return false;

        int tar = sum / k;
        vector<int> dp(1 << n, -1);
        dp[0] = 0;

        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[mask] == -1) continue;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) continue;
                if (dp[mask] + a[i] <= tar) {
                    int nm = mask | (1 << i);
                    dp[nm] = (dp[mask] + a[i]) % tar;
                }
            }
        }

        return dp[(1 << n) - 1] == 0;
    }
};