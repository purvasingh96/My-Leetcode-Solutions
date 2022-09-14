class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int left=0, right=1;
        int maxlen = 0, n = nums.size();
        
        while(right<n){
            while(right<n && nums[right]> nums[right-1]){
                right+=1;
            }
            
            maxlen = max(maxlen, right-left);
            left=right;
            right+=1;
        }
        return maxlen;
        
    }
};