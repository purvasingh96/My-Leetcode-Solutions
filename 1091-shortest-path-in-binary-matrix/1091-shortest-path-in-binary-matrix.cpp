class Solution {
private:
    int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

    bool isValid(int x, int y, vector<vector<int>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //bfs
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0]=1;
        
        int d=1;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto f = q.front();
                q.pop();
                
                int x = f.first, y = f.second;
                
                if(x==n-1 && y==n-1){
                    return d;
                }
                
                for(int i=0;i<8;i++){
                    int new_x = x+dx[i];
                    int new_y = y+dy[i];
                    
                    if(isValid(new_x, new_y, grid) &&
                       grid[new_x][new_y]==0){
                        grid[new_x][new_y]=1;
                        q.push({new_x, new_y});
                    }
                }
            }
            d+=1;
        }
        
        return -1;
        
    }
};