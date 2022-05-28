class Solution {
public:
    /*
    {abc, de, def}
     012345
     abcdef
     dp[i] = (s.substr(i-wl+1, i+1) == wordDict && dp[i-wl])
     return ndp[s.len-1]
    
    */
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length()+1, false);
        dp[0]=true;
        set<string> wordSet(wordDict.begin(), wordDict.end());
        
        for (int i = 1; i <= s.length(); i++) {
            for(int j=0;j<i;j++){
                
                if(dp[j] && wordSet.find(s.substr(j, i-j))!=wordSet.end()){
                    dp[i] = true;
                    break;
                }
                
            }
        }
     
        return dp[s.length()];
        
    }
};