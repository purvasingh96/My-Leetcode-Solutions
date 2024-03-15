class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int l=0, r=nums.size()-1;
        
        while(l<=r){
            // mid represents number of missing elements
            int mid = l + (r-l)/2;
            // missing elements
            int missing = nums[mid] - nums[0] - mid;
            if(missing < k){
                l=mid+1;
            } else {
                r=mid-1;
            }
        }
        
        return nums[0] + l + k-1;
        
    }
};