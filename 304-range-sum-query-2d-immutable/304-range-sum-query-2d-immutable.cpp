class NumMatrix {
private:
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        dp.resize(m, vector<int>(n, 0));
        
        for(int i=0;i<m;i++){
            dp[i][0]=matrix[i][0];
        }
        
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i][j-1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int sum=0;
        
        for(int i=row1;i<=row2;i++){
            sum += dp[i][col2];
            if(col1-1>=0) sum -= (dp[i][col1-1]);
        }
        
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */