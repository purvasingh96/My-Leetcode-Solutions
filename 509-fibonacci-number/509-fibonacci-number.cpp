class Solution {
private:
    int dfs(int n, vector<int>& dp){
        if(n<2) return n;
        
        if(dp[n]!=-1) return dp[n];
            
        return dp[n] = dfs(n-1, dp) + dfs(n-2, dp);
    }
public:
    int fib(int n) {
        vector<int> dp(n+1, -1);
        return dfs(n, dp);
    }
};