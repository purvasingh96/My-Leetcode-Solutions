class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        
        while(left < right) {
            
            if(nums[left]%2 > nums[right]%2) {
                swap(nums[left], nums[right]);
            }
            
            if(nums[left]%2==0) left+=1;
            if(nums[right]%2!=0) right-=1;
            
           
            
        }
        
        return nums;
    }
};