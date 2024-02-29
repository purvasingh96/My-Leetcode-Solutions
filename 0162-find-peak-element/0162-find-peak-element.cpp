class Solution {
private:
    bool isPeak(vector<int>& nums, int idx){
        if(idx==0){
            if(nums[1]<nums[idx]){
                return true;    
            }
            return false;
        }
        
        if(idx == nums.size()-1){
            if(nums[nums.size()-2] < nums[idx]){
                return true;    
            }
            return false;
        } 
        if(nums[idx-1] < nums[idx] && nums[idx] > nums[idx+1]){
            return true;
        }
        
        return false;
    }
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        
        int low=0, high=nums.size()-1;
        
        
        while(low<high){
            int mid = low + (high-low)/2;
            
            if(isPeak(nums, mid)){
                return mid;
            }
            else if(nums[mid+1] > nums[mid]){
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
            
        return isPeak(nums, low) ? low : -1;
    }
};