class Solution {
private:
    bool isValid(int i, int j, vector<vector<char>>& grid){
        return i>=0 && j>=0 && i<grid.size() && j<grid[0].size();
    }
    
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    void dfs(vector<vector<char>>& grid, int i, int j){
        
        for(int k=0;k<4;k++){
            int new_x = i + dx[k];
            int new_y = j + dy[k];
            
            if(isValid(new_x, new_y, grid) && grid[new_x][new_y] == '1'){
                grid[new_x][new_y] = '0';
                dfs(grid, new_x, new_y);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    dfs(grid, i, j);
                    count+=1;
                }
            }
        }
        
        return count;
    }
};