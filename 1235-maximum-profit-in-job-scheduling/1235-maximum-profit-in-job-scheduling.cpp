class Solution {
private:
    int binary_search(int idx, vector<vector<int>>& nums){
        int n = nums.size();
        int left = 0, right=n-1;
        int target = nums[idx][1], ans=n;
        
        while(left<=right){
            int mid = left + (right-left)/2;
            
            if(nums[mid][0] >= target){
                ans=mid;
                right=mid-1;
            } else {
                left = mid+1;
            }
        }
        
        return ans;
    }
    
    int dfs(int idx, vector<vector<int>>& nums, vector<int>& dp){
        if(idx >= nums.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        
        int next = binary_search(idx, nums);
        
        int skip = dfs(idx+1, nums, dp);
        int dontSkip = nums[idx][2] + dfs(next, nums, dp);
        
        return dp[idx] = max(skip, dontSkip);
        
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> nums;
        for(int i=0;i<n;i++){
            nums.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(nums.begin(), nums.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] == b[0]) return a[2] > b[2];
            return a[0] < b[0];
        });
        
        vector<int> dp(n, -1);
        return dfs(0, nums, dp);
    }
};