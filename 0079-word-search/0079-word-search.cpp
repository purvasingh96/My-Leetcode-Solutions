class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    bool isValid(int x, int y, vector<vector<char>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
    
    bool dfs(int x, int y, int idx, vector<vector<char>>& board, string word){
        if(idx >= word.length()) return true;
        
        bool ans=false;
        
        for(int i=0;i<4;i++){
            int new_x = x + dx[i];
            int new_y =  y + dy[i];
            if(isValid(new_x, new_y, board) && board[new_x][new_y]!='#' && board[new_x][new_y]==word[idx]){
                char temp = board[new_x][new_y];
                board[new_x][new_y] = '#';
                bool val = dfs(new_x, new_y, idx+1, board, word);
                //cout<<"val: "<<val<<"\n";
                ans = ans or val;
                board[new_x][new_y] = temp;
            }
        }
        
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == word[0]){
                    //cout<<"here";
                    char temp = board[i][j];
                    board[i][j] = '#';
                    if(dfs(i, j, 1, board, word)) return true;
                    board[i][j] = temp;
                }
            }
        }
        
        return false;
    }
};