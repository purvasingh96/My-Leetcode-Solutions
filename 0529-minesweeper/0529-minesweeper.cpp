class Solution {
private:
    
    int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

    bool isValid(int x, int y, vector<vector<char>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
    char returnMines(int x,int y, vector<vector<char>>& board){
        int mines=0;
        for(int i=0;i<8;i++){
            int newX = x+dx[i];
            int newY = y+dy[i];
            if(isValid(newX, newY, board) && board[newX][newY]=='M'){
                mines+=1;
            }
        }
        return mines+'0';
    }
    
    void dfs(int x, int y, vector<vector<char>>& board, vector<vector<bool>>& visited){
        
        if(board[x][y] == 'E'){
            char mines = returnMines(x, y, board);
            //cout<<"x: "<<x<<" y: "<<y<<"mines: "<<mines<<"\n";
            if(mines=='0'){
                board[x][y]='B';
                // recrusve reveal  
                for(int i=0;i<8;i++){
                    int newX = x+dx[i];
                    int newY = y+dy[i];
                    if(isValid(newX, newY, board) && !visited[newX][newY] && board[newX][newY]!='B'){
                        visited[newX][newY]=true;
                        dfs(newX, newY, board, visited);
                    }
                }
            } else {
               board[x][y] = mines; 
            }
            
        } 
    }
    
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x =click[0], y = click[1];
        if(board[x][y]=='M'){
            board[x][y]='X';
            return board;
        }
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[x][y]=true;
        dfs(x, y, board, visited);
        return board;
    }
};