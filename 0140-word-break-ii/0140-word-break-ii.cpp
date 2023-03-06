class Solution {
private:
    void backtrack(int idx, string& s, string curr, unordered_set<string>& set,vector<string>& res){
        if(idx == s.length()){
            curr.pop_back();
            res.push_back(curr);
        }
        
        string str="";
         for(int i=idx;i<s.length();i++)
        {
            //get every substring and check if it exists in set
            str.push_back(s[i]);
            if(set.count(str))
            {
                //we have got a word in dict 
                //explore more and get other substrings
                backtrack(i+1,s,curr+str+" ",set,res);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        unordered_set<string> dict;
        for(auto x:wordDict) dict.insert(x);
        backtrack(0, s, "", dict, ans);
        return ans;
    }
};