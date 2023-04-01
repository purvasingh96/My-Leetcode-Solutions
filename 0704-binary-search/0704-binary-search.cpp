class Solution {
public:
    int search(vector<int>& nums, int target) {
        int idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(idx==nums.size()) return -1;
        return nums[idx]==target ? idx:-1;
    }
};