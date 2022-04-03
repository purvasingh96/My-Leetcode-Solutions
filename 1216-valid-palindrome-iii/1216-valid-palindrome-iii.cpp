class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        
        int n = s.length();
        string original = s;
        reverse(s.begin(), s.end());
        int x = longestPalindromicSubsequence(original, s);
        
        return (n-x<=k);
        
    }
    
    int longestPalindromicSubsequence(string s, string r) {
        int n = s.length();
        
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        
        for(int i=0;i<=n;i++) {
            
            for(int j=0;j<=n;j++) {
                
                if(i==0 || j==0) dp[i][j] = 0;
                else if(s[i-1] == r[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                
            }
            
        }
        
        return dp[n][n];
        
    }
};