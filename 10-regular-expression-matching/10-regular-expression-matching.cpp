class Solution {
private:
    bool dp(int i, int j, string s, string p, map<vector<int>, bool>& memo){
        if(memo.find({i, j})!=memo.end()) {
            return memo[{i, j}];
        }
        
        if(i>=s.length() && j>=p.length()) return true;
        if(j>=p.length()) return false;
        
        int match = (i<s.length() && (s[i]==p[j] || p[j]=='.'));
        
        if(j+1<p.length() && p[j+1]=='*'){
            
            memo[{i,j}] = dp(i, j+2, s, p, memo) || (match && dp(i+1, j, s, p, memo));
            return memo[{i,j}];
        }
        
        if(match) {
            memo[{i,j}] = dp(i+1, j+1, s, p, memo);
            return memo[{i,j}];
        }
        
       memo[{i,j}]=false;
        return memo[{i,j}];
        
    }
public:
    bool isMatch(string s, string p) {
        map<vector<int>, bool> memo;
        return dp(0, 0, s, p, memo);
    }
};