class Solution {
private:
    int maxlen;
    int dfs(int idx, int prev, string& res, int k, vector<vector<int>>& dp){
        
        if(idx>=res.length()) {
            return 0;
        }
        
        if(dp[idx][prev]!=-1) return dp[idx][prev];
        
        int pick=0, notpick=0; 
        if(prev == 26 || abs(res[idx] - prev) <= k) {
            
           pick = 1+dfs(idx+1, res[idx], res, k, dp);
            
        } 
            
            notpick = dfs(idx+1, prev, res, k, dp);
        
        return dp[idx][prev] = max(pick, notpick);
            
       
    }
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(150, -1));
        return dfs(0, 26, s, k, dp);
    }
};