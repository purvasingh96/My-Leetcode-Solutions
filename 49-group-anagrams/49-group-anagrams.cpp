class Solution {
public:
    string createHash(string s) {
        // O(K)
        vector<int> count(26, 0);
        for(auto c:s) {
            count[c-'a'] += 1;
        }
        
        string hash = "";
        
        for(int i=0;i<count.size();i++) {
            if(count[i]>0) hash += string(count[i], i+'a');
        }
        
        return hash;
    }
    
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
           map<string, vector<string>> m;
            vector<vector<string>> res;
        //O(NK)
        for(auto c:strs) {
            m[createHash(c)].push_back(c);
        }
        
        for(auto it:m) {
            res.push_back(it.second);
        }
        
        return res;
    }
};