class Solution {
public:
    int minDistance(string word1, string word2) {
        // return length of LCS
        int m = word1.length(), n = word2.length();
        
        vector<int> dp(n+1, 0);
        int prev=0;
        for(int i=1;i<=m;i++){
            vector<int> temp(n+1, 0);
            for(int j=1;j<=n;j++){
                if(word1[i-1] == word2[j-1]){
                    temp[j] = 1+dp[j-1];
                } else{
                    temp[j] = max(dp[j], temp[j-1]);
                }
            }
            dp = temp;
        }
        
        return (m+n) - 2*dp.back();
    }
};