class Solution {
private:
    int dfs(int idx, int count, int k, vector<int>& nums, vector<vector<int>>& dp){
        if(idx >= nums.size() || count==0) return 0;
        if(dp[idx][count]!=-1) return dp[idx][count];
        
        int skip = dfs(idx+1, count, k, nums, dp);
        
        int dontSkip = -1;
        int it = upper_bound(nums.begin(), nums.end(), nums[idx]+k) - nums.begin();
        dontSkip = (it - idx) + dfs(it, count-1, k, nums, dp);
        
        return dp[idx][count] = max(skip, dontSkip);
    }
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        vector<vector<int>> dp(100001, vector<int>(3, -1));
        return dfs(0, 2, k, prizePositions, dp);
    }
};