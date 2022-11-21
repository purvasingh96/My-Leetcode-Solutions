class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool isValid(int x, int y, vector<vector<char>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        int ex = entrance[0], ey = entrance[1];
        queue<pair<int,int>> q;
        q.push({ex, ey});
        maze[ex][ey] = '+';
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
                    
                    if(isValid(new_x, new_y, maze) && maze[new_x][new_y]=='.'){
                        q.push({new_x, new_y});
                        if((new_x==0 || new_y == 0 || new_x == m-1 || new_y == n-1) && (new_x!=ex || new_y!=ey)){
                            return level+1;
                        }
                        maze[new_x][new_y] = '+';
                    }
                }
            }
            level+=1;
        }
        
        return -1;
    }
};