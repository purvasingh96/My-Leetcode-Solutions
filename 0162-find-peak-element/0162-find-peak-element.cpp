class Solution {
private:
    bool isPeak(vector<int>& nums, int mid){
        if(mid == 0){
            if(nums[mid] > nums[mid+1]){
                return true;
            } else {
                return false;
            }
        }
        
        if(mid == nums.size()-1){
            if(nums[mid] > nums[mid-1]){
                return true;
            } else {
                return false;
            }
        }
        
        return nums[mid-1] < nums[mid]  && nums[mid] > nums[mid+1];
    }
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1){
            return 0;
        }
        int l=0, r=nums.size()-1;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            if(isPeak(nums, mid)){
                return mid;
            } else {
                if(nums[mid] < nums[mid+1]){
                    l=mid+1;
                }  else{
                    r = mid-1;
                }
            }
            
        }
        
        return l;
    }
};