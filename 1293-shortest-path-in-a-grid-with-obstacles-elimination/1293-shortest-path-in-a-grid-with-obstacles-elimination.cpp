#define v vector<int>

class Solution {
private:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        // obst, 
        queue<v> pq;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1));
        // x, y, dist, obst
        pq.push({0, 0, 0, k});
        
        while(!pq.empty()){
            auto f = pq.front();
            pq.pop();
            
            int x = f[0];
            int y = f[1];
            int dist=f[2];
            int obst_remaining=f[3];
            
           
            
            if(x==m-1 && y==n-1){
                return dist;
            }
            
            if(grid[x][y] == 1){
                if(obst_remaining>0){
                    obst_remaining-=1;
                } else{
                    continue;
                }
                    
            }
            
            if(visited[x][y]!=-1 && visited[x][y]>=obst_remaining){
                continue;
            }
            
            visited[x][y]=obst_remaining;
            
            for(int i=0;i<4;i++){
                int new_x = x+dx[i];
                int new_y = y+dy[i];
                
                if(new_x>=0 && new_y>=0 && new_x<m && new_y<n){
                    pq.push({new_x, new_y, dist+1, obst_remaining});
                }
                
            }
            
        }
        
        return -1;
        
    }
};