class Solution {
    public int[] getBiggestThree(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        TreeSet<Integer> set = new TreeSet<>(Collections.reverseOrder());

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                set.add(grid[i][j]);

                int maxRadius = Math.min(
                        Math.min(i, m - 1 - i),
                        Math.min(j, n - 1 - j)
                );

                for (int r = 1; r <= maxRadius; r++) {

                    if (i - r < 0 || i + r >= m || j - r < 0 || j + r >= n)
                        break;

                    int sum = 0;
                    for (int k = 0; k < r; k++)
                        sum += grid[i - r + k][j + k];

                    for (int k = 0; k < r; k++)
                        sum += grid[i + k][j + r - k];

                    for (int k = 0; k < r; k++)
                        sum += grid[i + r - k][j - k];

                    for (int k = 0; k < r; k++)
                        sum += grid[i - k][j - r + k];

                    set.add(sum);
                }
            }
        }

        int size = Math.min(3, set.size());
        int[] ans = new int[size];

        int idx = 0;
        for (int val : set) {
            if (idx == size) break;
            ans[idx++] = val;
        }

        return ans;
    }
}