class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool isValid(int x, int y, vector<vector<int>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 0));
        int mindist = INT_MAX;
        int emptyLandValue = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j] == 1){
                    
                    mindist = INT_MAX;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    int level=0;
                    
                    while(!q.empty()){
                        
                        int sz=q.size();
                        level+=1;
                        
                        while(sz--){
                            
                            auto f = q.front();
                            q.pop();
                            int x = f.first, y = f.second;
                            
                            for(int k=0;k<4;k++){
                                
                                int new_x = x + dx[k];
                                int new_y = y + dy[k];
                                
                                
                                if(isValid(new_x, new_y, grid) 
                                   && grid[new_x][new_y] == emptyLandValue){
                                    
                                    grid[new_x][new_y] -=1;
                                    dist[new_x][new_y] += level;
                                    q.push({new_x, new_y});
                                    
                                    mindist = min(mindist, dist[new_x][new_y]);
                                    
                                }
                                
                            }
                            
                        }
                         
                    }
                    
                    emptyLandValue -= 1; 
                }
                
            }
        }
        
        return mindist == INT_MAX ? -1: mindist;
    }
};