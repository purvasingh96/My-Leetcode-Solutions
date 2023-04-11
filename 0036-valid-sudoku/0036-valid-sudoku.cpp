class Solution {
private:
    int boxId(int x, int y){
        return ((x/3)*3+y/3);
    }
    
    bool isValid(int x, int y, vector<unordered_set<int>>& boxes, vector<vector<char>>& grid){
        // row wise
        int m = grid.size(), n = grid[0].size();
        
        for(int i=0;i<m;i++){
            if(grid[i][y] == grid[x][y] && i!=x) return false;
        }
        
        for(int j=0;j<n;j++){
            if(grid[x][j] == grid[x][y] && j!=y) return false;
        }
        
        int idx = boxId(x, y);
        if(boxes[idx].count(grid[x][y])) return false;
        boxes[idx].insert(grid[x][y]);
        return true;
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& grid) {
        vector<unordered_set<int>> boxes(9);
        int m = grid.size(), n = grid[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!='.' && !isValid(i, j, boxes, grid)){
                    return false;
                }
            }
        }
        
        return true;
    }
};