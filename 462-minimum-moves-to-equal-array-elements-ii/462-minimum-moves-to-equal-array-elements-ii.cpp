class Solution {
private:
    void swap(int left, int right, vector<int>& nums){
        int t = nums[left];
        nums[left] = nums[right];
        nums[right]=t;
    }
    
    int partition(int left, int right, int pi, vector<int>& nums){
        int si = left;
        int pivot = nums[pi];
        
        swap(pi, right, nums);
        
        for(int i=left;i<=right;i++){
            
            if(nums[i] < pivot){
                swap(i, si, nums);
                si+=1;
            }
            
        }
        
        swap(si, right, nums);
        return si;
    }
    
    int quickselect(int left, int right, vector<int>& nums, int k){
        
        if(left == right) return nums[left];
        
        int pi = left + rand()%(right-left+1);
        
        pi = partition(left, right, pi, nums);
        
        if(pi==k){
            return nums[pi];
        } 
        
        else if(pi<k){
            return quickselect(pi+1, right, nums, k);
        } else{
            return quickselect(left, pi-1, nums, k);
        }
        
    }
    
public:
    int minMoves2(vector<int>& nums) {
        
        int x = quickselect(0, nums.size()-1,nums, nums.size()/2);
        int sum=0;
        
        for(auto num:nums){
            sum += abs(x-num);
        }
        return sum;
    }
};