class Solution {
private:
    long long dfs(int cur_pos, int endpos, int k, unordered_map<string, long long>& dp){
        int mod = 1e9+7;
        
        if((cur_pos==endpos && k==0)) return 1;
        if(k<=0) return 0;
        
        string val = to_string(cur_pos) + "#" + to_string(k);
        if(dp.find(val)!=dp.end()) return dp[val]%mod;
        
        // left
        long long left=0;
        
        long long right = 0;
        
        if(k >= cur_pos-endpos) right = dfs(cur_pos+1, endpos, k-1, dp);
        
        if(k>= endpos-cur_pos) left = dfs(cur_pos-1, endpos, k-1, dp);
        
        return dp[val] = (left+right)%mod;
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        unordered_map<string, long long> dp;
        int mod=1e9+7;
        return (int)dfs(startPos, endPos, k, dp)%mod;
    }
};