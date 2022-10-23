# define pp pair<int, pair<int,int>>
class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    bool isValid(int x, int y, vector<vector<int>> grid){
        return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
   }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int ans=0;
        int n = grid.size();
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        
        while(!pq.empty()){
            
            auto f = pq.top();
            pq.pop();
            
            ans = max(ans, f.first);
            int x = f.second.first, y = f.second.second;
            
            
            if(x==n-1 && y==n-1) return ans;
            
            for(int i=0;i<4;i++){
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                
                if(isValid(new_x, new_y, grid) && !visited[new_x][new_y]){
                    pq.push({grid[new_x][new_y], {new_x, new_y}});
                    visited[new_x][new_y] = true;
                }
            }
            
            
        }
          return ans;
    }
};