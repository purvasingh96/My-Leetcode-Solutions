class Solution {
private:
    #define MOD ((long)1e9 + 7)
    int dfs(int n, vector<int>& dp){
        
        if(n==0) return 1;
        
        if(dp[n]!=-1) return dp[n];
        
        long hs=0;
        for(int i=0;i<n;i+=2){
            
            hs += (dfs(i, dp)%MOD * dfs(n-2-i, dp)%MOD)%MOD;
        }
        
        return dp[n] = hs%MOD;
        
    }
public:
    int numberOfWays(int numPeople) {
        vector<int> dp(numPeople+1, -1);
        return dfs(numPeople, dp);
    }
};