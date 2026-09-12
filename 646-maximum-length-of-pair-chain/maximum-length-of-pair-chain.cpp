class Solution {
public:
    int findLongestChain(vector<vector<int>>& p) {
        sort(p.begin(), p.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        int ans = 0;
        int last = -1000000;

        for (auto &x : p) {
            if (x[0] > last) {
                ans++;
                last = x[1];
            }
        }

        return ans;
    }
};