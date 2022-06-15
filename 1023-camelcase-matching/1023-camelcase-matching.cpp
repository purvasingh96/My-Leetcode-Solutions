class Solution {
private:
    bool check(string s, string pattern){
        int i=0;
        int j=0;
        //if(s[0]!=pattern[0]) return false;
        
        while(i<s.length() && j<pattern.length()){
            if(s[i] >='A' && s[i]<='Z'){
                if(s[i]!=pattern[j]) return false;
            }
            if(s[i] == pattern[j]){
                i+=1;
                j+=1;
            } else{
                i+=1;
            }
        }
        
        if(j<pattern.length()) return false;
        
        for(i;i<s.length();i++){
            if(s[i]>='A' && s[i]<='Z'){
                return false;
            }
        }
        
        return true;
    }
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for(auto word:queries){
            res.push_back(check(word, pattern));
        }
        return res;
    }
};