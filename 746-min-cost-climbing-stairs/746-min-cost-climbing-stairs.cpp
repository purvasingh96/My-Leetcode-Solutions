class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1);
        
        dp[0]=0;
        dp[1]=0;
        
        for(int i=2;i<=n;i++) {
            dp[i] = min((cost[i-2]+dp[i-2]), (cost[i-1]+dp[i-1]));
        }
        
        return dp[n];
        
    }
};