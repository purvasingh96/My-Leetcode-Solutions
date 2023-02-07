class Solution {
private:
    long long dfs(int n, int currSum, int k, int target, vector<vector<int>>& dp){
        int mod = 1e9+7;
        if(n==0 && currSum == target) return 1;
        if(n==0 || currSum > target) return 0;
        
        if(dp[n][currSum]!=-1) return dp[n][currSum];
        
        long long count=0;
        for(int i=1;i<=k;i++){
            count += dfs(n-1, currSum+i, k, target, dp);
            count = count%mod;
        }
        
        return dp[n][currSum] = count;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return (int)dfs(n, 0, k, target, dp);
    }
};