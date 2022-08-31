class Solution {
private:
    vector<vector<bool>> atlantic, pacific;
    vector<vector<int>> ans;
    
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& visited){
        if(visited[i][j]) return;
        int m = heights.size(), n= heights[0].size();
        
        visited[i][j] = true;
        
        if(atlantic[i][j] && pacific[i][j]) ans.push_back({i, j});
        
        for(int k=0;k<4;k++){
            int new_x = i + dx[k];
            int new_y = j + dy[k];
            
            if(new_x>=0 && new_y>=0 && new_x<m && new_y<n && heights[new_x][new_y] >= heights[i][j]){
                dfs(new_x, new_y, heights, visited);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        
        atlantic = pacific = vector<vector<bool>>(m, vector<bool>(n, false));
        
        for(int i=0;i<m;i++){
            dfs(i, 0, heights, pacific);
            dfs(i, n-1, heights, atlantic);
        }
        
        for(int j=0;j<n;j++){
            dfs(0, j, heights, pacific);
            dfs(m-1, j, heights, atlantic);
        }
        
        return ans;
    }
};