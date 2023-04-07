class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool isValid(int x, int y, vector<vector<int>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
    void backtrack(int x, int y, int& target, int tx, int ty, vector<vector<int>>& grid, vector<vector<bool>>& visited, int& ans){
        if(x==tx && y==ty && target==-1){
            ans+=1;
            return;
        }
        
        for(int i=0;i<4;i++){
            int newx = x+dx[i];
            int newy = y+dy[i];
            
            if(isValid(newx, newy, grid) && !visited[newx][newy] && grid[newx][newy]!=-1){
                visited[newx][newy]=true;
                target-=1;
                backtrack(newx, newy, target, tx, ty, grid, visited, ans);
                target+=1;
                visited[newx][newy]=false;
            }
        }
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int target=0;
        int sx, sy, tx, ty;
        int m =grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    sx=i;
                    sy=j;
                } else if(grid[i][j]==2){
                    tx=i;
                    ty=j;
                } else if(grid[i][j]==0){
                    target+=1;
                }
            }
        }
        visited[sx][sy]=true;
        int ans=0;
        backtrack(sx, sy, target, tx, ty, grid, visited, ans);
        return ans;
    }
};