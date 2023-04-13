class Solution {
private:
    string strSort(string& s){
        vector<int> count(26, 0);
        for(auto c:s){
            count[c-'a']+=1;
        }
        
        string res="";
        for(int i=0;i<26;i++){
            if(count[i]>0){
                string t(count[i], i+'a');
                res+=t;
            }
        }
        
        return res;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(auto s:strs){
            
            m[strSort(s)].push_back(s);
        }
        vector<vector<string>> res;
        for(auto it:m){
            res.push_back(it.second);
        }
        return res;
    }
};