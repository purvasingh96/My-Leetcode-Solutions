class Solution {
private:
    int quickSelect(vector<int>& nums, int k){
        int pivot = nums[rand()%nums.size()];
        vector<int> left;
        vector<int> right;
        vector<int> mid;
        
        for(int num:nums){
            if(num < pivot){
                right.push_back(num);
            } else if(num > pivot){
                left.push_back(num);
            } else {
                mid.push_back(num);
            }
        }
        
        if(left.size() >= k){
            // ans is in left subarray
            return quickSelect(left, k);
        } 
        
        if(left.size() + mid.size() < k){
            return quickSelect(right, k - left.size() - mid.size());
        }
        
        return pivot;
        
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, k);
    }
};