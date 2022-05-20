class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        if(obstacleGrid[0][0] == 1) return 0;
        else dp[0][0]=1;
        
        for(int i=1;i<m;i++){
            if(obstacleGrid[i][0] ==0){
                dp[i][0]= 1;
            } else break;
        }
        
        
        for(int j=1;j<n;j++){
            if(obstacleGrid[0][j]==0){
                dp[0][j] = 1;
            } else break;
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                
                if(obstacleGrid[i][j]==0){
                    
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    
                }
                
            }
        }
        
        return dp[m-1][n-1];
        
        
    }
};