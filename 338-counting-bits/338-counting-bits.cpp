class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, -1);
        dp[0]=0;
        
        for(int i=0;pow(2, i)<=n;i++) {
            
            dp[pow(2, i)] = 1;
            
        }
        
        int x = 1;
        
        for(int i=1;i<=n;i++) {
            
            if(dp[i]==-1) {
                
                dp[i] = dp[x] + dp[i-x];
                
                
            } else {
                
                x = i;
                
            }
            
        }
        
        return dp;
        
    }
};