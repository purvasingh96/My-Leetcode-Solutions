class Solution {
private:
    int dp[1001][101][2] = {};
    // state: 0: buy 1: sell
    int dfs(int idx, int k, int state, vector<int>& prices){
        if(idx==prices.size() || k==0) return 0;
        
        if(dp[idx][k][state]!=0) return dp[idx][k][state];
        
        int pick, dontpick;
        
        dontpick = dfs(idx+1, k, state, prices);
        
        
        if(state == 0){
            // buy
            pick = -prices[idx] + dfs(idx+1, k, 1, prices);
        } else {
            // sell
            pick = prices[idx] + dfs(idx+1, k-1, 0, prices);
        }
        
        return dp[idx][k][state] = max(pick, dontpick);
        
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        return dfs(0, k, 0, prices);
    }
};