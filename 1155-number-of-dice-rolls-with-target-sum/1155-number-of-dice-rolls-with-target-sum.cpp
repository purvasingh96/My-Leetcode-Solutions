class Solution {
private:
    // dp[num blanks][target sum] = how many ways
    int mod=1e9+7;
    long long dfs(int n, int k, int target, vector<vector<long long>>& dp){
        if(target<0) return 0;
        if(target==0 && n==0) return 1;
        
        if(n==0) return 0;
        
        if(dp[n][target]!=-1) return dp[n][target];
        
        long long c=0;
        for(int i=1;i<=k;i++){
            c+= dfs(n-1, k, target-i, dp);
            c=c%mod;
        }
        
        return dp[n][target] = c;
        
    }
        
        
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>> dp(n+1, vector<long long>(target+1, -1));
        return dfs(n, k, target, dp)%mod;
    }
};