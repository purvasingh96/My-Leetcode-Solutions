class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        // O(logN) => binary search approach.
        if(nums.size()==1) return 0;
        
        int low = 0, high = nums.size()-1;
        
        while(low<=high) {
            
            int mid = low + (high-low)/2;
            
            
            if(mid-1>=0 && mid+1<nums.size()) {
                if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                    return mid;
                }
                
                else if(nums[mid] <= nums[mid+1]) low = mid+1;
            
                else if(nums[mid] <= nums[mid-1]) high = mid-1;
                
            }  else if(mid-1 == -1) {
                
                if(nums[mid] > nums[mid+1]) return mid;
                else if(nums[mid] <=nums[mid+1]) low = mid+1;
                
            } else if(mid+1 == nums.size()) {
                
                if(nums[mid] > nums[mid-1]) return mid;
                else if(nums[mid]<=nums[mid-1]) high = mid-1;
                
            }
            
        }
        
        return 0;
        
    }
};