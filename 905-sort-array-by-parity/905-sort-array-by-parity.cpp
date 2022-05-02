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
                    int t = nums[left];
                    nums[left] = nums[right];
                    nums[right] = t;
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
                    int t = nums[left];
                    nums[left] = nums[right];
                    nums[right] = t;
                }
            }
            
            left += 1;
            right -= 1;
            
        }
        
        return nums;
    }
};