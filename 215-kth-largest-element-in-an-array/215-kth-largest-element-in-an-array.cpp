class Solution {
private:
    void swap(int i, int j, vector<int>& nums){
        int t = nums[i];
        nums[i]=nums[j];
        nums[j]=t;
    }
    
    int partition(int left, int right, int pivot_idx, vector<int>& nums){
        
        int pivot = nums[pivot_idx];
        int store_idx=left;
        
        swap(pivot_idx, right, nums);
        
        for(int i=left;i<=right;i++){
            
            if(nums[i] < pivot){
                
                swap(store_idx, i, nums);
                store_idx+=1;
                
            }
            
        }
        
        swap(store_idx, right, nums);
        
        return store_idx;
        
    }
    
    int quickselect(int left, int right, int k_smallest, vector<int>& nums){
        
        if(left==right) return nums[left];
        
        int pivot_idx = left + rand()%(right-left+1);
        
        pivot_idx = partition(left, right, pivot_idx, nums);
        
        if(pivot_idx == k_smallest){
            return nums[pivot_idx];
        }
        
        else if(pivot_idx < k_smallest){
            return quickselect(pivot_idx+1, right, k_smallest, nums);
        }
        
        else return quickselect(left, pivot_idx-1, k_smallest, nums);
        
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size()-k;
        return quickselect(0, nums.size()-1, k, nums);
        
    }
};