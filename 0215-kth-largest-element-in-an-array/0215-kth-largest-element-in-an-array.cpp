class Solution {
private:
    int partition(vector<int>& nums, int start, int end){
        int pivot = nums[end];
        int i = start-1;
        for(int j=start;j<end;j++){
            if(nums[j] > pivot){
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[++i], nums[end]);
        return i;
    }
    
    void quickSort(vector<int>& nums, int start, int end, int k){
       
        if(start<=end){
            int pivot = partition(nums, start, end);
            
            if(k<=pivot){
                quickSort(nums, start, pivot-1, k);
            } else if(k > pivot){
                quickSort(nums, pivot+1, end, k);
            }
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        // quick select
        quickSort(nums, 0, nums.size()-1, k);
        
        return nums[k-1];
    }
};