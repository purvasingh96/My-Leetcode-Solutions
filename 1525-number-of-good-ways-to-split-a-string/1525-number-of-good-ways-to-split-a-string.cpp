class Solution {
private:
    int dfs(int idx, string& s, vector<int>& dp, unordered_map<char, int>& left, unordered_map<char, int>& right){
        
        if(idx == s.length()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        
        left[s[idx]]+=1;
        right[s[idx]]-=1;
        if(right[s[idx]]==0) right.erase(s[idx]);
        int ans=0;
        if(left.size() == right.size()) {
            
            ans += (1 + dfs(idx+1, s, dp, left, right));
            
        } else {
            
            ans += dfs(idx+1, s, dp, left, right);
        }
        return dp[idx] = ans;
    }
public:
    int numSplits(string s) {
        int n = s.length();
        unordered_map<char, int> left;
        unordered_map<char, int> right;
        for(auto c:s) right[c]+=1;
        vector<int> dp(n, -1);
        return dfs(0, s, dp, left, right);
    }
};