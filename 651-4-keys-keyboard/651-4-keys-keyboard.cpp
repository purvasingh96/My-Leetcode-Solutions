class Solution {
public:
    int maxA(int n) {
        if(n<=6) return n;
        vector<int> dp(n+1);
        
        for(int i=0;i<=6;i++){
            dp[i]=i;
        }
        cout<<"hger";
        for(int i=7;i<=n;i++){
            dp[i] = dp[i-1]+1;
            
            for(int j=3;j<=i;j++){
                
                dp[i] = max(dp[i], dp[j-3]*(i-j+2));
                
            }
        }
        
        return dp[n];
    }
};