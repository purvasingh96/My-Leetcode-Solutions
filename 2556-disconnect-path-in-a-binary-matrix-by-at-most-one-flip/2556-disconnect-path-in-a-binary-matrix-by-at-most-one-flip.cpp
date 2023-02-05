class Solution {
private:
    int dx[2] = {0, 1};
    int dy[2] = {1, 0};

    bool isValid(int x, int y, vector<vector<int>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y]==1;
    }
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        
        int c=0, m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0]=true;
        
        if(isValid(0, 1, grid)) {
            visited[0][1]=true;
            q.push({0, 1});
        }
        
        if(isValid(1, 0, grid)){
            visited[1][0]=true;
            q.push({1, 0});
        }
        
        while(!q.empty()){
            
            int sz = q.size();
            
            if(sz==1){
              auto f = q.front();
                if(f!= pair<int, int>{m-1, n-1}) return true;
            }
            
            while(sz--){
                
                auto f = q.front();
                q.pop();
                
                int x = f.first, y = f.second;
                
                for(int i=0;i<2;i++){
                    int new_x = x+dx[i];
                    int new_y = y+dy[i];
                    
                    if(isValid(new_x, new_y, grid) && !visited[new_x][new_y]){
                        visited[new_x][new_y]=true;
                        q.push({new_x, new_y});
                    }
                }
                
            }
            
        }
        
        return !visited[m-1][n-1];
        
        
    }
};