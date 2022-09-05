class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        vector<bool> seen(32, false);
        
        int left=0, right=0, mask=0, res=-1;
        
        while(right<nums.size()){
            
            while(left<right && ((mask & nums[right])!=0)){
                mask^=nums[left];
                left+=1;
            }
            
            mask = (mask | nums[right]);
            
            res = max(res, right-left+1);
            right+=1;
            
        }
        
        return res;
    }
};