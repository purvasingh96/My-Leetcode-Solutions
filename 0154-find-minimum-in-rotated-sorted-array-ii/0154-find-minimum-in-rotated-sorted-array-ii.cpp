class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0, high=nums.size()-1;
        while(low<high){
            if(nums[low] < nums[high]) return nums[low];
            int mid = low + (high-low)/2;
            if(nums[low] > nums[mid]){
                high=mid;
            } else if(nums[mid]>nums[high]){
                low=mid+1;
            } else{
                
                while(low<high && nums[low] == nums[high] && nums[high]==nums[mid]){
                    low+=1;
                    high-=1;
                }
            }
        }
        
        return nums[low];
    }
};