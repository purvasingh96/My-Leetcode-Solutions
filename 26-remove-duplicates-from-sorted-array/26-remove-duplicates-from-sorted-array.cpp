class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int last_swap_pos = 0;
        int last_unique_num = nums[0];
        
        int left=0, right=0;
        
        while(left<nums.size()){
            
            while(right<nums.size() && nums[right] == nums[left]) {
                right+=1;
            }
            
            if(right<nums.size()) {
                last_unique_num = nums[right];
                nums[last_swap_pos + 1] = last_unique_num;
                last_swap_pos += 1;
            }
            
            left=right;
            
        }
        
        return last_swap_pos+1;
        
    }
};