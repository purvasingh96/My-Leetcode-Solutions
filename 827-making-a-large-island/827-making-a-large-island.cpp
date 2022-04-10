class Solution {
public:
    int get(int i, int j, vector<vector<int>>& grid) {
        return (i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) ? 0: grid[i][j];
    }
    
    int paint(int i, int j, int color, vector<vector<int>>& grid) {
        
        if(get(i, j, grid)!=1) return 0;
        grid[i][j] = color;
        
        // return size of island;
        return 1+ paint(i+1, j, color, grid)+paint(i-1, j, color, grid)+paint(i, j+1, color, grid)+paint(i, j-1, color, grid);
        
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        
        vector<int> sizes = {0, 0};
        int res = INT_MIN;
        
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                
                if(grid[i][j] == 1) sizes.push_back(paint(i, j, sizes.size(), grid));
                
            }
        }
        
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                
                if(grid[i][j] == 0) {
                    
                    unordered_set<int> s = {get(i+1, j, grid), get(i, j+1, grid), get(i-1, j, grid), get(i, j-1, grid)};
                    res  = max(res, 1 + accumulate(s.begin(), s.end(), 0, [&](int a, int b) {
                        return a + sizes[b];
                    }));
                    
                }
                
            }
        }
        
        return res==INT_MIN?grid.size()*grid[0].size() : res;
        
    }
};