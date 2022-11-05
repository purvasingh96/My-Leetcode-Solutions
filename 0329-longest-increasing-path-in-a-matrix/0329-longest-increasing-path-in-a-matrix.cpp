class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool isValid(int x, int y, vector<vector<int>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
    
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(dp[i][j]!=0) return dp[i][j];
        
        int ans=0;
        for(int k=0;k<4;k++){
            int new_x = i + dx[k];
            int new_y = j + dy[k];
            
            if(isValid(new_x, new_y, matrix) && 
               matrix[new_x][new_y] > matrix[i][j]){
                ans = max(ans, dfs(new_x, new_y, matrix, dp));
            }   
        }
        
        return dp[i][j] = ans+1;
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m =matrix.size(), n=matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        int ans=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans = max(ans, dfs(i, j, matrix, dp));
            }
        }
        
        return ans;
    }
};