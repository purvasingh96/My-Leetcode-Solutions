class Solution {
private:
    bool backtrack(int idx, string s, string currWord, int length, vector<string>& dict, map<pair<string, int>, bool>& dp){
        
        if(idx>=s.length()){
            if(length == s.length()){
                return true;
            }
            return false;
        }
        
        if(dp.find({currWord, idx})!=dp.end()){
            return dp[{currWord, idx}];
        }
        
        currWord += s[idx];
        
        
        bool ans = backtrack(idx+1, s, currWord, length, dict, dp);
        
        if(find(dict.begin(), dict.end(), currWord)!=dict.end()){    
            bool skip = backtrack(idx+1, s, "", length+currWord.length(), dict, dp);
            ans = ans || skip;
        } 
          
        return dp[{currWord, idx}] = ans;
        
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<pair<string, int>, bool> dp;
        return backtrack(0, s, "", 0, wordDict, dp);
    }
};