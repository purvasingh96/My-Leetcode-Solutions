class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool isValid(int x, int y, vector<vector<int>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
    
    int bfs(int x, int y, vector<vector<int>>& grid){
        int m =grid.size(), n = grid[0].size();
        int ans=0;
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({x, y});
        seen[x][y] = true;
        
        while(!q.empty()){
            
            int sz =q.size();
            while(sz--){
                
                auto f = q.front();
                q.pop();
                
                int x = f.first, y = f.second;
                
                for(int i=0;i<4;i++){
                    
                    int new_x = x + dx[i];
                    int new_y = y + dy[i];
                    
                    if(!isValid(new_x, new_y, grid) || grid[new_x][new_y] == 0){
                        
                        ans+=1;
                        
                    } else if(isValid(new_x, new_y, grid) && grid[new_x][new_y]==1 && !seen[new_x][new_y]){
                        seen[new_x][new_y] = true;
                        q.push({new_x, new_y});
                    }
                    
                    
                }
                
            }
            
        }
        
        return ans;
    }
    
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int total_p=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) {
                    return bfs(i, j, grid);
                }
            }
        }
        
        return 0;
    }
};