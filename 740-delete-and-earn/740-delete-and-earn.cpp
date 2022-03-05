class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int left=0;
        vector<int> dp(nums.size(), 0);
        
        dp[0]=nums[0];
        
        for(int i=1;i<nums.size();i++) {
            int left = i-1;
            while(left >=0 && (nums[left] == nums[i] || nums[i]-nums[left] == 1)) {
                left-=1;
            }
            
            if(nums[i] == nums[i-1]) {
                
                
                    int x = nums[i];
                    while(i<nums.size() && nums[i]==nums[i-1]) {
                        x+=nums[i];
                        if(left<0) dp[i] = max(x, dp[i-1]);
                        else dp[i] = max(dp[left]+x, dp[i-1]);
                        i+=1;
                    }
                
                i-=1;
                
                
            }
            
            else if(nums[i] - nums[i-1] == 1) {
                
                if(left<0) dp[i] = max(nums[i], dp[i-1]);
                 else dp[i] = max((nums[i] + dp[left]), dp[i-1]);
                
                
            } else {
                
                dp[i] = nums[i] + dp[i-1];
                
                
                
            }
            
        }
        
        return dp.back();
        
        
        
    }
};