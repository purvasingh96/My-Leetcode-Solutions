class Solution {
private:
    int dfs(int n, int num, vector<int>& dp){
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        
        int res=0;
        if(n!=num) res=n;
        
        for(int i=1;i<n;i++){
            int val = dfs(i, num, dp) * dfs(n-i, num, dp);
            res = max(res, val);
        }
        
        return dp[n] = res;
    }
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, -1);
        dp[1] = 1;
        return dfs(n, n, dp);
    }
};