class Solution {
private:
    int dfs(int idx, int target, vector<int>& coins, vector<vector<int>>& dp){
        
        if(idx>=coins.size() || target<0) return 0;
        if(target == 0) return 1;
        if(dp[idx][target]!=-1) return dp[idx][target];
        
        int ans = dfs(idx, target-coins[idx], coins, dp) + 
                  dfs(idx+1, target, coins, dp);
        
        return dp[idx][target] = ans;
    }
public:
    int change(int amount, vector<int>& coins) {
        int ans=0;
        int m = coins.size();
        vector<vector<int>> dp(m, vector<int>(amount+1, -1));
        
        return dfs(0, amount, coins, dp);
        
    }
};