class Solution {
    public int numberOfSubmatrices(char[][] grid) {
        int rows = grid.length, cols = grid[0].length;
        int[][] countX = new int[rows+1][cols+1];
        int[][] countY = new int[rows+1][cols+1];
        int ans = 0;
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                int x = grid[i-1][j-1] == 'X' ? 1 : 0;
                int y = grid[i-1][j-1] == 'Y' ? 1 : 0;
                countX[i][j] = countX[i-1][j] + countX[i][j-1] - countX[i-1][j-1] + x;
                countY[i][j] = countY[i-1][j] + countY[i][j-1] - countY[i-1][j-1] + y;
                if (countX[i][j] == countY[i][j] && countX[i][j] > 0) ans++;
            }
        }
        return ans;
    }
}