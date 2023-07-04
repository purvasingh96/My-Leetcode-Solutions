class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    vector<vector<int>> ans;

    bool isValid(int x, int y, vector<vector<int>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
    void dfs(int x, int y, vector<vector<int>>& heights, vector<vector<string>>& dp, string val, vector<vector<bool>>& visited){
        dp[x][y] += val;
        if(dp[x][y] == "PA") ans.push_back({x, y});
        
        for(int i=0;i<4;i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            
            if(isValid(new_x, new_y, heights) && !visited[new_x][new_y] &&
              heights[new_x][new_y] >= heights[x][y]){
                visited[new_x][new_y] = true;
                dfs(new_x, new_y, heights, dp, val, visited);
            }
        }
        
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<string>> dp(m, vector<string>(n, ""));
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        
        
        // pacific
        for(int i=0;i<m;i++){
            if(!visited[i][0]){
                visited[i][0] = true;
                dfs(i, 0, heights, dp, "P", visited);
            }
        }
        
        // pacific
        for(int j=1;j<n;j++){
            if(!visited[0][j]){
                visited[0][j] = true;
                dfs(0, j, heights, dp, "P", visited);
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                visited[i][j] = false;
            }
        }
        
        // atlantic
        for(int i=0;i<m;i++){
            if(!visited[i][n-1]){
                visited[i][n-1] = true;
                dfs(i, n-1, heights, dp, "A", visited);
            }
        }
        
        
        for(int j=0;j<n-1;j++){
            if(!visited[m-1][j]){
                visited[m-1][j] = true;
                dfs(m-1, j, heights, dp, "A", visited);
            }
        }
        //cout<<"here";
        
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(dp[i][j] == "PA"){
        //             ans.push_back({i, j});
        //         }
        //     }
        // }
        
        return ans;
        
        
    }
};