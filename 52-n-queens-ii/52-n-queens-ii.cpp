class Solution {
private:
    bool isValid(vector<string>& board, int row, int col){
        
        // check col
        for(int i=row;i>=0;i--){
            if(board[i][col]=='Q') return false;
        }
        
        // check left diagnol
        for(int i=row,j=col;i>=0 && j>=0;--i,--j){
            if(board[i][j] == 'Q') return false;
        }
        
        // check right diagnol
        for(int i=row,j=col;i>=0 && j<board.size();--i,++j){
            if(board[i][j] == 'Q') return false;
        }
        
        return true;
        
    }
    
    void dfs(int row, vector<string>& board, vector<vector<string>>& res){
        if(row == board.size()){
            res.push_back(board);
            return;
        }
        
        for(int j=0;j<board.size();j++){
            if(isValid(board, row, j)){
                board[row][j] = 'Q';
                dfs(row+1, board, res);
                board[row][j]='.';
            }
        }
    }
    
public:
    int totalNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        dfs(0, board, res);
        
        return res.size();
    }
};