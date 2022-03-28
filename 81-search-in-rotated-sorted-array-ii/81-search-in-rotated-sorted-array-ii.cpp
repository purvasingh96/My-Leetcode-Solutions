class Solution {
public:
    bool binary_search(vector<int>& nums, int start, int end, int target) {
        while(start <= end) {
            int mid = start + (end-start)/2;
            
            if(nums[mid] == target) return true;
            
            else if(target > nums[mid]) start = mid+1;
            else end = mid-1;
        }
        return false;
        
    }
    
    
    bool search(vector<int>& nums, int target) {
        int start=0, end=0;
        if(nums.size()==1) return nums[0]==target;
        
        for(int i=0;i<nums.size();i++) {
            
            if(nums[i] == target) {
                return true;
            }
            
            if(i<nums.size()-1) {
                if(nums[i] >= nums[i+1]) {
                if(target >= nums[0] && target <= nums[i]) {
                    return binary_search(nums, 0, i, target);
                } else if(target >=nums[i+1] && target <= nums.back()) {
                    return binary_search(nums, i+1, nums.size()-1, target);
                }
                
                }
            }
            
             
         }
        
        return false;
        
    }
};