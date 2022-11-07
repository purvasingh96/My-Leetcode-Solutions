class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool isValid(int x, int y, vector<vector<int>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
    
    bool bfs(int mid, vector<vector<int>>& grid){
        queue<pair<int, int>> q;
        int n = grid.size();
        vector<vector<bool>> seen(n, vector<bool>(n, false));
        
        seen[0][0] = true;
        
        q.push({0, 0});
        
        
        while(!q.empty()){
            
            int sz = q.size();
            while(sz--){
                
                auto f = q.front();
                q.pop();
                
                int x = f.first, y = f.second;
                
                if(x == n-1 && y==n-1) return true;
                
                for(int k=0;k<4;k++){
                    int new_x = x +dx[k], new_y=y+dy[k];
                    
                    if(isValid(new_x, new_y, grid) && !seen[new_x][new_y] && grid[new_x][new_y] <= mid){
                        q.push({new_x, new_y});
                        seen[new_x][new_y] = true;
                    }
                }
                
                
            }
            
        }
        
        return false;
    }
    
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int l=grid[0][0], r=pow(n, 2);
        
        int ans=0;
        while(l<=r){
            int mid = l + (r-l)/2;
            vector<vector<bool>> seen(n, vector<bool>(n, false));
            if(bfs(mid, grid)){
                ans = mid;
                r = mid-1;
            } else l = mid+1;
        }
        
        return ans;
    }
};