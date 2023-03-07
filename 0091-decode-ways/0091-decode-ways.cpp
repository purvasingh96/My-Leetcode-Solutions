class Solution {
private:
    int dfs(int idx, string& s, vector<int>& dp){
        if(idx>= s.length()){
            return 1;
        }
        
        if(dp[idx]!=-1) return dp[idx];
        
        int singleDigit=0, doubleDigit=0;
        if(s[idx]!='0'){
            singleDigit += dfs(idx+1, s, dp);
            if(idx+1<s.length()){
                int val = stoi(s.substr(idx, 2));
                if(val >= 1 && val <= 26){
                    doubleDigit += dfs(idx+2, s, dp);
                }
            }
            
        }
        
        return dp[idx] = singleDigit + doubleDigit;
    }
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n, -1);
        return dfs(0, s, dp);
    }
};