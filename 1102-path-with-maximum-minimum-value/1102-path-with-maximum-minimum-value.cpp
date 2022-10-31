/*
1. find path for which min score is N or for which all the values are greater than equal to N.
2. BFS
*/

class Solution {
private:
    int dx[4] = {0,1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    bool isValid(int x, int y, vector<vector<int>>& grid){
        return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
    
    bool check(vector<vector<int>>& grid, int mid){
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        q.push({0, 0});
        if(grid[0][0] < mid) return false;
        seen[0][0] = true;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto f = q.front();
                q.pop();
                
                int x = f.first, y = f.second;
                
                if(x==m-1 && y==n-1) return true;
                
                
                
                for(int i=0;i<4;i++){
                    int new_x = x + dx[i];
                    int new_y = y + dy[i];
                    
                    if(isValid(new_x, new_y, grid) && !seen[new_x][new_y] && grid[new_x][new_y] >= mid){
                        q.push({new_x, new_y});
                        seen[new_x][new_y] = true;
                    }
                    
                }
                
            }
        }
        
        return false;
        
    }
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int left = 0, right = min(grid[0][0], grid[m-1][n-1]);
        int ans=0;
        
        while(left<=right){
            int mid = left + (right-left)/2;
            if(check(grid, mid)){
                ans=mid;
                left=mid+1;
            } else right=mid-1;
        }
        
        return ans;
    }
};