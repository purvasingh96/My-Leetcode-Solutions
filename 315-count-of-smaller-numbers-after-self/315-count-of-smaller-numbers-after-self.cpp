class Solution {
private:
    void mergesort(int start, int end, vector<vector<int>>& nums, vector<int>& indices,
                  vector<vector<int>>& temp){
        
        if(start>=end) return;
        
        int mid = start + (end - start) / 2;
        
        mergesort(start, mid, nums, indices, temp);
        mergesort(mid + 1, end, nums, indices, temp);
        
        
        int left=start, right=mid+1, nsmall=0, idx=start;
        
        while(left<=mid && right<=end){
            
            if(nums[left][0] <= nums[right][0]){
                indices[nums[left][1]] += nsmall;
                temp[idx++] = nums[left++];
                
            }  else if(nums[left][0] > nums[right][0]){
                temp[idx++] = nums[right++];
                nsmall++;
            }
            
        }
        
        while(left<=mid){
            
            indices[nums[left][1]] += nsmall;
            temp[idx++] = nums[left++];
        }
    
        
        while(right<=end){
            
            temp[idx++] = nums[right++];
        }
        
        for(int k=start;k<=end;k++){
            nums[k] = temp[k];
        }
        
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<vector<int>> temp1;
        vector<vector<int>> temp2;
        int n = nums.size();
        vector<int> ans(n, 0);
        
        for(int i=0;i<n;i++){
            temp1.push_back({nums[i], i});
            temp2.push_back({nums[i], i});
        }
        
        mergesort(0, n-1, temp1, ans, temp2);
        
        return ans;
        
    }
};