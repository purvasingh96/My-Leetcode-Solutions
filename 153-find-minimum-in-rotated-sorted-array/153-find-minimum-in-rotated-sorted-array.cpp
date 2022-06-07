class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1) return nums[0];
        
        if(nums[0] < nums[n-1]){
            return nums[0];
        }
        
        if(nums[n-2] > nums[n-1]){
            return nums[n-1];
        }
        
        int left=0, right=nums.size()-1;
        
        while(left<right){
            int mid = left + (right-left)/2;
            
            if(nums[mid] >= nums[0]){
                left=mid+1;
            }else{
                right=mid;
            }
        }
        
        return nums[left];
        
    }
};