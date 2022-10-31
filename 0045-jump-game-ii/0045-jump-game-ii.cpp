class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[n-1] = 0;
        
        for(int pos=n-2;pos>=0;pos--){
            for(int steps=1;steps<=nums[pos];steps++){
                if(steps+pos < n){
                    if(dp[steps+pos] == -1) continue;
                    dp[pos] = min(dp[pos], 1+dp[steps+pos]);
                } 
            }
            if(dp[pos] == INT_MAX) dp[pos] = -1;
        }
        
        //for(auto x:dp) cout<<x<<" ";
        
        return dp[0];
    }
};