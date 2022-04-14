class Solution {
public:
    vector<int> createHash(string s) {
        
        vector<int> count(26, 0);
        for(auto c:s) {
            count[c-'a'] += 1;
        }
        
        return count;
    }
    
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
           map<vector<int>, vector<string>> m;
            vector<vector<string>> res;
        
        for(auto c:strs) {
            m[createHash(c)].push_back(c);
        }
        
        for(auto it:m) {
            res.push_back(it.second);
        }
        
        return res;
    }
};