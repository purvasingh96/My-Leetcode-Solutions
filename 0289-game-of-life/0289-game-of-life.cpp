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
                if(board[new_x][new_y] == 1 || board[new_x][new_y] == 4 || board[new_x][new_y] == 5){
                    live+=1;
                } else{
                    dead+=1;
                }
            }
            
        }
        
        return {live, dead};
    }
    
    
    void changeState(int x, int y, vector<vector<int>>& board){
        auto p = countLiveDead(x, y, board);
        int live = p.first, dead = p.second;
        int state = board[x][y];
        
        if(state == 1){
            if(live < 2) board[x][y] = 5;
            else if(live >= 2 && live<=3) board[x][y] = 4;
            else if(live > 3) board[x][y]=5;
        }
        
        else if(state==0) {
            if(live == 3) board[x][y]=2;
            else board[x][y] = 3;
        }
        
    }
        
public:
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                changeState(i, j, board);
            }
        }
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == 2 || board[i][j] == 4 || board[i][j]==1){
                    board[i][j]=1;
                } else if(board[i][j] == 3 || board[i][j] == 5 || board[i][j]==0){
                    board[i][j] = 0;
                }
            }
        }
        
    }
};