class Solution {
public:
    int findDerangement(int n) {
        int mod = 1e9+7;
        vector<long> dp(n+1, 0);
        dp[0]=0;
        dp[1]=0;
        
        if(n<=1) return dp[n];
        dp[2]=1;
        
        for(int i=3;i<=n;i++){
            dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % mod;
        }
        
        return (int)dp[n];
    }
};