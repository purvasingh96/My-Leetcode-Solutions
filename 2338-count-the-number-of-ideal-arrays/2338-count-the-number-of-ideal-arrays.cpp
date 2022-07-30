class Solution {
private:
    int mod = 1e9+7;
 int Comb(int n, int k, vector<vector<int>>& memo)
    {
        if(k == 0) return 1;
        if(n == 0) return 0;
        
        if(memo[n][k] != 0)
            return memo[n][k];
        
        memo[n][k] = Comb(n-1, k, memo)+Comb(n-1, k-1, memo);
        memo[n][k] %= mod;
        return memo[n][k];
    }
    
    map<int, vector<int>> helper(int maxValue){
        map<int, vector<int>> m;
        
        for(int i=1;i<=maxValue;i++){
            int j=i*2;
            
            while(j<=maxValue){
                m[j].push_back(i);
                j+=i;
            }
        }
        return m;
    }
public:
    int idealArrays(int n, int maxValue) {
        vector<vector<int>> dp(15, vector<int>(maxValue+1));
        dp[1][0] = 0;
        long long res=0;
        
        auto m = helper(maxValue);
        
        for(int j=1;j<=maxValue;j++){
            dp[1][j]=1;
        }
        
        for(int i=2;i<=n && i<15;i++){
            for(int j=1;j<=maxValue;j++){
                for(auto k:m[j]) {
                    dp[i][j] += dp[i-1][k];
                    dp[i][j] %= mod;
                }
            }
        }
        
        for(int i=1;i<=n && i<15;i++){
            for(int j=1;j<=maxValue;j++){
                dp[i][0] += dp[i][j];
                dp[i][0] %= mod;
            }
        }
        
        vector<vector<int>> memo(n+1, vector<int>(15));
        
        for(int i=1;i<=n && i<15;i++){
            res += (long)Comb(n-1, i-1, memo)*dp[i][0]%mod;
            res = res%mod;
        }
        
        return (int)res;
        
        
    }
};