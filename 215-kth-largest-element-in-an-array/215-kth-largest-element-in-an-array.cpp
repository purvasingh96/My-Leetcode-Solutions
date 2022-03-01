class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size()-k;
        
        int left = 0, right=nums.size()-1;
        
        while(true) {
            
            int pidx = partition(nums, left, right);
            
            if(k == pidx) return nums[k];
            
            else if(k < pidx) {
                right = pidx-1;
            }
             else left = pidx+1;
            
        }
        
    }
    
    int partition(vector<int>& nums, int left, int right) {
        
        int pidx = left + (rand()%(right - left + 1));
        int pivot = nums[pidx];
        
        swap(nums[pidx], nums[right]);
        
        int l = left;
        
        for(int i=left;i<=right;i++) {
            
            if(nums[i] < pivot) {
                swap(nums[l], nums[i]);
                l+=1;
            }
            
        }
        
        swap(nums[l], nums[right]);
        return l;
        
    }
    
    
};