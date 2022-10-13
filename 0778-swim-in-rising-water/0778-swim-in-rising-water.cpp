class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    bool isValid(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& seen, int time){
        return (
            x>=0 &&y>=0 && x<grid.size() && y<grid[0].size()
            && !seen[x][y] && grid[x][y] <= time
        
        );
    }
    
    bool dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& seen, int time){
        int n = grid.size();
        
        if(!isValid(x, y, grid, seen, time)) return false;
        if(x==n-1 && y==n-1) return true;
        
        seen[x][y] = true;
        
        for(int i=0;i<4;i++){
            int new_x = x+dx[i];
            int new_y = y+dy[i];
            
            if(dfs(new_x, new_y, grid, seen, time)) return true;
        }
        
        return false;
    }
public:
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int l = grid[0][0], r = n*n;
        
        while(l<r){
            int mid = l + (r-l)/2;
            vector<vector<bool>> seen(n, vector<bool>(n, false));
            if(dfs(0, 0, grid, seen, mid)){
                r=mid;
            } else{
                l=mid+1;
            }
        }
        
        return l;
    }
};