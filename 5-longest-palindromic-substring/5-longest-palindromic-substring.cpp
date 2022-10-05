class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        
        string c(1, s[0]);
        string ans = c;
        
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i] == s[j]){
                    if(j-i==1 || dp[i+1][j-1]){
                        
                        dp[i][j] = true;
                        if(ans.length() < j-i+1){
                            ans=s.substr(i, j-i+1);
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};