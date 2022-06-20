class Solution {
private:
    int dfs(int e, int f, vector<vector<int>>& dp){
        
        if(f==0 || f==1){
            return f;
        }
        
        if(e==1){
            return f;
        }
        
        if(dp[e][f]!=-1){
            return dp[e][f];
        }
        
        int mn =INT_MAX;
        for(int i=1;i<=f;i++){
            int temp = 1+ max(dfs(e-1, i-1, dp),  dfs(e, f-i, dp));
            mn = min(mn, temp);
        }
        
        return dp[e][f] = mn;
    }
public:
    int twoEggDrop(int n) {
        if(n==1) return n;
        int eggs=2;
        vector<vector<int>> dp(eggs+1, vector<int>(n+1, -1));
        dfs(eggs, n, dp);
        
        return dp[eggs][n];
    }
};