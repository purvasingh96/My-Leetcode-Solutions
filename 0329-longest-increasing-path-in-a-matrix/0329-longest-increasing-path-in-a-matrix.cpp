class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool isValid(int x, int y, vector<vector<int>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
    int dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(dp[x][y]!=-1) return dp[x][y];
        
        int ans=1;
        for(int k=0;k<4;k++){
            int new_x = x + dx[k];
            int new_y = y + dy[k];
            
            if(isValid(new_x, new_y, matrix) && 
               matrix[new_x][new_y]<matrix[x][y]){
               ans = max(ans, 1 + dfs(new_x, new_y, matrix, dp) );
            }
        }
        
        return dp[x][y] = ans;
        
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n=matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]==-1){
                    ans = max(ans, dfs(i, j, matrix, dp));
                }
            }
        }
        
        return ans;
    }
};