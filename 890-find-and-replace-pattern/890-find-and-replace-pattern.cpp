class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(auto word:words){
            
            vector<int> pw(26, -1);
            vector<int> wp(26, -1);
            bool keep=true;
            
            for(int i=0;i<word.length();i++){
                
                if(pw[pattern[i]-'a']==-1){
                    if(wp[word[i]-'a']!=-1){
                        if(wp[word[i]-'a']!=pattern[i]-'a') {
                            keep=false;
                            break;
                        }
                    } else{
                        wp[word[i]-'a'] = pattern[i]-'a';
                        pw[pattern[i]-'a'] = word[i]-'a';
                    }
                } else {
                    if(pw[pattern[i]-'a'] != word[i]-'a') {
                        keep=false;
                        break;
                    }
                }
            }
            if(keep) res.push_back(word);
        }
        return res;
    }
};