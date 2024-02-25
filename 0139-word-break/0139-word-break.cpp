class Solution {
private:
    bool helper(string s, int i, string temp, vector<string>& dict, map<pair<int, string>, bool>& dp){
        if(i>=s.length()){
            if(temp=="" || find(dict.begin(), dict.end(), temp)!=dict.end()){
                return dp[{i, temp}] = true;
            }
            return dp[{i, temp}] = false;
        }
        
        if(dp.find({i, temp})!=dp.end()){
            return dp[{i, temp}];
        }
        
        temp += s[i];
        
        
        if(find(dict.begin(), dict.end(), temp)!=dict.end()){
            // element found
            return dp[{i, temp}] = helper(s, i+1, "", dict, dp) || helper(s, i+1, temp, dict, dp);
        } else {
            return dp[{i, temp}] = helper(s, i+1, temp, dict, dp);
        }
        
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<pair<int, string>, bool> dp;
       
        return helper(s, 0, "", wordDict, dp);
    }
};