class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int ans=0;
        
        for(int i=0;i<n;i++){
            dp[i][i] = true;            
        }
        
        for(int i=0;i<n-1;i++){
            dp[i][i+1] = s[i] == s[i+1];
            ans += dp[i][i+1];
        }
        
        for(int len=3;len<=n;len++){
            for(int i=0, j=i+len-1;j<n;i++, j++){
                dp[i][j] = dp[i+1][j-1] && s[i]==s[j];
                ans += dp[i][j];
            }
        }
        
        return ans+n;
    }
    
};