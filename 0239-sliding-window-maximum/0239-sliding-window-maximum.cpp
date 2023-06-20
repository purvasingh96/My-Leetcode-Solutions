class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        
        left[0] = nums[0];
        right[n-1] = nums[n-1];
        
        
        for(int i=1;i<n;i++){
            if(i%k==0) left[i] = nums[i];
            else left[i] = max(left[i-1], nums[i]);
            
            int idx = n-i-1;
            if((idx+1)%k==0) right[idx] = nums[idx];
            else right[idx] = max(right[idx+1], nums[idx]);
        }
        
        vector<int> res;
        
        for(int i=0;i<=n-k;i++){
            int ans = max(left[i+k-1], right[i]);
            res.push_back(ans);
        }
        
        return res;
    }
};