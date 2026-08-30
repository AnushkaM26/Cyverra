class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const long long MOD = 1000000007;

        for (auto &query : queries) {
            int l = query[0];
            int r = query[1];
            int k = query[2];
            long long v = query[3];

            for (int idx = l; idx <= r; idx += k) {
                nums[idx] = (nums[idx] * v) % MOD;
            }
        }

        int ans = 0;

        for (int x : nums) {
            ans ^= x;
        }

        return ans;
    }
};