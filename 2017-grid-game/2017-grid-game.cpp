class Solution {
private:
    long long helper(vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> ps(m, vector<long long>(n, 0));
        
        for(int j=0;j<n;j++){
            if(j == 0){
              ps[0][j] = grid[0][j];
              ps[1][j] = grid[1][j];
            } else {
               ps[0][j] = grid[0][j] + ps[0][j-1];
               ps[1][j] = grid[1][j] + ps[1][j-1]; 
            }
            
        }
       
        
        long long maxVal=LONG_MIN, ans=LONG_MAX;
        long long pos, sum=0;
        
        for(int pos=n-1;pos>=0;pos--){
             
                //cout<<"pos: "<<pos<<"\n";
                long long sumUpper = ps[0][n-1] - ps[0][pos];
                long long sumLower = pos==0?0:ps[1][pos-1];
                
                ans = min(ans, max(sumUpper, sumLower));
            
        }
        
       //cout<<"pos: "<<pos;
        
        return ans;
        
    }
public:
    long long gridGame(vector<vector<int>>& grid) {
        return helper(grid);
    }
};