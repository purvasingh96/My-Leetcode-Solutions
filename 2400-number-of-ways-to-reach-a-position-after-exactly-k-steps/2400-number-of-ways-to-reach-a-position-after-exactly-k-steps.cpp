class Solution {
private:
    long long dfs(int cur_pos, int endpos, int k, vector<vector<int>>& dp){
        int mod = 1e9+7;
        
        if((cur_pos==endpos && k==0)) return 1;
        if(k<=0) return 0;
        
        
        if(dp[cur_pos+1000][k]!=-1) return dp[cur_pos+1000][k];
        
        // left
        long long left=0;
        
        long long right = 0;
        
        if(k >= cur_pos-endpos) right = dfs(cur_pos+1, endpos, k-1, dp);
        
        if(k>= endpos-cur_pos) left = dfs(cur_pos-1, endpos, k-1, dp);
        
        return dp[cur_pos+1000][k] = (left+right)%mod;
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(3100, vector<int>(1001, -1));
        int mod=1e9+7;
        return (int)dfs(startPos, endPos, k, dp)%mod;
    }
};