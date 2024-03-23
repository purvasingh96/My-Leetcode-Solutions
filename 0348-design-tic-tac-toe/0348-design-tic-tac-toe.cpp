class TicTacToe {
public:
    int diag_1;
    int diag_2;
    int anti_diag_1;
    int anti_diag_2;
    vector<int> rows_1;
    vector<int> rows_2;
    vector<int> cols_1;
    vector<int> cols_2;
    int m;
    TicTacToe(int n) {
        diag_1=0;
        diag_2=0;
        anti_diag_1=0;
        anti_diag_2=0;
        rows_1.resize(n, 0);
        rows_2.resize(n, 0);
        cols_1.resize(n, 0);
        cols_2.resize(n, 0);
        m=n;
    }
    
    int move(int row, int col, int player) {
        if(player==1){
            rows_1[row]+=1;
            cols_1[col]+=1;
            
            if(row == col){
                diag_1+=1;
            } 
            
            if(row + col == m-1){
                anti_diag_1 +=1;
            } 
            
            if(rows_1[row]==m || cols_1[col] == m || diag_1 == m || anti_diag_1 == m){
                return 1;
            }
        } else {
            rows_2[row]+=1;
            cols_2[col] += 1;
            
            if(row == col){
                diag_2 += 1;
            }
            if(row + col == m-1){
                anti_diag_2 += 1;
            }
            
            if(rows_2[row] == m || cols_2[col] == m || diag_2 == m || anti_diag_2 == m){
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