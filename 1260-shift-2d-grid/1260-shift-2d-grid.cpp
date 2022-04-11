class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        
        int m = grid.size(), n = grid[0].size();
        k = k%(m*n);
        vector<int> temp_res(m*n);
        vector<vector<int>> res(m, vector<int>(n));
        int row=0, col=0;
        
        for(int i=0;i<grid.size();i++) {
            
            for(int j=0;j<grid[i].size();j++) {
                
                int new_col = (j+k)%n;
                
                int new_row = (i+(j+k)/n)%m;
                
                res[new_row][new_col] = grid[i][j];
                
            }
            
        }
        

        
        return res;
        
    }
};