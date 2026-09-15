class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> cur(1, (double)poured);

        for (int r = 0; r < query_row; r++) {
            vector<double> nxt(r + 2, 0.0);
            for (int c = 0; c <= r; c++) {
                double over = (cur[c] - 1.0) / 2.0;
                if (over > 0) {
                    nxt[c] += over;
                    nxt[c + 1] += over;
                }
            }
            cur = nxt;
        }

        return min(1.0, cur[query_glass]);
    }
};