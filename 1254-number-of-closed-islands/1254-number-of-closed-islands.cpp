class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool isValid(int x, int y, vector<vector<int>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
    void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        visited[x][y]=true;
        grid[x][y] = 1;
        
        for(int k=0;k<4;k++){
            int new_x =x+dx[k];
            int new_y = y+dy[k];
            if(isValid(new_x, new_y, grid) && !visited[new_x][new_y] && grid[new_x][new_y]==0){
                dfs(new_x, new_y, grid, visited);
            }
        }
    }
    
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i=0;i<m;i++){
            if(grid[i][0]==0) dfs(i, 0, grid, visited);
            if(grid[i][n-1]==0) dfs(i, n-1, grid, visited);
        }
        
        for(int j=0;j<n;j++){
            if(grid[0][j]==0) dfs(0, j, grid, visited);
            if(grid[m-1][j]==0) dfs(m-1, j, grid, visited);
        }
        
      
        int ans=0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]==0) {
                    dfs(i, j, grid, visited);
                    ans+=1;
                    
                }
            }
        }
        
        return ans;
        
    }
};