class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        queue<pair<int, int>> q;
        int m = maze.size(), n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        q.push({start[0], start[1]});
        visited[start[0]][start[1]] = true;
        
        while(!q.empty()){
            
            auto f = q.front();
            q.pop();
            int x = f.first;
            int y = f.second;
            
            if(x==destination[0] && y==destination[1]) return true;
            
            visited[x][y] = true;
            
            for(int i=0;i<4;i++) {
                
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                
                while(new_x>=0 && new_y>=0 && new_x<m && new_y<n && maze[new_x][new_y]==0){
                    new_x += dx[i];
                    new_y += dy[i];
                }
                
                if(!visited[new_x - dx[i]][new_y - dy[i]]) {
                    q.push({(new_x - dx[i]), (new_y - dy[i])});
                    visited[new_x - dx[i]][new_y - dy[i]] = true;
                }
                
            }
        }
                
            
           return false; 
            
        }
        
        
    
};