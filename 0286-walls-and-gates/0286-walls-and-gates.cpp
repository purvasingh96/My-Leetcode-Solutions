class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    bool isValid(int x, int y, vector<vector<int>>& rooms){
        return x>=0 && y>=0 && x<rooms.size() && y<rooms[0].size() && rooms[x][y]==INT_MAX;
    }
    
    void bfs(vector<vector<int>>& rooms, queue<pair<int, int>>& q) {
        int m = rooms.size(), n = rooms[0].size();
        
        int level=0;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                
                auto f = q.front();
                q.pop();
                
                int x = f.first, y = f.second;
                
                for(int i=0;i<4;i++){
                    
                    int new_x = x + dx[i];
                    int new_y = y + dy[i];
                    
                    if(isValid(new_x, new_y, rooms)) {
                        rooms[new_x][new_y] = rooms[x][y]+1;
                        q.push({new_x, new_y});
                    }
                    
                }
                
                
            }
            
        }
        
    }
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> q;
        
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[0].size();j++){
                if(rooms[i][j] == 0){
                    q.push({i, j});
                }
            }
        }
        
        bfs(rooms, q);
    }
};