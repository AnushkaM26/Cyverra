class Solution {
    int[][] grid;
    int n;
    Integer[][][] dp;

    public int cherryPickup(int[][] grid) {
        this.grid = grid;
        n = grid.length;
        dp = new Integer[n][n][n];

        return Math.max(0, solve(0, 0, 0));
    }

    private int solve(int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2;

        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n)
            return -1000000;

        if (grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return -1000000;

        if (r1 == n - 1 && c1 == n - 1)
            return grid[r1][c1];

        if (dp[r1][c1][r2] != null)
            return dp[r1][c1][r2];

        int cherries = grid[r1][c1];

        if (r1 != r2 || c1 != c2)
            cherries += grid[r2][c2];

        int best = Math.max(
                Math.max(solve(r1 + 1, c1, r2 + 1),
                         solve(r1 + 1, c1, r2)),
                Math.max(solve(r1, c1 + 1, r2 + 1),
                         solve(r1, c1 + 1, r2))
        );

        cherries += best;

        dp[r1][c1][r2] = cherries;
        return cherries;
    }
}