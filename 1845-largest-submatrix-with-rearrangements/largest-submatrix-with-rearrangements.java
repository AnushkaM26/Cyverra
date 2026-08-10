class Solution {
    public int largestSubmatrix(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int[][] heights = new int[m][n];
        
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (matrix[i][j] == 1) {
                    heights[i][j] = (i > 0 ? heights[i-1][j] : 0) + 1;
                } else {
                    heights[i][j] = 0;
                }
            }
        }
        
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            int[] row = heights[i].clone();
            Arrays.sort(row);
            // reverse to descending
            for (int l = 0, r = n - 1; l < r; l++, r--) {
                int tmp = row[l]; row[l] = row[r]; row[r] = tmp;
            }
            for (int j = 0; j < n; j++) {
                int area = row[j] * (j + 1);
                maxArea = Math.max(maxArea, area);
            }
        }
        
        return maxArea;
    }
}