class Solution {
public:
    using ll = long long;

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<ll> pos;
        ll S = side;
        ll perimeter = 4LL * S;

        for (auto &p : points) {
            ll x = p[0];
            ll y = p[1];

            if (x == 0)
                pos.push_back(y);
            else if (y == S)
                pos.push_back(S + x);
            else if (x == S)
                pos.push_back(3 * S - y);
            else
                pos.push_back(4 * S - x);
        }

        sort(pos.begin(), pos.end());

        int n = pos.size();

        vector<ll> a(2 * n);
        for (int i = 0; i < n; i++) {
            a[i] = pos[i];
            a[i + n] = pos[i] + perimeter;
        }

        auto can = [&](ll dist) -> bool {
            for (int start = 0; start < n; start++) {
                ll lastAllowed = a[start] + perimeter - dist;

                int curr = start;
                bool possible = true;

                for (int cnt = 1; cnt < k; cnt++) {
                    ll target = a[curr] + dist;

                    auto it = lower_bound(
                        a.begin() + curr + 1,
                        a.begin() + start + n,
                        target
                    );

                    if (it == a.begin() + start + n || *it > lastAllowed) {
                        possible = false;
                        break;
                    }

                    curr = it - a.begin();
                }

                if (possible)
                    return true;
            }

            return false;
        };

        ll low = 0, high = S;

        while (low < high) {
            ll mid = low + (high - low + 1) / 2;

            if (can(mid))
                low = mid;
            else
                high = mid - 1;
        }

        return (int)low;
    }
};