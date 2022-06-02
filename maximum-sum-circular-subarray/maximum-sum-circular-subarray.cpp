class Solution {
private:
    vector<int> kadane(vector<int>& nums){
        int best_max_sum=nums[0];
        int best_min_sum = nums[0];
        int min_so_far = nums[0];
        int max_so_far=nums[0];
        int total_sum=nums[0];
        
        for(int i=1;i<nums.size();i++){
            total_sum += nums[i];
            max_so_far = max(max_so_far+nums[i], nums[i]);
            best_max_sum = max(best_max_sum, max_so_far);
            
            min_so_far = min(min_so_far+nums[i], nums[i]);
            best_min_sum = min(best_min_sum, min_so_far);
        }
        return {total_sum, best_min_sum, best_max_sum};
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        auto f = kadane(nums);
        int total_sum = f[0];
        int min_sum = f[1];
        int max_sum = f[2];
        
        return total_sum==min_sum?max_sum:max(max_sum, (total_sum-min_sum));
    }
};