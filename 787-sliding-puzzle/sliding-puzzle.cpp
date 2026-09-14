class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& b) {
        string s = "";

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                s += char(b[i][j] + '0');

        string t = "123450";

        vector<vector<int>> adj = {
            {1, 3},
            {0, 2, 4},
            {1, 5},
            {0, 4},
            {1, 3, 5},
            {2, 4}
        };

        queue<string> q;
        unordered_set<string> vis;

        q.push(s);
        vis.insert(s);

        int d = 0;

        while (!q.empty()) {
            int n = q.size();

            while (n--) {
                string x = q.front();
                q.pop();

                if (x == t)
                    return d;

                int z = x.find('0');

                for (int p : adj[z]) {
                    string y = x;
                    swap(y[z], y[p]);

                    if (!vis.count(y)) {
                        vis.insert(y);
                        q.push(y);
                    }
                }
            }

            d++;
        }

        return -1;
    }
};