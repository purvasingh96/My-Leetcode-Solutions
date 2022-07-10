class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        
        vector<vector<int>> memo(nums.size(), vector<int>(nums.size(), 0));
        
        return helper(memo, nums, 1, nums.size()-2);
    }
    
    int helper(vector<vector<int>>& memo, vector<int>& nums, int left, int right) {
        
        if(right - left < 0) return 0;
        
        if(memo[left][right] > 0) return memo[left][right];
        
        int result = 0;
        
        for(int i=left;i<=right;i++) {
            
            int gain = nums[left-1]*nums[i]*nums[right+1];
            
            int remaining = helper(memo, nums, left, i-1) + helper(memo, nums, i+1, right);
            
            result = max(result, remaining + gain);
            
        }
        
        memo[left][right] = result;
        
        return result;
        
    }
};