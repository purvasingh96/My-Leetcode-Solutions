class Solution {
private:
    // clockwise 
    int x_dir[4] = {-1, 0, 1 , 0};
    int y_dir[4] = {0, 1, 0, -1};
public:
    bool isValid(vector<vector<bool>> visited, int n, int x, int y) {
        return x>=0 && y>=0 && x<n && y<n && visited[x][y]==false;
    }
    
    bool breakLoop(vector<vector<bool>> visited, int n, int x, int y) {
        int invalids=0;
        
        for(int i=0;i<4;i++) {
            int new_x = x + x_dir[i];
            int new_y = y + y_dir[i];
            
            if(!isValid(visited, n, new_x, new_y)) {
                invalids += 1;
            } else {
                return false;
            }
        }
        //cout<<"invalids: "<<invalids<<"\n";
        return (invalids == 4);
    }
    
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> grid(n, vector<int>(n, -1));
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        int row=0, col=0, num=1;
        grid[0][0] = num;
        int dir_idx = 0;
        
        while(true) {
            //bool found = false;
            
            for(int i=dir_idx;i%4<4;i++) {
                i=i%4;
                
                int new_x = row + x_dir[i];
                int new_y = col + y_dir[i];
                
                
                
                if(isValid(visited, n, new_x, new_y)) {
                        //found=true;
                        visited[row][col] = true;
                        row = new_x;
                        col = new_y;
                        num+=1;
                        //cout<<row<<" "<<col<<" "<<num<<"\n";
                        grid[row][col] = num;
                        dir_idx = i;
                        break;
                    } 
                
                if(breakLoop(visited, n, row, col)) return grid;
                
            }
            
            
        }
        
        
        return grid;
    }
};