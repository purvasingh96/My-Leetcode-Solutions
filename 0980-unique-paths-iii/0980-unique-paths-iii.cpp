class Solution {
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool isValid(int x, int y, vector<vector<int>>& grid){
        return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
}
    
void backtrack(int x, int y, int& total, vector<vector<int>>& grid, vector<vector<bool>>& visited, int& ans, int nonObstacleSquares, int ex, int ey){
    
    if(x==ex && y==ey){
        if(total == nonObstacleSquares){
            ans+=1;
        }
        return;
    }
    
    visited[x][y]=true;
    for(int i=0;i<4;i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        
        if(isValid(new_x, new_y, grid) && !visited[new_x][new_y] && grid[new_x][new_y]!=-1){
            total+=1;
            backtrack(new_x, new_y, total, grid, visited, ans, nonObstacleSquares, ex, ey);
            total-=1;
        }
    }
    visited[x][y]=false;
}    
    
    
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int nonObstacleSquares = 0;
        int sx, sy, ex, ey;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    nonObstacleSquares+=1;
                    sx=i;
                    sy=j;
                } else if(grid[i][j]==2){
                    nonObstacleSquares+=1;
                    ex=i;
                    ey=j;
                } else if(grid[i][j] == 0){
                    nonObstacleSquares+=1;
                }
            }
        }
        
        int ans=0, total=1;
        
        backtrack(sx, sy, total, grid, visited, ans, nonObstacleSquares, ex, ey);
        
        
        return ans;
        
    }
};