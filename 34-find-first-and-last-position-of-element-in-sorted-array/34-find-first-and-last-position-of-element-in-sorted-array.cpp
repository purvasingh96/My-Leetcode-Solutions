class Solution {
private:
    int binary(vector<int>& nums, int target, bool isFirst){
        int n = nums.size();
        int left=0,right=n-1;
        
        while(left<=right){
            int mid = left + (right-left)/2;
            
            if(nums[mid] == target){
                
                if(isFirst){
                    
                    if(mid==left || nums[mid-1]!=target){
                        return mid;
                    }
                    
                    right=mid-1;
                    
                } else {
                    
                    
                    if(mid==right || nums[mid+1]!=target){
                        return mid;
                    }
                    
                    left=mid+1;
                    
                }
                
            } else if(nums[mid] < target) {
                left = mid+1;
            } else {
                right=mid-1;
            }            
        }
        
        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i = binary(nums, target, true);
        
        if(i==-1) return {-1, -1};
        
        int j = binary(nums, target, false);
        
        return {i,j};
    }
    
    
};