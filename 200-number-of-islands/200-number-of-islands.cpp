class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    bool isValid(int r, int c, vector<vector<char>>& grid){
        return r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c]=='1';
    }
    
    void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        
        visited[r][c] = true;
        
        for(int i=0;i<4;i++){
            int new_r = r+dx[i];
            int new_c = c+dy[i];
            
            if(isValid(new_r, new_c, grid) && !visited[new_r][new_c]){
                dfs(new_r, new_c, grid, visited);
            }
        }        
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> ones;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    ones.push_back({i, j});
                }
            }
        }
        
        int ans=0;
        
        for(int i=0;i<ones.size();i++){
            int r = ones[i][0], c = ones[i][1];
            
            if(!visited[r][c]){
                dfs(r, c, grid, visited);
                ans+=1;
            }
            
        }
        
        return ans;
    }
};