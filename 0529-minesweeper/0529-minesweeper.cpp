class Solution {
private:
    int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

    bool isValid(int x, int y, vector<vector<char>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
    int count(int x, int y, vector<vector<char>>& board){
        int c=0;
        for(int k=0;k<8;k++){
            int new_x = x+dx[k];
            int new_y = y+dy[k];
            if(isValid(new_x, new_y, board) && board[new_x][new_y]=='M'){
                c+=1;
            }
        }
        
        return c;
    }
    void dfs(int x, int y, vector<vector<char>>& board, vector<vector<bool>>& visited){
        if(board[x][y] == 'M'){
            board[x][y] = 'X';
            return;
        }
        
        if(board[x][y] == 'E'){
            int c = count(x, y, board);
            if(c == 0){
                board[x][y] = 'B';
                for(int k=0;k<8;k++){
                    int new_x = x+dx[k];
                    int new_y = y+dy[k];
                    if(isValid(new_x, new_y, board) && 
                       !visited[new_x][new_y]){
                        visited[new_x][new_y] = true;
                        dfs(new_x, new_y, board, visited);
                    }
                }
            } else {
                board[x][y] = c+'0';
            }
        }
        
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        dfs(click[0], click[1], board, visited);
        return board;
        
    }
};