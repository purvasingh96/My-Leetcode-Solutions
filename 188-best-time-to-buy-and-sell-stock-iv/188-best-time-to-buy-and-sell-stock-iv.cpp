class Solution {
private:
    int memo[1001][101][2] = {};
    int dp(int i, int k, int holding, vector<int> prices){
        if(i==prices.size() || k==0) return 0;
        
        if(memo[i][k][holding]==0){
            
            int doNothing = dp(i+1, k, holding, prices);
            int doSomething;
            
            if(holding){
                // sell stock
                doSomething = prices[i] + dp(i+1, k-1, 0, prices);
            } else{
                // buy stock
                doSomething = -prices[i] + dp(i+1, k, 1, prices);
            }
            
            memo[i][k][holding] = max(doNothing, doSomething);
            
        }
        
        return memo[i][k][holding];
        
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        return dp(0, k, 0, prices);
        
        
    }
};