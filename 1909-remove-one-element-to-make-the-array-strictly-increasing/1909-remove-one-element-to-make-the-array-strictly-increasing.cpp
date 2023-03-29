class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int cnt=0;
        for(int i=1;i<nums.size() && cnt<2;i++){
            if(nums[i] <= nums[i-1]){
                cnt+=1;
                if(i>=2 && nums[i-2] >= nums[i]){
                    nums[i] = nums[i-1];
                }
            }
        }
        return cnt<2;
    }
};