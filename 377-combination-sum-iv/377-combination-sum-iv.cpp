class Solution {
private:
    int dfs(int idx, int target, vector<int>& nums, vector<vector<int>>& dp){
        
        if(target<0 || idx>=nums.size()) return 0;
        
        if(target==0) return 1;
        
        if(dp[idx][target]!=-1) return dp[idx][target];
        
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans += dfs(i, target-nums[i], nums, dp);
        }
        return dp[idx][target]=ans;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        
        return dfs(0, target, nums, dp);
    }
};