class Solution {
private:
    int leftMost(int left, int right, vector<int>& nums, int target){
        int ans=-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target){
                ans = mid;
                right = mid-1;
            } else if(nums[mid] > target){
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        
        return ans;
    }
    
    int rightMost(int left, int right, vector<int>& nums, int target){
        int ans=-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid] == target){
                ans=mid;
                left=mid+1;
            } else if(nums[mid] > target){
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        
        
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = leftMost(0, n-1, nums, target);
        if(left == -1) return {-1, -1};
        int right = rightMost(left, n-1, nums, target);
        if(right == -1) return {left, left};
        return {left, right};
    }
};