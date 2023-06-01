class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        char dir = 'R';
        vector<int> res;
        int startRow=0, startCol=0, endRow=matrix.size(), endCol= matrix[0].size();
        int sz = endRow * endCol;
        while(res.size()!=sz){
            // for(auto x:res) cout<<x<<" ";
            // cout<<"\n";
            if(dir == 'R'){
                int i = startRow;
                for(int j=startCol;j<endCol;j++) res.push_back(matrix[i][j]);
                dir = 'D';
                startRow+=1;
            } 
            
            else if(dir == 'D'){
                int j = endCol-1;
                for(int i=startRow;i<endRow;i++) res.push_back(matrix[i][j]);
                dir = 'L';
                endCol-=1;
            }
            
            else if(dir == 'L'){
                int i = endRow-1;
                for(int j=endCol-1;j>=startCol;j--) res.push_back(matrix[i][j]);
                dir = 'U';
                endRow-=1;
            }
            
            else if(dir == 'U'){
                int j = startCol;
                for(int i=endRow-1;i>=startRow;i--) res.push_back(matrix[i][j]);
                dir = 'R';
                startCol+=1;
            }
                
        }
        
        return res;
    }
};