class Solution {
public:
    
    int dist(char a, char b) {
        int x1 = (a - 'A') / 6;
        int y1 = (a - 'A') % 6;
        
        int x2 = (b - 'A') / 6;
        int y2 = (b - 'A') % 6;
        
        return abs(x1 - x2) + abs(y1 - y2);
    }
    
    int minimumDistance(string word) {
        int n = word.size();
        
        
        vector<int> dp(26, INT_MAX);
        
        
        for (int j = 0; j < 26; j++) {
            dp[j] = 0;
        }
        
        for (int i = 0; i < n - 1; i++) {
            vector<int> next(26, INT_MAX);
            
            int curr = word[i] - 'A';
            int nxt = word[i + 1] - 'A';
            
            for (int other = 0; other < 26; other++) {
                if (dp[other] == INT_MAX) continue;
                
                next[other] = min(
                    next[other],
                    dp[other] + dist(word[i], word[i + 1])
                );
                
                next[curr] = min(
                    next[curr],
                    dp[other] + dist('A' + other, word[i + 1])
                );
            }
            
            dp = next;
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};