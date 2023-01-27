class Solution {
private:
    bool dfs(string& word, int idx, unordered_set<string>& dict){
        if(idx == word.length()) return true;
        
        for(int i=idx+1;i<word.length();i++){
            
            string s1 = word.substr(0, i);
            string s2 = word.substr(i);
            if(dict.count(s1) && dict.count(s2)) return true;
            
            //cout<<"s1: "<<s1<<" s2: "<<s2<<"\n";
            bool ans = dict.count(word.substr(0, i));
            //cout<<"s1: "<<s1<<" present: "<<ans<<"\n";                                  
            if(ans && dfs(s2, 0, dict)) return true;
        }
        
        return false;
    }
    
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string, int> dp;
        unordered_set<string> dict(words.begin(), words.end());
        vector<string> res;
        
        
        
        for(auto word:words){
            if(dfs(word, 0, dict)) res.push_back(word);
        }
        
        return res;
    }
};