class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int m = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2!=0) return false;
        
        int n = sum/2;
        
        vector<vector<bool>> dp(m+1, vector<bool>(n+1));
        
        for(int i=0;i<=m;i++){
            dp[i][0] = true;
        }
        
        for(int j=0;j<=n;j++){
            dp[0][j] = false;
        }
        
        dp[0][0] = true;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                
                dp[i][j] = dp[i-1][j];
                
                if(j >= nums[i-1]) {
                    dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
                }
                
            }
        }
        
        return dp[m][n];
    }
};