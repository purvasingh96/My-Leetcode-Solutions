class Solution {
private:
    int mod=1e9+7;
    long long dfs(int start, int end, int k, vector<vector<long long>>& dp){
        if(start==end){
            if(k==0) return 1;
        }
        
        if(k==0) return 0;
        if(dp[start+1000][k]!=-1) return dp[start+1000][k];
        long long left=0, right=0;
        
        right = dfs(start+1, end, k-1, dp);
        
        if(k-1 >= (end-start+1)){
            left = dfs(start-1, end, k-1, dp);
        }
        
        return dp[start+1000][k] = (left+right)%mod;
    }
public:
    int numberOfWays(int start, int end, int k) {
        vector<vector<long long>> dp(3100, vector<long long>(1001, -1));
        return dfs(start, end, k, dp)%mod;
    }
};