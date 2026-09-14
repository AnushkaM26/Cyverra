#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int s, int d, int k) {
        vector<vector<pair<int,int>>> g(n);
        for (auto &e : f) g[e[0]].push_back({e[1], e[2]});

        vector<int> c(n, INT_MAX);
        c[s] = 0;

        queue<int> q;
        q.push(s);

        int st = 0;

        while (!q.empty() && st <= k) {
            int sz = q.size();
            vector<int> nx = c;

            while (sz--) {
                int u = q.front(); q.pop();
                for (auto &[v, p] : g[u]) {
                    if (c[u] + p < nx[v]) {
                        nx[v] = c[u] + p;
                        q.push(v);
                    }
                }
            }

            c = nx;
            st++;
        }

        return c[d] == INT_MAX ? -1 : c[d];
    }
};