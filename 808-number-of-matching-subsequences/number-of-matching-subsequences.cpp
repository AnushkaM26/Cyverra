class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> pos(26);
        for (int i = 0; i < s.size(); i++)
            pos[s[i] - 'a'].push_back(i);

        int cnt = 0;
        for (string& w : words) {
            int cur = -1;
            bool ok = true;
            for (char c : w) {
                auto& v = pos[c - 'a'];
                auto it = upper_bound(v.begin(), v.end(), cur);
                if (it == v.end()) { ok = false; break; }
                cur = *it;
            }
            if (ok) cnt++;
        }
        return cnt;
    }
};