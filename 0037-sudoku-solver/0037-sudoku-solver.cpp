class Solution {
private:
    bool isValid(int val, int i, int j, vector<vector<char>>& board){
    
        for(int x=0;x<9;x++){
            if(board[i][x] == val) return false;
            if(board[x][j] == val) return false;
            if(board[(i/3)*3 + (x/3)][(j/3)*3 + (x%3)] == val) return false;
        }
        
        return true;
    }
    
    
    
    bool dfs(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                
                if(board[i][j] == '.'){
                    
                    
                    for(char num='1';num<='9';num++){
                        
                        if(isValid(num, i, j, board)){
                            board[i][j] = num;
                            if(dfs(board)) return true;
                            board[i][j] = '.';
                        }
                        
                        
                    }
                    
                    return false;
                    
                }
                
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board);
    }
};