class Solution {
private:
    long long dfs(int idx, vector<long long>& dp, vector<vector<int>>& questions){
        int n = questions.size();
        
        if(idx>=n) {
            return 0;
        }
        
        if(dp[idx]!=-1) return dp[idx];
        
        long long pick=0, notpick=0;
        int start=idx+questions[idx][1]+1;
            
        pick = questions[idx][0] + dfs(start, dp, questions);
        
        notpick = dfs(idx+1, dp, questions);
        
        return dp[idx] = max(pick, notpick);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        return dfs(0, dp, questions);
    }
};