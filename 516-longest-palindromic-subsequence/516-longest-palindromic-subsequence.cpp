class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        int maxlen =1;
        
        string og = s;
        reverse(s.begin(), s.end());
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(og[i-1] == s[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                } else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                
                maxlen = max(maxlen, dp[i][j]);
            }
        }
        
        return dp[n][n];
        
        
    }
};