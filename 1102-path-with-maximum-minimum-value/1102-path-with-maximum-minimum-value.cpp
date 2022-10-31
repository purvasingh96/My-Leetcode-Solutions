# define pp pair<int, pair<int, int>> 

class Solution {
private:
    int dx[4] = {0,1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    bool isValid(int x, int y, vector<vector<int>>& grid){
        return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), minVal = INT_MAX;
        priority_queue<pp> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        
        
        while(!pq.empty()){
            
            auto f = pq.top();
            pq.pop();
            
            int val = f.first, x = f.second.first, y = f.second.second;
            
            minVal = min(minVal, val);
            
            if(x == m-1 && y == n-1) return minVal;
            
            
            for(int i=0;i<4;i++){
                
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                
                
                if(isValid(new_x, new_y, grid) && !visited[new_x][new_y]){
                    pq.push({grid[new_x][new_y], {new_x, new_y}});
                    visited[new_x][new_y] = true;
                }
                
            }
            
            
            
        }
        
        return minVal;
        
    }
};