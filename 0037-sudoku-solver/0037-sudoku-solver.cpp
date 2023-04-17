#include <cmath>

class Solution {
private:
    vector<vector<char>> ans;
    int boxId(int x, int y){
        return (floor(x/3)*3+y/3);
    }
    
    bool isValid(int x, int y, char val, vector<unordered_set<char>>& boxes, vector<vector<char>>& grid){
        // row wise
       
        int m = grid.size(), n = grid[0].size();
        
        for(int i=0;i<m;i++){
            if(grid[i][y] == val) return false;
        }
        
        for(int j=0;j<n;j++){
            if(grid[x][j] == val) return false;
        }
        
        int idx = boxId(x, y);
        if(boxes[idx].count(val)) return false;
        return true;
    }
    
    void dfs(int k, vector<vector<char>>& board, vector<unordered_set<char>>& boxes, vector<vector<int>>& coords, int& totalDots){
        
//         if(totalDots==0) {
//             if(ans.size()==0) ans=board;
            
//             return;
//         }
        
        if(k>=coords.size()) {
            return;
        };
        
        int x = coords[k][0], y = coords[k][1];
        if(board[x][y] =='.'){
            for(int i=1;i<=9;i++){
                char target = i+'0';
                if(isValid(x, y, target, boxes, board)){
                    int id = boxId(x, y);
                    boxes[id].insert(target);
                    board[x][y] = target;
                    totalDots-=1;
                    dfs(k+1, board, boxes, coords, totalDots);
                    if(totalDots!=0){
                        totalDots+=1;
                        board[x][y] = '.';
                        boxes[id].erase(target);
                    }
                    
                }
            }
               
        }
        
        
    }
    
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> coords;
        int total=0;
        vector<unordered_set<char>> boxes(9);
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == '.'){
                    total+=1;
                    coords.push_back({i, j});
                } else {
                    int id = boxId(i, j);
                    boxes[id].insert(board[i][j]);
                }
            }
        }
        dfs(0, board, boxes, coords, total);
        //board=ans;
        
    }
};