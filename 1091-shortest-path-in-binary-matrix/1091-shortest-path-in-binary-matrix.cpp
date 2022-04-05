class Solution {
private:
    int offset_x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int offset_y[8] = {1, 1, 0, -1, -1, -1, 0, 1};
public:
    bool checkBoundry(int n, int x, int y) {
        return (x>=0 && x<n && y>=0 && y<n);
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid[0][0] != 0) return -1;
        //cout<<"here";
        
        int len=0, n = grid.size();
        queue<vector<int>> q;
        
        q.push({0, 0, 1});
        
        while(!q.empty()) {
            
            int s = q.size();
            
            for(int i=0;i<s;i++) {
                
                auto f = q.front();
                q.pop();
                
                int x = f[0], y = f[1], level=f[2];
                
                if(x == n-1 && y == n-1 && grid[x][y] == 0) return level;
                
                for(int j=0;j<8;j++) {
                    
                    int new_x = x + offset_x[j], new_y = y+offset_y[j];
                    
                    if(checkBoundry(n, new_x, new_y) && grid[new_x][new_y] == 0) {
                        
                        //cout<<"nx: "<<new_x<<" "<<new_y<<"\n";
                        grid[new_x][new_y] = 1;
                        
                        if(new_x == n-1 && new_y == n-1) return level+1;
                        
                        q.push({new_x, new_y, level+1});
                        
                    }
                    
                }
                
                
            }
            
        }
        
        return -1;
    }
};