class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int m = grid.size(), n = grid[0].size();
        vector<int> temp(m*n);
        vector<int> temp_res(m*n);
        
        for(int i=0;i<grid.size();i++) {
            
            for(int j=0;j<grid[i].size();j++) {
                
                int cur_idx = (n*i) + j;
                int new_idx = (cur_idx+k)%(m*n);
                temp_res[new_idx] = grid[i][j];
            }
            
        }
        
        
        
        
       
        
        //for(auto x:temp_res) cout<<x<<" ";
        
        vector<vector<int>> res(m, vector<int>(n));
        int row=0, col=0;
        
        for(int i=0;i<temp_res.size();i++) {
            
            if(i%n==0 && i!=0) {
                row+=1;
                col=0;
                res[row][col] = temp_res[i];
                col+=1;
            }   else{
                res[row][col] = temp_res[i];
                col+=1;
            }
        }
        
        return res;
        
    }
};