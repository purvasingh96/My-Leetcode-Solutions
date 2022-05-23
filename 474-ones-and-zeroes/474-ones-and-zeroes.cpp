class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // subset + upper limit => knapsack
        int l=strs.size();
        int dp[l+1][m+1][n+1];
        
        memset(dp, 0, sizeof(dp));
        
        int res=0;
        
        for(int i=1;i<=l;i++){
            
            int cz=0, co=0;
            
            for(auto x:strs[i-1]){
                if(x=='0') cz+=1;
                else co+=1;
            }
            
            
            
            for(int j=0;j<=m;j++){
                
                for(int k=0;k<=n;k++){
                    dp[i][j][k] = dp[i-1][j][k];
                    if(j>=cz && k>=co){
                        int y = 1+dp[i-1][j-cz][k-co];
                        dp[i][j][k] = max(dp[i][j][k], y);
                        
                    }
                    
                    res = max(res, dp[i][j][k]);
                        
                        
                }
                
            }
            
        }
        
        return res;
    }
};