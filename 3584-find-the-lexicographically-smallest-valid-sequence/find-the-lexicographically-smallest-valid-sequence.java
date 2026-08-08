class Solution {
    public int[] validSequence(String word1, String word2) {
        int n = word1.length(), m = word2.length();
        int[] suf = new int[n + 1];
        for (int i = n - 1; i >= 0; i--) {
            int k = suf[i + 1];
            if (k < m && word1.charAt(i) == word2.charAt(m - k - 1)) {
                suf[i] = k + 1;
            } else {
                suf[i] = k;
            }
        }
        
        int[] result = new int[m];
        int idx = 0;
        int i = 0, j = 0;
        boolean used = false;
        while (j < m) {
            if (i >= n) return new int[0];
            if (word1.charAt(i) == word2.charAt(j)) {
                result[idx++] = i;
                i++; j++;
            } else if (!used && suf[i + 1] >= m - j - 1) {
                used = true;
                result[idx++] = i;
                i++; j++;
            } else {
                i++;
            }
        }
        return result;
    }
}