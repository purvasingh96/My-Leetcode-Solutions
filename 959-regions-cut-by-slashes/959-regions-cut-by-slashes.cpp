class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    bool isValid(int i, int j, int n, vector<vector<int>>& g){
        return i>=0 && j>=0 && i<n && j<n && g[i][j]==0;
    }
    
    void dfs(int i, int j, vector<vector<int>>& g){
        
        g[i][j] = 1;
        
        for(int k=0;k<4;k++){
            int new_x = i+dx[k];
            int new_y = j+dy[k];
            
            if(isValid(new_x, new_y, g.size(), g)){
                dfs(new_x, new_y, g);
            }
        }
    }
    
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> g(n*3, vector<int>(n*3, 0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               if(grid[i][j] == '/') {
                   g[i*3][j*3+2] = g[i*3+1][j*3+1] = g[i*3+2][j*3] = 1;
               }
                
               else if(grid[i][j] == '\\') {
                   g[i*3][j*3] = g[i*3+1][j*3+1] = g[i*3+2][j*3+2] = 1; 
               }
            }
        }
        
        int regions=0;
        for(int i=0;i<n*3;i++){
            for(int j=0;j<n*3;j++){
                
                if(g[i][j] == 0){
                    
                    dfs(i, j, g);
                    regions+=1;
                }
                
            }
        }
        
        return regions;
    }
};