class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        vector<int> dp(nums.size(),0);
        int res=0;
        
        for(int i=2;i<nums.size();i++) {
            
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                dp[i] = dp[i-1]+1;
                res += dp[i];
            }
            
        }
        
        return res;
        
    }
};