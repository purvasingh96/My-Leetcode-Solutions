class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left=0, right=n-1;
        
        while(left<right){
            
            int mid = left + (right-left)/2;
            
            if(mid>0){
                //cout<<"mid greater than 0 :"<<mid<<"\n";
                
                if(nums[mid-1] == nums[mid]){
                    if((mid-1)%2==0) left=mid+1;
                    else right=mid-1;
                } else if(mid+1<n && nums[mid] == nums[mid+1]){
                    if(mid%2==0) left=mid+1;
                    else right=mid-1;
                } else return nums[mid];
                
                
            } else {
                if(mid+1 < n && nums[mid] == nums[mid+1]){
                    left=mid+1;
                } else return nums[mid];
            }
            
        }
        
        return nums[left];
        
    }
};