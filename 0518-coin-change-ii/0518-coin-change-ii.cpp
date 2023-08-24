class Solution {
private:
    int dfs(int i, int amt, vector<int>& coins, vector<vector<int>>& dp){
        if(amt == 0) return 1;
        if(i >= coins.size()) return 0;
        
        if(dp[i][amt]!=-1) return dp[i][amt];
        
        // skip,
        if(coins[i] > amt){
            return dp[i][amt] = dfs(i+1, amt, coins, dp);
        }
        
        int skip = dfs(i+1, amt, coins, dp);
        int dontSkip = dfs(i, amt-coins[i], coins, dp);
        
        return dp[i][amt] = skip + dontSkip;
        
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return dfs(0, amount, coins, dp);
    }
};