class Solution {
public:
    
    int bfs(vector<vector<int>>& grid, int x, int y, int totalHouses) {
        
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        int m = grid.size(), n = grid[0].size();
        
        int distance=0, housesVisited = 0;
        
        queue<pair<int, int>> q;
        q.push({x, y});
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[x][y] = true;
        int level=0;
        
        while(!q.empty() && housesVisited!=totalHouses) {
            
            int s=q.size();
            
            for(int i=0;i<s;i++) {
                
                auto curr = q.front();
                q.pop();
                
                int row = curr.first, col = curr.second;
                
                if(grid[row][col] == 1) {
                    
                    distance += level;
                    housesVisited += 1;
                    continue;
                    
                }
                
                for(auto d:dir) {
                    
                    int new_x = row + d[0];
                    int new_y = col + d[1];
                    
                    if(new_x>=0 && new_x<m && new_y>=0 && new_y<n) {
                        
                        if(!visited[new_x][new_y] && grid[new_x][new_y]!=2) {
                            
                            visited[new_x][new_y] = true;
                            q.push({new_x, new_y});
                            
                        }
                        
                        
                    }
                    
                    
                }
                
            }
            
            level += 1;
            
            
        }
        
        
        if(housesVisited!=totalHouses) {
            
            for(int i=0;i<m;i++) {
                for(int j=0;j<n;j++) {
                    
                    if(visited[i][j] && grid[i][j] == 0) {
                        grid[i][j] = 2;
                    }
                    
                }
            }
            return INT_MAX;
            
        }
        
        return distance;
    }
    
    
    
    int shortestDistance(vector<vector<int>>& grid) {
        
        int minDistance = INT_MAX;
        int m = grid.size(), n=grid[0].size();
        int totalHouse = 0;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                
                if(grid[i][j] == 1) totalHouse += 1;
                
            }
        }
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                
                if(grid[i][j] == 0) {
                    minDistance = min(minDistance, bfs(grid, i, j, totalHouse));
                }
                
            }
        }
        
        if(minDistance == INT_MAX) return -1;
        return minDistance;
        
    }
};