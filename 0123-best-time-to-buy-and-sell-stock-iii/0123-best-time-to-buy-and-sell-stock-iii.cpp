class Solution {
private:
    int dp[100002][2][2]
;    int dfs(int idx, int k, int buy, int& ans, vector<int>& prices){
        if(idx >= prices.size() || k<0) return 0;
        
        if(dp[idx][buy][k]!=-1) return dp[idx][buy][k];
        
        int skip= dfs(idx+1, k, buy,ans, prices);
        int dont_skip;
        // buy if prev was sell
        if(buy == 0){
            dont_skip = dfs(idx+1, k, 1, ans,  prices) - prices[idx];
        } else{
            // sell if prev was buy
            dont_skip = dfs(idx+1, k-1, 0, ans, prices) + prices[idx];
        }
        
        return dp[idx][buy][k] = max(skip, dont_skip);
        
    }
public:
    int maxProfit(vector<int>& prices) {
        int ans=0, n = prices.size();
        memset(dp, -1, sizeof(dp));
        return dfs(0, 1, 0, ans, prices);
    }
};