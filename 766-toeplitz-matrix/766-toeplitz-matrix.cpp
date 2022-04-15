class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        if(m == 1) return true;
        // col-wise testng
        
        for(int j=0;j<n;j++) {
            int i=0;
            int start = matrix[i][j];
            int temp=j;
            
            
            while(i<m && temp<n) {
                if(matrix[i][temp]!=start) return false;
                i+=1;
                temp+=1;
                
            }
            
        }
        
        cout<<"here";
        
        // row-wise checking
        
        for(int r=1;r<m;r++) {
            int c=0, temp=r;
            int start = matrix[r][c];
            while(temp<m && c<n) {
                if(matrix[temp][c] != start) return false;
                temp+=1;
                c+=1;
                
            }
        }
        return true;
    }
};