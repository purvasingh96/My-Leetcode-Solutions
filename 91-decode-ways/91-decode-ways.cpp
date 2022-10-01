class Solution {
private:
    int dfs(int i, string& s, vector<int>& dp){
        // successfuly found 1 way to decode
        if(i>=s.length()) return 1;
        
        // memoization
        if(dp[i]!=-1) return dp[i];
        
        int l=0, r=0;
        
        string c1(1, s[i]);
        int a = stoi(c1);
        
        if(a>=1 && a<=26) l = dfs(i+1, s, dp);
        else l=0;
        
        if(i+1<s.length() && s[i]!='0') {
            string c2 = s.substr(i, 2);
            int b = stoi(c2);
            if(b>=1 && b<=26) r=dfs(i+2, s, dp);
            else r=0;
        }
        
        
        
        return dp[i] = l+r;
        
    }
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n, -1);
        return dfs(0, s, dp);
    }
};