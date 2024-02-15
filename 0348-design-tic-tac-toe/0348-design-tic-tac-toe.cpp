class TicTacToe {
public:
    vector<int> row_1;
    vector<int> col_1;
    vector<int> row_2;
    vector<int> col_2;
    int diag_1;
    int anti_diag_1;
    int diag_2;
    int anti_diag_2;
    int sz;
    TicTacToe(int n) {
        diag_1=0;
        diag_2=0;
        anti_diag_1=0;
        anti_diag_2=0;
        sz=n;
        row_1.resize(n, 0);
        col_1.resize(n, 0);
        row_2.resize(n, 0);
        col_2.resize(n, 0);
    }
    
    
    
    int move(int row, int col, int player) {
        if(player==1){
            row_1[row] +=1;
            col_1[col]+=1;
            
            if(row == col){
                diag_1+=1;
            }
            if(row+col == sz-1){
                anti_diag_1+=1;
            }
            
            if(row_1[row]==sz || col_1[col]==sz || diag_1 == sz || anti_diag_1 == sz){
                return 1;
            }
        } else {
           row_2[row] +=1;
            col_2[col]+=1;
            
            if(row == col){
                diag_2+=1;
            }
            if(row+col == sz-1){
                anti_diag_2+=1;
            }
            
            if(row_2[row]==sz || col_2[col]==sz || diag_2 == sz || anti_diag_2 == sz){
                return 2;
            } 
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */