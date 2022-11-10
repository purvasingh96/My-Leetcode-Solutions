class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool isValid(int x, int y, vector<vector<int>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
    void backtrack(int i, int j, int emptyCells, int& ans, vector<vector<int>>& grid){
        
        if(grid[i][j] == 2 && emptyCells == 1){
            ans+=1;
            return;
        }
        
        int temp = grid[i][j];
        grid[i][j] = -4;
        
        for(int k=0;k<4;k++){
            int new_x = i + dx[k], new_y = j + dy[k];
            if(isValid(new_x, new_y, grid) && grid[new_x][new_y]>=0){
                backtrack(new_x, new_y, emptyCells-1, ans, grid);
            }
        }
        
        grid[i][j] = temp;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ans=0;
        int m = grid.size(), n = grid[0].size();
        int si, sj, emptyCells=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    si=i, sj=j;
                } 
                if(grid[i][j] !=-1) emptyCells+=1;
            }
        }
        
        backtrack(si, sj, emptyCells, ans, grid);
        
        
        return ans;
    }
};