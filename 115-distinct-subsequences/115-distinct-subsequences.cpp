class Solution {
private:
    int dfs(int is, int it, string s, string t, vector<vector<int>>& dp){
        
        if(it==t.length()) {
            return 1;
        }
        
        if(is==s.length()){
            return 0;
        }
        
        if(dp[is][it]!=-1) return dp[is][it];
        
        int count=0;
        for(int i=is;i<=min(s.length()-1, s.length()-t.length()+it);i++){
            if(s[i] == t[it]){
                count += dfs(i+1, it+1, s, t, dp);
            } else{
                continue;
            }
        }
        
        return dp[is][it] = count;
        
    }
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
        return dfs(0, 0, s, t, dp);
        
    }
};