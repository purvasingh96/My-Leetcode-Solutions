class Solution {
private:
    bool dfs(int k, int i, int j, string s1, string s2, string s3, vector<vector<int>>& memo){
        
        if(i==s1.length()){
            return s2.substr(j) == s3.substr(k);
        }
        
        if(j==s2.length()){
            return s1.substr(i) == s3.substr(k);
        }
        
        if(memo[i][j]>=0) {
            return memo[i][j] == 1 ? true:false;
        }
        
        bool ans=false;
        
        bool c1 = (s3[k] == s1[i] && dfs(k+1, i+1, j, s1, s2, s3, memo));
        bool c2 = (s3[k] == s2[j] && dfs(k+1, i, j+1, s1, s2, s3, memo));
        
        if(c1 || c2){
            ans = true;
        }
        
        memo[i][j] = ans ? 1: 0;
        return ans;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l = s3.length(), m = s1.length(), n = s2.length();
        
        if(l!=m+n) return false;
        
        vector<vector<int>> memo(m, vector<int>(n, -1));
        
        return dfs(0, 0, 0, s1, s2, s3, memo);
        
    }
};