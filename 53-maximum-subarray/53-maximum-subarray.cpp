class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far=nums[0];
        int best_sum=nums[0];
        
        for(int i=1;i<nums.size();i++){
            max_so_far = max(max_so_far+nums[i], nums[i]);
            best_sum = max(best_sum, max_so_far);
        }
        
        return best_sum;
    }
};