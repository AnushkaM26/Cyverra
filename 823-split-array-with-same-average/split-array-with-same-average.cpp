class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int tot = 0;
        for (int x : nums) tot += x;

        vector<bool> ok(n + 1, false);
        for (int c = 1; c < n; c++)
            if (tot * c % n == 0) ok[c] = true;

        int half = n / 2;
        unordered_map<int, unordered_set<int>> left;
        for (int m = 0; m < (1 << half); m++) {
            int cnt = 0, sum = 0;
            for (int i = 0; i < half; i++)
                if (m >> i & 1) { cnt++; sum += nums[i]; }
            left[cnt].insert(sum);
        }

        int rest = n - half;
        for (int m = 0; m < (1 << rest); m++) {
            int cnt = 0, sum = 0;
            for (int i = 0; i < rest; i++)
                if (m >> i & 1) { cnt++; sum += nums[half + i]; }
            for (int c = 1; c < n; c++) {
                if (!ok[c]) continue;
                int need = tot * c / n - sum;
                if (left.count(c - cnt) && left[c - cnt].count(need)) {
                    if (c == n && cnt == n) continue;
                    return true;
                }
            }
        }
        return false;
    }
};