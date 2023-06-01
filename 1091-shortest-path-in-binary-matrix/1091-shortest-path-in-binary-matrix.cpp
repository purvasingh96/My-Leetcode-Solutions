class Solution {
private:
    int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

    bool isValid(int x, int y, vector<vector<int>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        if(grid[0][0]!=0) return -1;
        grid[0][0]=1;
        
        q.push({0, 0, 1});
        int ans = INT_MAX, m = grid.size(), n = grid[0].size();
        
        while(!q.empty()){
            
            auto f = q.front();
            q.pop();
            
            int x = f[0], y = f[1], steps=f[2];
            if(x == m-1 && y==n-1){
                ans = min(ans, steps);
            }
            
            for(int i=0;i<8;i++){
                int new_x = x+dx[i];
                int new_y = y+dy[i];
                
                if(isValid(new_x, new_y, grid) && grid[new_x][new_y]==0){
                    grid[new_x][new_y]=1;
                    q.push({new_x, new_y, steps+1});
                }
            }
            
        }
        
        return ans==INT_MAX?-1:ans;
        
    }
};