class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz=strs.size();
        int dp[sz+1][m+1][n+1];
        memset(dp,0,sizeof(dp));
        int res=0;
        
        for(int i=1;i<=sz;i++){
            
             int cnt1=count(strs[i-1].begin(),strs[i-1].end(),'1');  //count no of 1's in each substring
            int cnt0=strs[i-1].size()-cnt1;
            
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    dp[i][j][k] = dp[i-1][j][k];
                    
                    if(j>=cnt0 && k>=cnt1) {
                        dp[i][j][k] = max(dp[i][j][k], 1+dp[i-1][j-cnt0][k-cnt1]);
                    
                    }
                    
                    res = max(res, dp[i][j][k]);
                    
                }
            }
            
        }
        
        return res;
    }
};