class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool isValid(int x, int y, vector<vector<int>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
    
    void dfs(int x, int y, vector<vector<int>>& grid, queue<vector<int>>& q){
        if(grid[x][y]==1){
            grid[x][y]=2;
            bool borderCell=false;
            
            for(int i=0;i<4;i++){
                int new_x = x+dx[i];
                int new_y = y+dy[i];
                
                if(isValid(new_x, new_y, grid)){
                    if(grid[new_x][new_y]==0) borderCell=true;
                    else if(grid[new_x][new_y]==1){
                        dfs(new_x, new_y, grid, q);
                    }
                }
            }
            
            q.push({x, y, 0});
        }
    }
    
    int bfs(queue<vector<int>>& q, vector<vector<int>>& grid){
        while(!q.empty()){
            
            auto f = q.front();
            q.pop();
            
            int x = f[0], y = f[1], steps=f[2];
            if(grid[x][y]==1) return steps-1;
            
            for(int i=0;i<4;i++){
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                
                if(isValid(new_x, new_y, grid) && grid[new_x][new_y]!=2){
                    if(grid[new_x][new_y]==1) return steps;
                    grid[new_x][new_y]=2;
                    q.push({new_x, new_y, steps+1});
                }
                
            }
            
            
        }
        
        return 0;
    }
    
public:
    int shortestBridge(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        for(int i=0;i<grid.size();i++){
            bool found=false;
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    dfs(i, j, grid, q);
                    found=true;
                    break;
                }
            }
            if(found) break;
        }
        
        
        return bfs(q, grid);
    }
};