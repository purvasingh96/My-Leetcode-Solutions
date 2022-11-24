class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool isValid(int x, int y, vector<vector<char>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
    bool backtrack(int i, int x, int y, string& word, vector<vector<char>>& board) {
        if(i==word.length()) return true;
        bool ans=false;
        
        for(int k=0;k<4;k++){
            int new_x = x + dx[k];
            int new_y = y + dy[k];
            
            if(isValid(new_x, new_y, board) &&
               board[new_x][new_y] == word[i]){
                char t = board[new_x][new_y];
                board[new_x][new_y] = '.';
                ans = ans | backtrack(i+1, new_x, new_y, word, board);
                board[new_x][new_y] = t;
            }
        }
        
        return ans;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == word[0]){
                    char t = board[i][j];
                    board[i][j]='.';
                    if(backtrack(1, i, j, word, board)) {
                        return true;
                    }
                    board[i][j] = t;
                }
            }
        }
        
        return false;
    }
};