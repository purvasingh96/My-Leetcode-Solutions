class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool isValid(int x, int y, vector<vector<int>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, INT_MAX));
        
        queue<vector<int>> q;
        //x y steps obstacles
        q.push({0,0,0,0});
        visited[0][0] = 0;
        
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            int x = f[0], y = f[1], steps=f[2], obs=f[3];
            if(x==m-1 && y==n-1) return steps;
            
            
            for(int i=0;i<4;i++){
                int new_x = x + dx[i];
                int new_y = y +dy[i];
                
                if(isValid(new_x, new_y, grid)){
                    
                    if(grid[new_x][new_y]==1){
                        if(obs == k) continue;
                        else {
                            if(visited[new_x][new_y]==INT_MAX ||(visited[new_x][new_y]!=INT_MAX && visited[new_x][new_y] > obs+1)){
                                visited[new_x][new_y] = obs+1;
                                q.push({new_x, new_y, steps+1, obs+1});
                            }
                        }
                    } else {
                        if(visited[new_x][new_y]==INT_MAX || (visited[new_x][new_y]!=INT_MAX && visited[new_x][new_y] > obs)){
                                visited[new_x][new_y] = obs;
                                q.push({new_x, new_y, steps+1, obs});
                        }
                    }
                    
                }
            }
        }
        return -1;
    }
};