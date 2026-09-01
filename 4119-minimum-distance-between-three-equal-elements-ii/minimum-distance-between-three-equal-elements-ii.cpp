class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> pos(n + 1);
        
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            pos[x].push_back(i);

            int sz = pos[x].size();

            
            if (sz >= 3) {
                int a = pos[x][sz - 3];
                int c = pos[x][sz - 1];

                ans = min(ans, 2 * (c - a));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};