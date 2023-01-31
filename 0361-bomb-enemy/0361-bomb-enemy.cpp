class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> count(m, vector<int>(n, 0));
        int res=0;
        
        for(int i=0;i<m;i++){
            int t=0;
            for(int j=0;j<n;j++){
                if(grid[i][j] == 'E') t++;
                else if(grid[i][j] == 'W') t=0;
                else if(grid[i][j] == '0'){
                    count[i][j] += t;
                    res = max(res, count[i][j]);
                }
            }
            t=0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j] == 'E') t++;
                else if(grid[i][j] == 'W') t=0;
                else if(grid[i][j] == '0'){
                    count[i][j] += t;
                    res = max(res, count[i][j]);
                }
            }
            
        }
        
        for(int j=0;j<n;j++){
            int t=0;
            for(int i=0;i<m;i++){
               if(grid[i][j] == 'E') t++;
                else if(grid[i][j] == 'W') t=0;
                else if(grid[i][j] == '0'){
                    count[i][j] += t;
                    res = max(res, count[i][j]);
                } 
            }
            
            t=0;
            for(int i=m-1;i>=0;i--){
                if(grid[i][j] == 'E') t++;
                else if(grid[i][j] == 'W') t=0;
                else if(grid[i][j] == '0'){
                    count[i][j] += t;
                    res = max(res, count[i][j]);
                }
            }
        }
        
        return res;
        
    }
};