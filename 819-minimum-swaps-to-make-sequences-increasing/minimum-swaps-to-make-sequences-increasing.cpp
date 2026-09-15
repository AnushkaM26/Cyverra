class Solution {
public:
    int minSwap(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int keep = 0, swp = 1;

        for (int i = 1; i < n; i++) {
            int nk = INT_MAX, ns = INT_MAX;

            if (a[i] > a[i - 1] && b[i] > b[i - 1])
                nk = min(nk, keep);
            if (a[i] > b[i - 1] && b[i] > a[i - 1])
                nk = min(nk, swp);

            if (b[i] > a[i - 1] && a[i] > b[i - 1])
                ns = min(ns, keep + 1);
            if (b[i] > b[i - 1] && a[i] > a[i - 1])
                ns = min(ns, swp + 1);

            keep = nk;
            swp = ns;
        }

        return min(keep, swp);
    }
};