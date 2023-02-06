class Solution {
    long long dfs(int n, vector<int>& dp){
        int mod= 1e9+7;
        if(n%2==1) return 0;
        if(n==0) return 1;
        
        if(dp[n]!=-1) return dp[n];
        
        long long s=0;
        for(int i=0;i<n;i+=2){
            s += (dfs(i, dp) * dfs(n-2-i, dp));
            s = s%mod;
        }
        
        return dp[n] = s%mod;
            
    }
public:
    int numberOfWays(int n) {
        int mod= 1e9+7;
        vector<int> dp(n+1, -1);
        return dfs(n, dp)%mod;
    }
};