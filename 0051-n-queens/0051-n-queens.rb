class Solution {
private:
    bool isValid(int row, int col, vector<string>& board){
        // col check
        int  n = board[0].length();
        for(int i=0;i<board.size();i++){
            if(board[i][col] == 'Q') return false;
            if(row-i >=0 && col-i >=0 && board[row-i][col-i]=='Q') return false;
            if(row-i>=0 && col+i < n && board[row-i][col+i]=='Q') return false;
            if(row+i<n && col-i >=0 && board[row+i][col-i] == 'Q') return false;
            if(row+i<n && col+i<n && board[row+i][col+i] == 'Q') return false;       
        }
        
        return true;
    }
    
    void backtrack(int row, vector<string>& board, vector<vector<string>>& ans){
        
        if(row == board.size()) {
            ans.push_back(board);
            return;
        }
        
        for(int col = 0;col<board[0].length();col++){
            if(isValid(row, col, board)){
                board[row][col] = 'Q';
                backtrack(row+1, board, ans);
                board[row][col] = '.';
            }
        }
        
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        for(int i=0;i<n;i++){
            string s(n, '.');
            board.push_back(s);
        }
        vector<vector<string>> ans;
        backtrack(0, board, ans);
        return ans;
    }
};