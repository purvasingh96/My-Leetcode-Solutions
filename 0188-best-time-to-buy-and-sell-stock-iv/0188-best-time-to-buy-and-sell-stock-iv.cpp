class Solution {
private:
    //int dp[10002][2][2];
    int dfs(int idx, int buy, int k, vector<vector<vector<int>>>& dp, vector<int>& prices){
        if(idx >= prices.size() || k<0) return 0;
        if(dp[idx][buy][k]!=-1) return dp[idx][buy][k];
        
        int skip = dfs(idx+1, buy, k, dp, prices);
        
        int dont_skip;
        
        if(buy == 0){
            // buy
            dont_skip = dfs(idx+1, 1, k, dp, prices) - prices[idx];
        } else{
            // sell
            dont_skip = dfs(idx+1, 0, k-1, dp, prices) + prices[idx];
        }
        
        return dp[idx][buy][k] = max(skip, dont_skip);
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(10002, vector<vector<int>>(2, vector<int>(k, -1)));
        //memset(dp, -1, sizeof(dp));
        
        return dfs(0, 0, k-1, dp, prices);
    }
};