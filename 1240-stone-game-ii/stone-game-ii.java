class Solution {
    public int stoneGameII(int[] piles) {
        int n = piles.length;
        int[] suffix = new int[n + 1];
        for (int i = n - 1; i >= 0; i--) suffix[i] = suffix[i + 1] + piles[i];

        Integer[][] memo = new Integer[n][n + 1];
        return dp(0, 1, piles, suffix, memo, n);
    }

    private int dp(int i, int M, int[] piles, int[] suffix, Integer[][] memo, int n) {
        if (i >= n) return 0;
        if (i + 2 * M >= n) return suffix[i];
        if (memo[i][M] != null) return memo[i][M];

        int best = 0;
        for (int X = 1; X <= 2 * M; X++) {
            if (i + X > n) break;
            int opp = dp(i + X, Math.max(M, X), piles, suffix, memo, n);
            best = Math.max(best, suffix[i] - opp);
        }
        memo[i][M] = best;
        return best;
    }
}