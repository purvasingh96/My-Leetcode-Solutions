class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // count?
        int n = nums.size();
        int left = 0, right=n-1;
        
        
        while(left<right){
            int mid = left + (right-left)/2;
            int countLeft = 0;
            int countRight = 0;
            
            if(mid+1<n && nums[mid]==nums[mid+1]){
                countRight = right-mid+1;
                countLeft = mid - left;
                
                if(countLeft%2!=0) right=mid-1;
                else left= mid+2;
                
            } else if(mid-1>=0 && nums[mid] == nums[mid-1]){
                countLeft = mid-left+1;
                countRight = right-mid;
                
                if(countLeft%2!=0) right=mid-2;
                else left = mid+1;
                
            } else return nums[mid];
            
        }
        
        return nums[left];
    }
};