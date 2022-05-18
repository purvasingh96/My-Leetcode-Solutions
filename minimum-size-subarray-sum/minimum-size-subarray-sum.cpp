class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0, right=0, min_len=INT_MAX;
        
        while(left<nums.size()){
            right = left;
            int temp_sum=0;
            
            while(right<nums.size() && temp_sum<target) {
                temp_sum += nums[right];
                right+=1;
            }
            
            if(temp_sum >= target) {
                int cur_len = right-left;
                min_len = min(min_len, cur_len);
            } 
                left+=1;
            
            
        }
        
        return min_len==INT_MAX?0:min_len;
    }
};