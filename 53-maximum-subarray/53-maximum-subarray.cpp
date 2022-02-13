class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int prev = nums[0];
        int global_max = nums[0];
        
        for(int i=1;i<nums.size();i++) {
            
            prev = max(nums[i], (prev+nums[i]));
            global_max = max(prev, global_max);
            
        }
        
        return global_max;
        
    }
};