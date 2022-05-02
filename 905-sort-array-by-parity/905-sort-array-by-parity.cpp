class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        
        while(left < right) {
            
            if(nums[left]%2==0 && nums[right]%2==0) {
                while(left<right && nums[left]%2==0) {
                    left+=1;
                }
                if(left<right) {
                    swap(nums[left], nums[right]);
                }
            }
            
            else if(nums[left]%2 != 0 && nums[right]%2==0) {
                swap(nums[left], nums[right]);
            }
            
            else if(nums[left]%2!=0 && nums[right]%2!=0) {
                
                while(right>left && nums[right]%2!=0) {
                    right-=1;
                }
                
                if(right > left) {
                    swap(nums[right], nums[left]);
                }
            }
            
            left += 1;
            right -= 1;
            
        }
        
        return nums;
    }
};