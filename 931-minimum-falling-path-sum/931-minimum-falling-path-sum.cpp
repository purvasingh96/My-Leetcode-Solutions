class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& nums) {
        int m = nums.size(), n = nums[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int j=0;j<n;j++){
            dp[0][j]=nums[0][j];
        }
        
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                
                int x = dp[i-1][j] + nums[i][j];
                if(j-1>=0){
                    x = min(x, nums[i][j]+dp[i-1][j-1]);
                } 
                
                if(j+1<n){
                    x = min(x, nums[i][j]+dp[i-1][j+1]);
                }
                
                dp[i][j] = x;
                
            }
                
            
        }
        
        int res=INT_MAX;
        for(int j=0;j<n;j++){
            res=min(res, dp[m-1][j]);
        }
        
        for(auto x:dp){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<"\n";
        }
        return res;
    }
};