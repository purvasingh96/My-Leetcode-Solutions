class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int max_len = 0;
        
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++){
                
                if(matrix[i-1][j-1] == '1') {
                    
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                    max_len = max(max_len, dp[i][j]);
                    
                }
                
            }
        }
        
        return max_len*max_len;
    }
};