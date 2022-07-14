class Solution {
private:
    void checkCount(vector<int>& nums, int left, int mid, int right, int& count){
        
        int i=left, j=mid+1;
        
        while(i<=mid && j<=right){
            if((long)nums[i] > (long) 2*nums[j]){
                count += (mid-i)+1;
                j+=1;
            } else {
                i+=1;
            }
        }
        
        sort(nums.begin()+left, nums.begin()+right+1);
        
    }
    void mergeSort(vector<int>& nums, int left, int right, int& count){
        
        if(left>=right) return;
        
        int mid = left + (right-left)/2;
        
        mergeSort(nums, left, mid, count);
        mergeSort(nums, mid+1, right, count);
        
        checkCount(nums, left, mid, right, count);
        
        
    }
public:
    int reversePairs(vector<int>& nums) {
        int count=0;
        mergeSort(nums, 0, nums.size()-1, count);
        return count;
    }
};