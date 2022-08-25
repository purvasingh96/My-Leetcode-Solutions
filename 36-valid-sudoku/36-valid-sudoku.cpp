class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> row(9), col(9), block(9);
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                
                if(board[i][j]!='.'){
                    int val = board[i][j] -' 0';
                    int idx = ((i/3)*3 + j/3);

                    if(row[i].count(val) || col[j].count(val) || block[idx].count(val)) {
                        return false;
                    }

                    row[i].insert(val);
                    col[j].insert(val);
                    block[idx].insert(val);
                }
            }
        }
        
        return true;
    }
};