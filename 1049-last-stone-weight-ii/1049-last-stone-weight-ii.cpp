class Solution {
private:
    int dfs(int i, int w1, int w2, vector<int>& stones, vector<vector<int>>& dp){
        
        int diff = abs(w1-w2);
        
        if(i==stones.size()){
            return diff;
        }
        
        if(dp[i][diff]!=-1) return dp[i][diff];
        
        return dp[i][diff] = min(dfs(i+1, w1+stones[i], w2, stones, dp),
                                  dfs(i+1, w1, w2+stones[i], stones, dp));
        
    }
    
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        //sum = sum/2;
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        
        return dfs(0, 0, 0, stones, dp);
    }
};