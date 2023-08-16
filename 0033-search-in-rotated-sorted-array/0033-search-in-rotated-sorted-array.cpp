class Solution {
private:
    int findSplitPoint(vector<int>& nums){
        int n = nums.size();
        int l=0, r=n-1;
        
        while(l<r){
            int mid = l + (r-l)/2;
            
            if(nums[mid] > nums[n-1]){
                l = mid+1;
            } else r = mid;
            
        }
        
        return l;
        
    }
    
    int findVal(vector<int>& nums, int start, int end, int target){
        int l=start, r = end;
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) {
                r=mid-1;
            } else l = mid+1;
        }
        return nums[l] == target ? l:-1;
    }
public:
    int search(vector<int>& nums, int target) {
        // BS to find split point
        // BS to find element
        int idx = findSplitPoint(nums);
        cout<<idx;
        if(target >= nums[0] && idx-1>=0 && target <= nums[idx-1]){
            return findVal(nums, 0, idx-1, target);
        }
        
        return findVal(nums, idx, nums.size()-1, target);
        
    }
};