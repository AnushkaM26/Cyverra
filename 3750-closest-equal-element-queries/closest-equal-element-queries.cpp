class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> answer;

        for (int idx : queries) {
            vector<int>& positions = mp[nums[idx]];

            if (positions.size() == 1) {
                answer.push_back(-1);
                continue;
            }

            int k = lower_bound(
                positions.begin(),
                positions.end(),
                idx
            ) - positions.begin();

            int m = positions.size();

            int prev = positions[(k - 1 + m) % m];

            int next = positions[(k + 1) % m];

            int distPrev = abs(idx - prev);
            distPrev = min(distPrev, n - distPrev);

            int distNext = abs(idx - next);
            distNext = min(distNext, n - distNext);

            answer.push_back(min(distPrev, distNext));
        }

        return answer;
    }
};