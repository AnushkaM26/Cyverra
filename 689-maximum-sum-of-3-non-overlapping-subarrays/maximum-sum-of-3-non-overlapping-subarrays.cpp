class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& a, int k) {
        int n = a.size();
        vector<int> s(n + 1), l(n), r(n);
        
        for (int i = 0; i < n; i++)
            s[i + 1] = s[i] + a[i];

        int p = 0;
        for (int i = k; i <= n - k; i++) {
            int x = s[i] - s[i - k];
            int y = s[p + k] - s[p];
            if (x > y) p = i - k;
            l[i] = p;
        }

        p = n - k;
        for (int i = n - k; i >= k; i--) {
            int x = s[i + k] - s[i];
            int y = s[p + k] - s[p];
            if (x >= y) p = i;
            r[i] = p;
        }

        vector<int> ans;
        long long mx = 0;

        for (int i = k; i <= n - 2 * k; i++) {
            int x = l[i];
            int z = r[i + k];
            long long sum = (s[x + k] - s[x]) +
                            (s[i + k] - s[i]) +
                            (s[z + k] - s[z]);

            if (ans.empty() || sum > mx) {
                mx = sum;
                ans = {x, i, z};
            }
        }

        return ans;
    }
};