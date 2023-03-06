class Solution {
public:
    int findMin(vector<int>& nums) {
        // need to check low and high
        int n = nums.size();
        int low=0, high=n-1;
        
        while(low<high){
            if(nums[low] <= nums[high]) return nums[low];
            int mid = low + (high-low)/2;
            if(nums[low] > nums[mid]){
                high=mid;
            } else if(nums[mid] > nums[high]) {
                low=mid+1;
            }
            
        }
        
        if(nums[low] <= nums[high]) return nums[low];
        
        return -1;
    }
};