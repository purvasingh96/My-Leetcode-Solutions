class Solution {
private:
    void mergeSort(int start, int end, vector<pair<int, int>>& nums, vector<int>& indices, vector<pair<int, int>>& temp){
        if(start >= end)
            return;
        
        int mid = start + (end - start) / 2;
        
        mergeSort(start, mid, nums, indices, temp);
        mergeSort(mid + 1, end, nums, indices, temp);
        
        int left = start, right = mid + 1;
        int idx = start;
        int nRightLessThanLeft = 0;
        while(left <= mid and right <= end) {
            if(nums[left] < nums[right]) {
                indices[nums[left].second] += nRightLessThanLeft;
                temp[idx++] = nums[left++];
            } else if(nums[left] > nums[right]) {
                temp[idx++] = nums[right++];
                nRightLessThanLeft++;
            } else
                left++, right++;
        }
        
        while(left <= mid) {
            indices[nums[left].second] += nRightLessThanLeft;
            temp[idx++] = nums[left++];
        }
        
        while(right <= end)
            temp[idx++] = nums[right++];
        
        for(int i=start; i<=end; i++)
            nums[i] = temp[i];
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        
        vector<pair<int, int>> temp1;
        vector<pair<int, int>> temp2;
        int n = nums.size();
        
        for(int i=0;i<nums.size();i++){
            temp1.push_back({nums[i], i});
            temp2.push_back({nums[i], i});
        }
        
        vector<int> ans((int)nums.size(), 0);
        
        if(nums.size()==1) {
            return ans;
        }
        mergeSort(0, n-1, temp1, ans, temp2);
        return ans;
    }
};