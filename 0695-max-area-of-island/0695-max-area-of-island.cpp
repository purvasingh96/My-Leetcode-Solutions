class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool isValid(int x, int y, vector<vector<int>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
    void dfs(vector<vector<int>>& grid, int i, int j, int& total){
        
        for(int k=0;k<4;k++){
            int new_x = i + dx[k];
            int new_y = j + dy[k];
            
            if(isValid(new_x, new_y, grid) && grid[new_x][new_y]==1){
                total+=1;
                grid[new_x][new_y]=0;
                dfs(grid, new_x, new_y, total);
            }
                
        }
    }
        
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    grid[i][j]=0;
                    int total=1;
                    dfs(grid, i, j, total);
                    ans = max(ans, total);
                }        
            }
        }
        
        return ans;
    }
};