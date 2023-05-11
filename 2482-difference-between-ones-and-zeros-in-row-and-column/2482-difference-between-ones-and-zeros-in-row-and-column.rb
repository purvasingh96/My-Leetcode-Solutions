class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int> row_ones;
        vector<int> col_ones;
        int m = grid.size(), n = grid[0].size();
        
        for(auto x:grid){
            row_ones.push_back(accumulate(x.begin(), x.end(), 0));
        }
        
        for(int j=0;j<grid[0].size();j++){
            int sum=0;
            for(int i=0;i<grid.size();i++){
                sum += grid[i][j];
            }
            col_ones.push_back(sum);
        }
        
        vector<vector<int>> res(m, vector<int>(n, 0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int onerow = row_ones[i];
                int onecol = col_ones[j];
                res[i][j] = 2*(onerow + onecol) - (m+n);
            }
        }
        
        return res;
        
        
    }
};