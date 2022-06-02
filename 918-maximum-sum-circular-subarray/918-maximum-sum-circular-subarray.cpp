class Solution {
private:
    int kadane(vector<int>& nums){
        int best_sum=INT_MIN;
        int min_so_far = 0;
        for(int i=0;i<nums.size();i++){
            min_so_far = max(min_so_far+nums[i], nums[i]);
            best_sum = max(best_sum, min_so_far);
        }
        return best_sum;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int x = kadane(nums);
        cout<<x<<" ";
        int total_sum = 0;
        for(int i=0;i<nums.size();i++){
            total_sum += nums[i];
            nums[i]*=-1;
        }
        for(auto x:nums) cout<<x<<" ";
        int y = kadane(nums);
        cout<<y<<" ";
        if(total_sum + y == 0) return x;
        return max(x, (y+total_sum));
    }
};