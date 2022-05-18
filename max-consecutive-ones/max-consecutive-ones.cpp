class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left=0, right=0, max_len=INT_MIN;
        
        while(left<nums.size()){
            
            while(left<nums.size() && nums[left]==0) {
                left+=1;
            }
            
            int right=left;
            
            while(right<nums.size() && nums[right] == 1) {
                right+=1;
            }
            
            int cur_len = right-left;
            max_len = max(max_len, cur_len);
            left=right;
            
        }
        
        return max_len;
        
    }
};