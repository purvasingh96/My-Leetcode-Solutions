class Solution {
private:
    void mergeSort(int start, int end, vector<int>& nums, long long& ans, int diff){
        if(start>=end) return;
        int mid = start + (end-start)/2;
        
        mergeSort(start, mid, nums, ans, diff);
        mergeSort(mid+1, end, nums, ans, diff);
        
        
        int left=start, right=mid+1;
        
        while(left<=mid && right<=end){
            if(nums[right]+diff>= nums[left]){
              ans += end-right+1;
                left+=1;
            } else right+=1;
        
        }
        
        vector<int> temp;
        int i=start, j=mid+1;
        
        while(i<=mid && j<=end){
            if(nums[i] < nums[j]){
                temp.push_back(nums[i++]);
            } else{
                 temp.push_back(nums[j++]);
            }
        }
        
        
        while(i<=mid){
            temp.push_back(nums[i++]);
        }
        
        while(j<=end){
            temp.push_back(nums[j++]);
        }
        
        int k=0;
        for(int i=start;i<=end;i++){
            nums[i] = temp[k++];
        }
        
        
    }
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<int> res(n);
        for(int i=0;i<n;i++) res[i] = nums1[i] - nums2[i];
        
        
        long long c=0;
        
        mergeSort(0, n-1, res, c, diff);
        
        return c;
        
    }
};