class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left=0, right=0;
        int prod=1, ans=0;
        
        for(int right=0;right<nums.size();right++){
            prod = prod*nums[right];
              
            
            while(left<=right && prod>=k){
                prod = prod/nums[left++];
            }
            ans += (right-left+1);
        }
        return ans;
    }
};