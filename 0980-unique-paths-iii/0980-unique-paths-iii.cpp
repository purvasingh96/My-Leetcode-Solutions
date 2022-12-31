class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool isValid(int x, int y, vector<vector<int>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
    
    void dfs(int i, int j, vector<vector<int>>& grid, int& count, int obstacleFreeCubes){
        
        if(obstacleFreeCubes == 1 && grid[i][j] == 2) {
            count+=1;
            return;
        }
        
        int temp = grid[i][j];
        grid[i][j] = -1;
        
        for(int k=0;k<4;k++){
            int new_x = i + dx[k];
            int new_y = j + dy[k];
            
            if(isValid(new_x, new_y, grid) && grid[new_x][new_y]!=-1){
                
                dfs(new_x, new_y, grid, count, obstacleFreeCubes-1);
            }
        }
        
        grid[i][j] = temp;
    }
    
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        // calculate 
        int count=0, si, sj;
        int obstacleFreeCubes=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] >=0) obstacleFreeCubes+=1;
                 if(grid[i][j] == 1) {
                    si=i;
                    sj=j;
                }
            }
        }
        
        cout<<"working";
        
        dfs(si, sj, grid, count, obstacleFreeCubes);
        return count;
    }
};