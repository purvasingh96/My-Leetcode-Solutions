class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // O(N)
        int left =0, right=0;
        int n = nums.size();
        int sum=0, ans=INT_MAX;
        
        while(right<n){
            sum += nums[right];
            
            while(left<right && sum-nums[left]>=target){
                sum -= nums[left++];
            }
            
            if(sum>=target) ans = min(ans, (right-left+1));
            right+=1;
        }
        
        return ans==INT_MAX?0:ans;
    }
};