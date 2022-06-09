class Solution {
private:
    
    int dp(int i, bool buy, int fee, vector<int>& prices, vector<vector<int>>& memo){
        if(i==prices.size()) return 0;
        
        if(memo[i][buy] == -1){
            int doNothing = dp(i+1, buy, fee, prices, memo);
            int doSomething;
            
            if(buy){
                // sell stock
                doSomething = prices[i] -fee + dp(i+1, false, fee, prices, memo);
                
            } else{
                // buy stock
                doSomething = -prices[i] + dp(i+1, true, fee, prices, memo);
            }
            
            memo[i][buy] = max(doNothing, doSomething);
        }
        return memo[i][buy];
    }
public:
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int>(2, -1));
        return dp(0, false, fee, prices, memo);
    }
};