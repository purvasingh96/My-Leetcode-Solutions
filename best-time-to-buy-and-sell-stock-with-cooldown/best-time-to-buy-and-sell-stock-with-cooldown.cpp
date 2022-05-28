class Solution {
private:
    int dp(int i, int buy, vector<vector<int>>& memo, vector<int>& prices){
        if(i>=prices.size()) return 0;
        
        if(memo[i][buy]==-1){
            
            int doNothing = dp(i+1, buy, memo, prices);
            
            int doSomething;
            
            if(buy){
                // sell stock
                doSomething = -prices[i] + dp(i+1, false, memo, prices);
            } else{
                // buy stock
                doSomething = prices[i] + dp(i+2, true, memo, prices);
            }
            
            memo[i][buy] = max(doNothing, doSomething);
        }
        
        return memo[i][buy];
        
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> memo(n+2, vector<int>(2, -1));
        return dp(0, 1, memo, prices);
    }
};