class Solution {
private:
    int dfs(int r, int c, vector<vector<int>>& grid){
        vector<int> xs;
        vector<int> ys;
        int count=0;
        
        for(int i=r+1;i<grid.size();i++){
            if(grid[i][c]==1) xs.push_back(i);  
        }
        
        for(int j=c+1;j<grid[0].size();j++){
            if(grid[r][j]==1) ys.push_back(j);
        }
        
        
        for(auto x:xs){
            for(auto y:ys){
                if(grid[x][y]==1){
                    count+=1;
                }
            }   
        }
        return count;
        
    }
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    ans+= dfs(i, j, grid);
                    //break;
                }
            }
            //break;
        }
        
        return ans;
    }
};