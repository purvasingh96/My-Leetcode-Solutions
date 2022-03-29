class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        if(nums.size()==1) return nums[0]==target?0:-1;
        
        while(left <= right) {
            
            int mid = left + (right - left)/2;
            
            if(target == nums[mid]) return mid;
            
            else if(target > nums[mid]) left = mid+1;
            else right = mid-1;
            
        }
        
        return nums[left] == target?left:-1;
    }
};