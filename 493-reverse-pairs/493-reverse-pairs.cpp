class Solution {
private:
    void merge(int left, int right, vector<int>& nums, int& ans){
        if(left>=right) return;
        
        int mid = left + (right-left)/2;
        
        merge(left, mid, nums, ans);
        merge(mid+1, right, nums, ans);
        
        int i=left, j=mid+1;
        
        while(i<=mid && j<=right){
            if(nums[i] > 2L*nums[j]){
                ans += right-j+1;
                i+=1;
            } else {
                j+=1;
            }
        }
        
        vector<int> temp;
        int i1=left, j1=mid+1;
        
        while(i1<=mid && j1<=right){
            if(nums[i1] > nums[j1]){
                temp.push_back(nums[i1]);
                i1+=1;
            } else {
                temp.push_back(nums[j1]);
                j1+=1;
            }
        }
        
        while(i1<=mid){
            temp.push_back(nums[i1]);
            i1+=1;
        }
        
        while(j1<=right){
            temp.push_back(nums[j1]);
            j1+=1;
        }
        
        int k=0;
        for(int i=left;i<=right;i++){
            nums[i]= temp[k++];
        }
        
    }
public:
    int reversePairs(vector<int>& nums) {
        int ans=0, n = nums.size();
        merge(0, n-1, nums, ans);
        return ans;
        
    }
};