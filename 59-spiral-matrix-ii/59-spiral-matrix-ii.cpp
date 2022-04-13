class Solution {
public:

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> grid(n, vector<int>(n, -1));
        
        int r1=0, r2=n-1, c1=0, c2=n-1;
        int num=0;
        
        while(r1<=r2 && c1<=c2) {
            
            for(int i=c1;i<=c2;i++){
                grid[r1][i] = ++num;
            }
            
            for(int i=r1+1;i<=r2;i++) {
                grid[i][c2] = ++ num;
            }
            
            if(r1<r2 && c1<c2) {
                
                for(int i=c2-1;i>c1;i--) {
                    grid[r2][i] = ++num;
                }
                
                for(int i=r2;i>r1;i--) {
                    grid[i][c1] = ++num;
                }
                
                
            }
            
            c2--;
            c1++;
            r1++;
            r2--;
            
            
        }
        
        
        return grid;
    }
};