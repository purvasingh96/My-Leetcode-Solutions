class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        
        while(left<right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) {
                right=mid;
            } else {
                left=mid+1;
            }
        }
        
        if(nums[left] < target) return left+1;
        
        return left;
    }
};