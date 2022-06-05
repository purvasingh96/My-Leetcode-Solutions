class Solution {
private:
    bool isValid(vector<string>& board, int row, int col){
        // check row
        for(int i=row;i>=0;i--){
            if(board[i][col] == 'Q') return false;
        } 
        
        // check left diagnol
        for(int i=row, j=col;i>=0 && j>=0;--i, --j){
            if(board[i][j]=='Q') return false;
        }
        
        // check right diagnol
        for(int i=row,j=col;i>=0 && j<board.size();--i,++j){
            if(board[i][j] == 'Q') return false;
        }
        
        return true;
    }
    
    void dfs(vector<string>& board, vector<vector<string>>& res, 
            int row){
        
        if(row == board.size()){
            res.push_back(board);
            return;
        }
        
        for(int j=0;j<board.size();j++){
            if(isValid(board, row, j)){
                board[row][j] = 'Q';
                dfs(board, res, row+1);
                board[row][j] = '.';
            }
        }
        
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        dfs(board, res, 0);
        return res;
    }
};