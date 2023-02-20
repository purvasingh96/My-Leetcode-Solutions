class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool isValid(int x, int y, vector<vector<char>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
    
    void bfs(int i, int j, vector<vector<char>>& grid){
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j]='0';
        
        while(!q.empty()){
            auto f= q.front();
            q.pop();
            
            int x = f.first, y =f.second;
            
            for(int i=0;i<4;i++){
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if(isValid(new_x, new_y, grid) && grid[new_x][new_y]=='1'){
                    grid[new_x][new_y]='0';
                    q.push({new_x, new_y});
                }
            }
        }
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1') {
                    bfs(i, j, grid);
                    ans+=1;
                }
            }
        }
        return ans;
    }
};