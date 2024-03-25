class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool isValid(int x, int y, vector<vector<char>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
    bool dfs(vector<vector<char>>& board, string word, int i, int x, int y, vector<vector<bool>>& visited){
        
        if(i>=word.length()){
            return true;
        }
        
        bool ans=false;
        for(int k=0;k<4;k++){
            int new_x = x+dx[k];
            int new_y = y+dy[k];
            
            if(isValid(new_x, new_y, board) && !visited[new_x][new_y] && board[new_x][new_y] == word[i]){
                visited[new_x][new_y] = true;
                ans = ans || dfs(board, word, i+1, new_x, new_y, visited);
                visited[new_x][new_y] = false;
            }
        }
        
        return ans;
        
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]){
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    visited[i][j] = true;
                    if(dfs(board, word, 1, i, j, visited)){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};