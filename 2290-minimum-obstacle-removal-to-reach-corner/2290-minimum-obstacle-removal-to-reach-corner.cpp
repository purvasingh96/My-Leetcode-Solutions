#define pi pair<int, int>
#define pipi pair<int, pi>

class Solution {
private:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        priority_queue<pipi, vector<pipi>, greater<pipi>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        pq.push({0, {0,0}});
        
        visited[0][0] = true;
        
        while(!pq.empty()){
            
            auto f = pq.top();
            pq.pop();
            int dist = f.first;
            auto coords_info = f.second;
            int x = coords_info.first;
            int y = coords_info.second;
            
            
            if(x==m-1 && y==n-1) return dist;
            
            for(int i=0;i<4;i++){
                
                int new_x = x+dx[i];
                int new_y = y+dy[i];
                
                if(new_x>=0 && new_y>=0 && new_x<m && new_y<n){
                    if(!visited[new_x][new_y]){
                        visited[new_x][new_y] = true;
                        if(grid[new_x][new_y]==0){
                            pq.push({dist, {new_x, new_y}});
                        } else{
                            pq.push({dist+1, {new_x, new_y}});
                        }
                    }
                }
                
                
            }
            
            
            
        }
        return -1;
    }
};