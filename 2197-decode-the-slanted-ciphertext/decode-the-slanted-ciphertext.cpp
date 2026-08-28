class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        
        int n = encodedText.size();

        if (rows == 1) {
            return encodedText;
        }

        int cols = n / rows;

        vector<string> matrix(rows, string(cols, ' '));

        int k = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = encodedText[k++];
            }
        }

        string ans;

        for (int startCol = 0; startCol < cols; startCol++) {

            int r = 0;
            int c = startCol;

            while (r < rows && c < cols) {
                ans += matrix[r][c];

                r++;
                c++;
            }
        }

        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};