class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool isValid(int x, int y, vector<vector<int>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
    int dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& seen){
        seen[x][y] = true;
        
        int ans=1;
        for(int i=0;i<4;i++){
            int new_x = x + dx[i];
            int new_y = y+ dy[i];
            if(isValid(new_x, new_y, grid) && grid[new_x][new_y]!=0 && !seen[new_x][new_y]){
                ans += dfs(new_x, new_y, grid, seen);
            }
        }
        
        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=INT_MIN;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> seen(m, vector<int>(n, false));
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1 && !seen[i][j]){
                    int res =  dfs(i, j, grid, seen);
                    //cout<<i<<" "<<j<<" "<<res<<"\n";
                    ans = max(ans,res);
                }
            }
        }
        
        return ans==INT_MIN? 0:ans;
    }
};