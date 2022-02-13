class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        vector<int> res(nums.size());
        int global_max = nums[0];
        res[0] = nums[0];
        
        for(int i=1;i<nums.size();i++) {
            
            res[i] = max(nums[i], (res[i-1]+nums[i]));
            global_max = max(res[i], global_max);
            
        }
        
        return global_max;
        
    }
};