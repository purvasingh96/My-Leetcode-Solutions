class Solution {
private:
    char hash(char s, int n){
        return (s - n + 26)%26 + 'a';
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> m;
        for(auto s:strings){
            string h="";
            for(auto c:s){
                h += hash(c, s[0]);
            }
            m[h].push_back(s);
        }
        
        vector<vector<string>> res;
        for(auto x:m){
            res.push_back(x.second);
        }
        
        return res;
    }
};