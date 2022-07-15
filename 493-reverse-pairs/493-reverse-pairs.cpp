class Solution {
private:
    void merge_sort(int start, int end, vector<int>& nums, vector<int>& temp, int& res){
        
        if(start>=end) return;
        
        int mid = start + (end-start)/2;
        
        merge_sort(start, mid, nums, temp, res);
        merge_sort(mid+1, end, nums, temp, res);
        
        int i=start, j=mid+1, p=mid+1, idx=start;
        
        while(i<=mid){
            
            while(p<=end && nums[i]> 2L*nums[p]) p++;
            res += (p - (mid+1));
            
            while(j<=end && nums[i] > nums[j]) temp[idx++] = nums[j++];
            temp[idx++] = nums[i++];
            
        }
        
        while(j<=end) temp[idx++] = nums[j++];
        
        for(int k=start;k<=end;k++){
            nums[k] = temp[k];
        }
        
    }
public:
    int reversePairs(vector<int>& nums) {
        int ans=0, n = nums.size();
        vector<int> temp(n);
        
        merge_sort(0, n-1, nums, temp, ans);
        
        return ans;
    }
};