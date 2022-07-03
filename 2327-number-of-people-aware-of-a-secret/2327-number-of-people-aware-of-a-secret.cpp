class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(1001, 0);
        dp[1] = 1;
        int mod = 1000000007;
        
        for(int i=1;i<=n;i++){
            
            int c = dp[i];
          
           if(dp[i]!=0){
               for(int k = i+delay;k<(i+forget) && k<=n;k++){
                    //cout<<"i: "<<i<<"k: "<<k<<"\n";
                    dp[k] +=c;
                    dp[k] = dp[k]%mod;
                }
               
           }
                    

                
            
        }
        
        int ans=0;
        for(int i=n;i>n-forget;i--) {
            //cout<<dp[i]<<" ";
            ans+= dp[i];
            ans = ans%mod;
        }
        
        return ans%mod;
    }
};