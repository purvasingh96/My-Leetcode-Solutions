class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        string og = s;
        reverse(s.begin(), s.end());
        string rev = s;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(og[i-1] == rev[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        int ans = dp[n][n];
        return n - ans <= k;
    }
};