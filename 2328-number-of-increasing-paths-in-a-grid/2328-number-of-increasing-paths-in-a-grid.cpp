class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    int mod = 1000000007;
    
    bool withinBounds(int new_x, int new_y, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        
        return new_x>=0 && new_x<m && new_y>=0 && new_y<n;
    }
    
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& memo){
        if(memo[r][c]!=-1) return memo[r][c];
        
        memo[r][c] = 0;
        for(int i=0;i<4;i++){
            int new_x = r+dx[i];
            int new_y = c+dy[i];
            
            // paths starting with node grid[r][c]
            if(withinBounds(new_x, new_y, grid) && grid[new_x][new_y]>grid[r][c]){
                memo[r][c] += (dfs(new_x, new_y, grid, memo));
            }
        }
        
        // path of length 1
        memo[r][c] = 1+ memo[r][c]%mod;
        
        return memo[r][c];
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> memo(m, vector<int>(n, -1));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(memo[i][j]==-1) dfs(i, j, grid, memo);
            }
        }
        
        int ans = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans += memo[i][j];
                ans = ans%mod;
            }
        }
        
        return ans;
    }
};