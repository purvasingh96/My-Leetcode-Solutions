class Solution {
private:
    long long dfs(int idx, int steps, int n, vector<vector<long long>>& dp){
        int mod = 1e9+7;
        if(steps==0 && idx==0) return 1;
        if(idx>=n || idx<0 || steps==0 || idx>steps) return 0;
        
        //cout<<"idx: "<<idx<<" "<<"steps: "<<steps<<"\n";
        if(dp[idx][steps]!=-1) return dp[idx][steps];
        
        long long stay = dfs(idx, steps-1, n, dp);
        long long left = dfs(idx-1, steps-1, n, dp);
        long long right = dfs(idx+1, steps-1, n, dp);
        
        return dp[idx][steps] = (stay+left+right)%mod;
    }
public:
    int numWays(int steps, int n) {
        vector<vector<long long>> dp(steps+1, vector<long long>(steps+1, -1));
       
        return (int)dfs(0, steps, n, dp);
    }
};