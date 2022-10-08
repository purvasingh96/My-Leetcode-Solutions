class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxsum = -1;
        int left=0, right=n-1;
        
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum < k) {
                maxsum = max(maxsum, sum);
                left+=1;
            } else right-=1;
        }
        
        return maxsum;
        
    }
};