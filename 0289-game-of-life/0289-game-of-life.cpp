class Solution {
private:
    int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    
    bool checkBounds(int x, int y, vector<vector<int>>& board){
        return x>=0 && y>=0 && x<board.size() && y<board[0].size();
    }
    
    // live and dead
    pair<int, int> countLiveDead(int x, int y, vector<vector<int>>& board){
        int live=0, dead=0;
        
        for(int i=0;i<8;i++){
            int new_x = x+dx[i];
            int new_y = y+dy[i];
            
            if(checkBounds(new_x, new_y, board)){
                if(board[new_x][new_y] == 1){
                    live+=1;
                } else{
                    dead+=1;
                }
            }
            
        }
        
        return {live, dead};
    }
    

        
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> boardCopy = board;
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                auto p = countLiveDead(i, j, board);
                int live = p.first, dead=p.second;
                
                if(board[i][j] == 1){
                    if(live < 2 || live > 3) boardCopy[i][j] = 0;
                    else if(live >=2 && live <= 3) boardCopy[i][j] = 1;
                } else if(board[i][j] == 0){
                    if(live == 3) boardCopy[i][j] = 1;
                    else boardCopy[i][j] = 0;
                }
            }
        }
        
        board = boardCopy;
    }
};