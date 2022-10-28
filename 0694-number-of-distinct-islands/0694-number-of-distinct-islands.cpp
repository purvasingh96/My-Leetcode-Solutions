class Solution {
private:
    unordered_set<string> st;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    bool isValid(int x, int y, vector<vector<int>>& grid){
        return x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y]==1;
    }
    
    void dfs(int x, int y, vector<vector<int>>& grid, string& path){
        if(!isValid(x, y, grid)) return;
        grid[x][y] = -1;
        
        vector<string> dir = {"U", "R", "D", "L"};
        for(int i=0;i<4;i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            
            path += dir[i];
            
            dfs(new_x, new_y, grid, path);
        }
    }
    
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        string path = "";
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    string path="";
                    dfs(i, j, grid, path);
                    //cout<<path<<"\n";
                    st.insert(path);
                }        
            }
        }
        
        return st.size();
    }
};