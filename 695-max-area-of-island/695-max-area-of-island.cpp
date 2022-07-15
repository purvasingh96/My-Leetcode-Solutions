class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    bool isValid(vector<vector<int>> grid, int x, int y){
        return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
   }
    
    int dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visited){
       
        if(!isValid(grid, r, c) || !grid[r][c] || visited[r][c]) return 0;
        visited[r][c] = true;
        int ans=0;
        
        for(int k=0;k<4;k++){
            
            int new_r = r+dx[k];
            int new_c = c+dy[k];
            
            ans += dfs(grid, new_r, new_c, visited);
            
        }
        
        return 1+ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int max_area = INT_MIN;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j] && !visited[i][j]){
                    //visited[i][j] = true;
                    int y=dfs(grid, i, j, visited);
                    
                    max_area = max(max_area, y);
                    
                }
                
            }
        }
        
        return max_area==INT_MIN?0:max_area;
    }
};