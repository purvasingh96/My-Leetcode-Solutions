class Solution {
private:
    int dfs(vector<vector<int>>& pairs, int idx, int prev, vector<vector<int>>& dp){
        if(idx>=pairs.size()) return 0;
        
        if(dp[idx][prev]!=-1) return dp[idx][prev];
        
        int pick=0, notpick=0;
        
        if(pairs[idx][0] + 1001 > prev){
            pick = 1+dfs(pairs, idx+1, pairs[idx][1]+1001, dp);
        }
        
        notpick = dfs(pairs, idx+1, prev, dp);
        
        return dp[idx][prev] = max(pick, notpick);
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<vector<int>> dp(n, vector<int>(2002, -1));
        sort(pairs.begin(), pairs.end());
        return dfs(pairs, 0, 0, dp);
    }
};