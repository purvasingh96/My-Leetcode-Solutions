class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        // O(logN) => binary search approach.
        int n = nums.size();
        if(n==1) return 0;
        if(n == 2) return nums[0] > nums[1] ? 0:1;
        
        int low = 1, high = nums.size()-2;
        
        while(low<=high) {
            
            int mid = low + (high-low)/2;
            
                if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                    return mid;
                }
                
                else if(nums[mid] < nums[mid+1]) low = mid+1;
            
                else if(nums[mid] <= nums[mid-1]) high = mid-1;
            
        }
        
        if(nums[0]>nums[1]) return 0;
        
        if(nums[n-1] > nums[n-2]) return n-1;
        return -1;
        
        
        
        
        return 0;
        
    }
};