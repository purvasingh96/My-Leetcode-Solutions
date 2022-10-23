class Solution {
// private:
//     int dx[4] = {0, 1, 0, -1};
//     int dy[4] = {1, 0, -1, 0};
    
    
//     bool isValid(int x, int y, vector<vector<char>>& grid){
        
//         return x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y]!='X';
        
//     }
    
    
//     int bfs(queue<pair<int, int>>& q, vector<vector<char>>& grid){
        
//         int level=0;
        
//         while(!q.empty()){
//             int sz = q.size();
            
//             while(sz--){
//                 auto f = q.front();
//                 q.pop();
                
//                 int x = f.first;
//                 int y = f.second;
                
//                 if(grid[x][y] == '*') return level;
                
//                 grid[x][y] = '&';
                
//                 for(int i=0;i<4;i++){
//                     int new_x = x+dx[i];
//                     int new_y = y+dy[i];
                    
//                     if(isValid(new_x, new_y, grid) && grid[new_x][new_y]!='&') q.push({new_x, new_y});
//                 }
                
//             }
            
//             level+=1;
//         }
        
//         return -1;
        
//     }
public:
    int getFood(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // To traverse in all directions i.e. north, east, south, and west
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};       
        
        // Standard requirement of BFS!
        queue<pair<int, int>> q;

        // Get the starting location in the Grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '*') {
                    q.push(make_pair(i, j));
                    // We found the starting place. Now, break from this loop.
                    break;
                }
            }
        }
        
        int steps = 0;
        while (!q.empty()) {
            steps++;
            
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto elem = q.front(); q.pop();
               
                // Traverse in each directions i.e.  north, east, south, and west
                for (int i = 0; i < dirs.size(); i++) {
                    int x = elem.first  + dirs[i][0];
                    int y = elem.second + dirs[i][1];
                
                    // If obstacle or reaching boundaries just continue
                    if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 'X')
                        continue;
                
                    // We found the food
                    if (grid[x][y] == '#')
                        return steps;
                    
                    // Mark this cell as visited by putting obstacle ('X')
                    grid[x][y] = 'X';
                    q.push(make_pair(x, y));
                }
            }
        }
        return -1;
    }
};