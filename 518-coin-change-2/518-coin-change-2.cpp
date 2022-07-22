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
        int m = coins.size();
        vector<vector<int>> dp(m+1, vector<int>(amount+1, 0));
        
        for(int i=0;i<=m;i++){
            dp[i][0] = 1;
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=amount;j++){
                
                if(coins[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                } else{
                    
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                    
                }
                
            }
        }
        return dp[m][amount];
    }
};