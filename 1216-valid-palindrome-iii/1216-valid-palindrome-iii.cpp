class Solution {
public:
    bool isValidPalindrome(string s, int k) {
      // len(s) - LCS between s and rev(s) should be <=k
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        string og = s;
        reverse(s.begin(), s.end());
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                
                if(i==0 || j==0) dp[i][j] = 0;
                
                else if(og[i-1] == s[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                } else{
                    
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    
                }
                
            }
        }
        
        int lcs = dp[n][n];
        cout<<lcs;
        
        return s.length()-lcs <= k;
    }
};