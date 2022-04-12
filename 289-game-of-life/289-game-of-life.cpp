class Solution {
public:
    int dir_x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dir_y[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    
    bool isValid(vector<vector<int>>& board, int x, int y) {
        int m = board.size();
        int n = board[0].size();
        
        return x>=0 && y>=0 && x<m && y<n;
    }
    
    int returnNeighours(vector<vector<int>>& board, int x, int y) {
        
        int neighbors = 0;
        
        for(int i=0;i<8;i++) {
            int new_x = x + dir_x[i];
            int new_y = y + dir_y[i];
            
            if(isValid(board, new_x, new_y)) {
                if(board[new_x][new_y] == 1 || board[new_x][new_y] == 3) neighbors +=1;
            } 
        }  
        
        return neighbors;
    }
    
    
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        // 2: alive in future, dead right now
        // 3: dead in future, alive now.
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                
                int neigh = returnNeighours(board, i, j);
                
                if(board[i][j] == 0) {
                    
                    if(neigh == 3) {
                        board[i][j] = 2;
                    }
                    
                } else {
                    
                    if(neigh < 2 || neigh > 3) {
                        board[i][j] = 3;
                    } 
                }
                
            }
        }
        // future state
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                
                if(board[i][j] == 2) {
                    board[i][j] = 1;
                } else if(board[i][j] == 3) {
                    board[i][j] = 0;
                }
                
                
            }
        }
        
        
    }
};