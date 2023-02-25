class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int localsum=nums[0], globalsum=nums[0];
        for(int i=1;i<nums.size();i++){
            localsum = max(localsum+nums[i], nums[i]);
            globalsum = max(globalsum, localsum);
        }
        
        return globalsum;
    }
};