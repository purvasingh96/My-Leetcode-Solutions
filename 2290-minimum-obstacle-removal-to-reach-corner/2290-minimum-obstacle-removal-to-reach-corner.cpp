class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool isValid(int x, int y, vector<vector<int>>& grid){
        return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
}
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        visited[0][0]=0;
        q.push({0,0, 0});
        
        while(!q.empty()){
            auto f = q.top();
            q.pop();
            int x = f[1], y = f[2], obstacles=f[0];
            if(x==m-1 && y==n-1) return obstacles;
            
            for(int i=0;i<4;i++){
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                
                if(isValid(new_x, new_y, grid)){
                   if(visited[new_x][new_y] > grid[new_x][new_y]+obstacles){
                       visited[new_x][new_y] = grid[new_x][new_y]+obstacles;
                       q.push({grid[new_x][new_y]+obstacles, new_x, new_y});
                   }
                }
                
                
                
                
            }
        }
        
        return -1;
        
    }
};