class Solution {
private:
    long long dfs(int idx, string& s, vector<long long>& dp){
        if(idx>s.length()) return 0;
        if(idx == s.length()) return 1;
        int mod = 1e9+7;
        if(dp[idx]!=-1) return dp[idx];
        
        long long sin=0, doub=0;
        
        if(s[idx]!='0'){
            
            if(idx+1<s.length()){
                string val = s.substr(idx, 2);
                if(val == "1*"){
                    doub = (9*dfs(idx+2, s, dp));
                } else if(val == "2*"){
                    doub = (6*dfs(idx+2, s, dp));
                } else if(val == "**"){
                    doub = (15*dfs(idx+2, s, dp));
                } else if(s[idx]=='*' && s[idx+1]>='0' && s[idx+1]<='6') {
                    doub = 2*dfs(idx+2, s, dp);
                } else if(s[idx] == '*'){
                    doub = dfs(idx+2, s, dp);
                }
                else if(s[idx]!='*' && s[idx+1]!='*' && stoi(val)>=1 && stoi(val)<=26) {
                    doub = dfs(idx+2, s, dp);
                    
                } 
            }
                if(s[idx]=='*') sin = 9*dfs(idx+1, s, dp);
                else sin = dfs(idx+1, s, dp);
            
            
        }
        
        return dp[idx] = (doub+ sin)%mod;
    }
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<long long> dp(n, -1);
        return (int)dfs(0, s, dp);
    }
};