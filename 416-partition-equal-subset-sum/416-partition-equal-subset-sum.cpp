class Solution {
private:
    bool dfs(int idx, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(idx==nums.size() || target<0) return false;
        
        if(dp[idx][target]!=-1) {
            if(dp[idx][target] == 0) return false;
            return true;
        }
        
        int pick = dfs(idx+1, target-nums[idx], nums, dp);
        int dontpick = dfs(idx+1, target, nums, dp);
        
        return dp[idx][target] = (pick || dontpick);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2!=0) return false;
        sum = sum/2;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        
        return dfs(0, sum, nums, dp);
    }
};