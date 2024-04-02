class NumMatrix {
public:
    vector<vector<int>> _dp;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                dp[i][j] = matrix[i-1][j-1]
                    + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
        
        _dp = dp;
            
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        return _dp[r2+1][c2+1] - _dp[r1][c2+1] - _dp[r2+1][c1] + _dp[r1][c1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */