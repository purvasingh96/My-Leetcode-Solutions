class Solution {
private:
    int dfs(int idx, int c0, int c1, vector<string>& strs, vector<vector<vector<int>>>& dp){
        
        if(idx == strs.size() || c0<0 || c1<0) return 0;
        
        if(dp[idx][c0][c1]!=-1) return dp[idx][c0][c1];
        
        int x0 = count(strs[idx].begin(), strs[idx].end(), '0');
        int x1 = strs[idx].length() - x0;
        
        int pick=-1;
        int not_pick = dfs(idx+1, c0, c1, strs, dp);
        
        if(c0-x0>=0 && c1-x1>=0){
           pick = 1 + dfs(idx+1, c0-x0, c1-x1, strs, dp); 
        }
        
        return dp[idx][c0][c1] = max(pick, not_pick);
    }
    
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k = strs.size();
        vector<vector<vector<int>>> dp(k, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        
        return dfs(0, m, n, strs, dp);
    }
};