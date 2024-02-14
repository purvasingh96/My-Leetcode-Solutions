class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    bool isValid(int i, int j, vector<vector<int>>& grid){
        return i>=0 && j>=0 && i<grid.size() && j<grid[0].size();
    }
    
    int dist(int p1x, int p1y, int p2x, int p2y){
        return abs(p2x - p1x) + abs(p2y - p1y);
    }
    
    int calculateMinDistance(vector<vector<int>>& buildings, int i, int j){
        int ans=0;
        for(auto b:buildings){
            ans += dist(b[0], b[1], i, j);
        }
        
        return ans;
    }
    
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& distances, vector<vector<int>>& count, int i, int j){
        int m = grid.size(), n = grid[0].size();
        queue<vector<int>> q;
        vector<vector<int>> visited(m, vector<int>(n, false));
        q.push({i, j});
        int d=1;
        while(q.size()!=0){
                int sz = q.size();
                
                while(sz--){
                    auto f = q.front();
                    q.pop();
                    int i=f[0], j=f[1];
                    
                    for(int k=0;k<4;k++){
                        int new_x = i+dx[k];
                        int new_y = j+dy[k];
                        
                        if(isValid(new_x, new_y, grid) && grid[new_x][new_y]==0
                           && visited[new_x][new_y]==false){
                            
                            visited[new_x][new_y]=true;
                            q.push({new_x, new_y});
                            distances[new_x][new_y] +=d; 
                            count[new_x][new_y]+=1;
                            
                        }
                    }
                }
                d+=1;
            }
    }
    
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), c=0, n = grid[0].size();
        vector<vector<int>> buildings;
        int globalMin = INT_MAX;
        vector<vector<int>> count(m, vector<int>(n, 0));
        vector<vector<int>> distances(m, vector<int>(n, 0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    c+=1;
                    bfs(grid, distances, count, i, j);
                }
            }
        }
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(count[i][j] == c){
                    // Empty space is accessible by all buildings
                    globalMin = min(globalMin, distances[i][j]);
                }
            }
        }
        
        return globalMin==INT_MAX?-1:globalMin;
        
    }
};