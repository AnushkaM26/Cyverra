class Solution {
public:
    vector<int> parent, rankv;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (rankv[a] < rankv[b])
            swap(a, b);

        parent[b] = a;

        if (rankv[a] == rankv[b])
            rankv[a]++;
    }

    int minimumHammingDistance(vector<int>& source,
                               vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {
        int n = source.size();

        parent.resize(n);
        rankv.assign(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (auto &swapPair : allowedSwaps) {
            unite(swapPair[0], swapPair[1]);
        }

        vector<unordered_map<int, int>> mp(n);

        for (int i = 0; i < n; i++) {
            int root = find(i);
            mp[root][source[i]]++;
        }

        int answer = 0;

        
        for (int i = 0; i < n; i++) {
            int root = find(i);

            if (mp[root][target[i]] > 0) {
                mp[root][target[i]]--;
            } else {
                answer++;
            }
        }

        return answer;
    }
};