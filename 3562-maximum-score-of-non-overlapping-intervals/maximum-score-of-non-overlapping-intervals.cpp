class Solution {
public:
    using P = pair<long long, vector<int>>;

    vector<int> maximumWeight(vector<vector<int>>& v) {
        int n = v.size();

        vector<array<long long, 4>> a(n);

        for (int i = 0; i < n; i++)
            a[i] = {v[i][0], v[i][1], v[i][2], i};

        sort(a.begin(), a.end());

        vector<int> nx(n);

        for (int i = 0; i < n; i++) {
            int l = i + 1, r = n;

            while (l < r) {
                int m = (l + r) / 2;

                if (a[m][0] > a[i][1])
                    r = m;
                else
                    l = m + 1;
            }

            nx[i] = l;
        }

        vector<vector<P>> dp(5, vector<P>(n + 1, {0, {}}));

        for (int k = 1; k <= 4; k++) {
            for (int i = n - 1; i >= 0; i--) {
                P x = dp[k][i + 1];

                P y = dp[k - 1][nx[i]];
                y.first += a[i][2];
                y.second.push_back(a[i][3]);

                sort(y.second.begin(), y.second.end());

                if (y.first > x.first ||
                    (y.first == x.first && y.second < x.second))
                    dp[k][i] = y;
                else
                    dp[k][i] = x;
            }
        }

        return dp[4][0].second;
    }
};