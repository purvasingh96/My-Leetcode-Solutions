class Solution {
public:
    int minPathSum(vector<vector<int>>& nums) {
        int m = nums.size(), n = nums[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0]=nums[0][0];
        
        for(int i=1;i<m;i++){
            dp[i][0] = dp[i-1][0] +nums[i][0];
        }
        
        for(int j=1;j<n;j++){
            dp[0][j] = dp[0][j-1] + nums[0][j];
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                
                dp[i][j] = nums[i][j] + min(dp[i-1][j], dp[i][j-1]);
                
            }
        }
        
        // for(auto x:dp){
        //     for(auto y:x){
        //         cout<<y<<" ";
        //     }
        //     cout<<"\n";
        // }
            
            
            
        return dp[m-1][n-1];
        
    }
};