class Solution {
public:
    int countOrders(int n) {
        if(n==1) return 1;
        vector<long> dp(n+1, 0);
        dp[0]=0;
        dp[1]=1;
        dp[2]=6;
        
        for(int i=3;i<=n;i++) {
            
            int x = 2*i-1;
            int sum=0;
            
            for(int j=1;j<=x;j++) {
                sum+=j;
            }
            
            long y = dp[i-1]%(1000000007);
            
            dp[i] = ((sum%1000000007)*y)%(1000000007);
            
        }
        
        
        return dp[n]%(1000000007);
    }
};