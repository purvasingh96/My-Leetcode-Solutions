class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(total_sum < x) return -1;
        
        if(total_sum == x) return nums.size();
        
        int target = total_sum - x;
        
        int cs=0, start=0, max_size=0;
        
        for(int i=0;i<nums.size();i++){
            
            cs += nums[i];
            
            while(cs > target){
                cs -= nums[start++];
            }
            
            if(cs == target){
                max_size = max(max_size, i-start+1);
            }
            
        }
        
        return max_size==0?-1:nums.size()-max_size;
        
    }
};