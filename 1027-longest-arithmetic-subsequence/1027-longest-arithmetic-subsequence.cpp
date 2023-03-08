class Solution {

public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(1003, INT_MIN));
        int res=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = nums[j] - nums[i] + 500;
                if(dp[j][diff]!=INT_MIN){
                    dp[i][diff] = max(dp[i][diff], dp[j][diff]+1);
                } else {
                    dp[i][diff] = max(2, dp[i][diff]);
                }
                
                res = max(res, dp[i][diff]);
            }
        }
        
        return res;
        
    }
};