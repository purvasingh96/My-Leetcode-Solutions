# define pp pair<int, pair<int, int>>

class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool isValid(int x, int y, vector<vector<int>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        priority_queue<pp> q;        
        q.push({grid[0][0], {0, 0}});
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        seen[0][0] = true;
        
        
        int ans = INT_MAX;
        
        while(!q.empty()){
            
            int sz = q.size();
            
            
                
                auto f = q.top();
                q.pop();
                
                int x = f.second.first, y = f.second.second;
                
                ans = min(ans, f.first);
                
                if(x == m-1 && y == n-1) return ans;
                
                for(int k=0;k<4;k++){
                    int new_x = x + dx[k], new_y = y + dy[k]; 
                    if(isValid(new_x, new_y, grid) && !seen[new_x][new_y]){
                        q.push({grid[new_x][new_y], {new_x, new_y}});
                        seen[new_x][new_y] = true;
                    }
                    
                }
                
             
            
        }
        
        return ans;
    }
};