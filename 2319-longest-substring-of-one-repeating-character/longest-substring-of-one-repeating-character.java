class Solution {
    int[] length, pref, suf, best;
    char[] first, last, s;
    int n;

    public int[] longestRepeating(String str, String queryCharacters, int[] queryIndices) {
        n = str.length();
        s = str.toCharArray();
        int size = 4 * n;
        length = new int[size]; pref = new int[size]; suf = new int[size]; best = new int[size];
        first = new char[size]; last = new char[size];
        build(1, 0, n-1);

        int k = queryIndices.length;
        int[] res = new int[k];
        for (int i = 0; i < k; i++) {
            update(1, 0, n-1, queryIndices[i], queryCharacters.charAt(i));
            res[i] = best[1];
        }
        return res;
    }

    void pull(int node) {
        int L = 2*node, R = 2*node+1;
        length[node] = length[L] + length[R];
        first[node] = first[L];
        last[node] = last[R];
        pref[node] = pref[L];
        if (pref[L] == length[L] && last[L] == first[R]) pref[node] += pref[R];
        suf[node] = suf[R];
        if (suf[R] == length[R] && last[L] == first[R]) suf[node] += suf[L];
        best[node] = Math.max(best[L], best[R]);
        if (last[L] == first[R]) best[node] = Math.max(best[node], suf[L] + pref[R]);
    }

    void build(int node, int l, int r) {
        if (l == r) {
            length[node] = pref[node] = suf[node] = best[node] = 1;
            first[node] = last[node] = s[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2*node, l, mid);
        build(2*node+1, mid+1, r);
        pull(node);
    }

    void update(int node, int l, int r, int idx, char ch) {
        if (l == r) {
            first[node] = last[node] = ch;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2*node, l, mid, idx, ch);
        else update(2*node+1, mid+1, r, idx, ch);
        pull(node);
    }
}