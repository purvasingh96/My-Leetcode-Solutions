class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int building=0;
        vector<vector<vector<int>>> dist(m, vector<vector<int>>(n, vector<int>()));
        
        queue<pair<int, int>> q;
        
        int reachTime = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j] == 1){
                    building+=1;
                    int distance=0;
                    q.push({i, j});
                    
                    while(!q.empty()){
                        int sz = q.size();
                        distance+=1;
                        while(sz--){
                            
                            auto f = q.front();
                            q.pop();
                            
                            int x = f.first, y = f.second;
                            
                            for(int i=0;i<4;i++){
                                int new_x = x + dx[i];
                                int new_y = y + dy[i];
                                
                                if(new_x >=0 && new_y >=0 && new_x<m && new_y<n && grid[new_x][new_y]==reachTime){
                                    grid[new_x][new_y]-=1;
                                    dist[new_x][new_y].push_back(distance);
                                    q.push({new_x, new_y});
                                }
                            }
                        }
                        
                        
                        
                    }
                 reachTime-=1;   
                }
                
                
                
            }
        }
        
        int res = INT_MAX;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                
                
                if(dist[i][j].size() == building){
                    
                    int total = accumulate(dist[i][j].begin(), dist[i][j].end(), 0);
                    res = min(res, total);
                    
                }
                
                
                
            }
        }
        
        return res==INT_MAX?-1:res;
        
        
    }
};