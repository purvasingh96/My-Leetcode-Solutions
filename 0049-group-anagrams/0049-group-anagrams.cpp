class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> m;
        for(auto s:strs){
            vector<int> count(26, 0);
            for(auto c:s){
                count[c-'a']+=1;
            }
            m[count].push_back(s);
        }
        vector<vector<string>> res;
        for(auto it:m){
            res.push_back(it.second);
        }
        return res;
    }
};