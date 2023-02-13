class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool isValid(int x, int y, vector<vector<int>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
    int max_len;
    int dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp, vector<vector<bool>>& visited){
        
        
       if(dp[x][y]!=-1) return dp[x][y];
        if(grid[x][y]==1) return 0;
        
        int min_len=200;
        for(int k=0;k<4;k++){
            int new_x = x+dx[k];
            int new_y= y+dy[k];
            
            if(isValid(new_x, new_y, grid) && !visited[new_x][new_y]){
                visited[new_x][new_y] = true;
                min_len = min(min_len, 1+dfs(new_x, new_y, grid, dp, visited));
                visited[new_x][new_y] = false;
            }
        }
        
        max_len = max(max_len, min_len);
        return dp[x][y] = min_len;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        max_len=INT_MIN;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }
        int d =-1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto f = q.front();q.pop();
                int x = f.first, y =f.second;

                for(int k=0;k<4;k++){
                    int new_x = x+dx[k];
                    int new_y = y+dy[k];

                    if(isValid(new_x, new_y, grid) && !visited[new_x][new_y]){
                            visited[new_x][new_y] = true;
                        q.push({new_x, new_y});
                    }
                }    
            }
            
            d+=1;
        }
        
        
        return d==0?-1:d;
    }
};