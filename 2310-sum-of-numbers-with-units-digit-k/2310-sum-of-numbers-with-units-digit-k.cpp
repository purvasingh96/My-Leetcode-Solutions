class Solution {
private:
    int coinchange(vector<int> nums, int amount){
        vector<int> dp(amount+1, amount+1);
        dp[0]=0;
        
        for(int i=0;i<=amount;i++){
            for(int j=0;j<nums.size();j++){
                
                if(nums[j]<=i && dp[i-nums[j]]!=amount+1){
                    
                    dp[i] = min(dp[i], 1+dp[i-nums[j]]);
                    
                }
                
            }
        }
        
        return dp[amount];
    }
public:
    int minimumNumbers(int num, int k) {
        vector<int> nums;
        
        for(int i=0;i<=num;i++){
            if(i%10==k) nums.push_back(i);
        }
        
        int ans = coinchange(nums, num);
        return ans==num+1?-1:ans;
    }
};