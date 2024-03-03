class Solution {
private:
    bool isPeak(vector<int>& nums, int i){
        if(i==0){
            return nums[1] < nums[0];
        } 
        
        if(i==nums.size()-1){
            return nums[nums.size()-2] < nums[i];
        }
        
        return nums[i-1] < nums[i] && nums[i] > nums[i+1];
    }
public:
    int findPeakElement(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        
        while(l<r){
            int mid = l + (r-l)/2;
            if(isPeak(nums,mid)){
                return mid;
            }
            if(nums[mid] < nums[mid+1]){
                l = mid+1;
            } else {
                r=mid-1;
            }
        }
        
        return l;
    }
};