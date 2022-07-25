class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1, -1};
        int n = nums.size();
        int left=0, right=n-1;
        
        while(left<right){
            int mid = left + (right-left)/2;
            if(nums[mid] < target) left= mid+1;
            else right=mid;
        }
        
        cout<<"hre";
        
        if(nums[left]!=target) return {-1, -1};
        
        int start = left,  end=n-1;
        
        while(start<end){
            
            int mid = start + (end-start)/2;
            
            if(nums[mid]<=target) start = mid+1;
            else end=mid;
        }
        
        cout<<"hre";
        if(nums[start]==target) return {left, start};
        
        return {left, start-1};
    }
};