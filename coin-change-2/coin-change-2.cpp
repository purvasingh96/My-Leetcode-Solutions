class Solution {

    
public:
    int change(int amount, vector<int>& coins) {
        if(amount==0) return 1;
        int m = coins.size(), n=amount+1;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int j=0;j<n;j++){
            if(j%coins[0]==0){
                dp[0][j]+=1;
            }
        }
        
        for(int i=0;i<m;i++){
            dp[i][0]=0;
        }
        
        
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                
                if(j<coins[i]){
                    dp[i][j] = dp[i-1][j];
                } else if(j==coins[i]){
                    dp[i][j] = 1+dp[i-1][j];
                } else if(j>coins[i]){
                    dp[i][j] = dp[i-1][j]+dp[i][j-coins[i]];
                }
                
            }
            
            
        }
        
        return dp[m-1][amount];
    }
};