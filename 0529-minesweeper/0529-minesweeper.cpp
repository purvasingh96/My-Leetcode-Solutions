class Solution {
private:
    int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    
    bool isValid(int x, int y, vector<vector<char>>& grid){
        return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
    
    int adjMines(int x, int y, vector<vector<char>>& grid){
        int mines=0;
        for(int i=0;i<8;i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(isValid(new_x, new_y, grid) && grid[new_x][new_y]=='M'){
                mines+=1;
            }
        }
        
        return mines;
    }
    
    void bfs(vector<vector<char>>& board, int x, int y){
        
        queue<pair<int, int>> q;
        q.push({x,y});
        
        while(!q.empty()){
                auto f = q.front();q.pop();
                int x = f.first, y = f.second;
                if(board[x][y]!='E') continue;
                
                int mines = adjMines(x, y, board);
                if(mines!=0){
                    board[x][y]=(mines+'0');
                } else{
                    board[x][y]='B';
                    
                    for(int i=0;i<8;i++){
                        int new_x = x+dx[i];
                        int new_y = y+dy[i];
                        if(isValid(new_x, new_y, board)){
                            q.push({new_x, new_y});
                        }
                    }
                }
            
        }
        
        
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0], y = click[1];
        if(board[x][y] == 'M'){
            board[x][y] = 'X';
            return board;
        }
        
        //if(board[x][y]!='E') return board;
        bfs(board, x, y);
        return board;
    }
};