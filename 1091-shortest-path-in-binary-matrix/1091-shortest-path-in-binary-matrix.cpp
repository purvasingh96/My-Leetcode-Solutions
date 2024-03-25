class Solution {
private:
    int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

    bool isValid(int x, int y, vector<vector<int>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n=grid.size();
        
        if(grid[0][0] == 1 || grid[n-1][n-1]==1){
            return -1;
        }
        
        q.push({0, 0});
        int level=1;
        
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                auto f = q.front();
                q.pop();
                int x = f.first, y = f.second;
                
                if(x == n-1 && y==n-1){
                    return level;
                }
                
                for(int k=0;k<8;k++){
                    int new_x = x+dx[k];
                    int new_y = y+dy[k];
                    
                    if(isValid(new_x,new_y, grid) && grid[new_x][new_y]==0){
                        grid[new_x][new_y] = 1;
                        q.push({new_x, new_y});
                    }
                    
                }
                
            }
            
            level+=1;
        }
        
        return -1;
        
    }
};