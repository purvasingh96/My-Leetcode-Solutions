class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        if(n<=2) return n;
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        
        
        for(int i=3;i<=n;i++){
            int ans=0;
            for(int j=1;j<=i;j++){
                int left = j-1;
                int right = i-j;
                ans += dp[left]*dp[right];
            }
            dp[i] = ans;
        }
        
        return dp[n];
        
    }
};