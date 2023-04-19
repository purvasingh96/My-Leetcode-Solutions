class Solution {
private:
    string buildSentence(vector<string>& str){
        string res="";
        for(auto x:str){
            res += x;
            res+=" ";
        }
        res.pop_back();
        return res;
    }

public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        set<string> ans;
        ans.insert(text);
        unordered_map<string, vector<string>> m;
        
        for(auto s:synonyms){
            m[s[0]].push_back(s[1]);
            m[s[1]].push_back(s[0]);
        }
        
        vector<string> words;
        queue<vector<string>> q;
        
        stringstream ss(text);
        string buff;
        
        while(getline(ss, buff, ' ')){
            words.push_back(buff);
        }
        
        q.push(words);
        
        
        while(!q.empty()){
            vector<string> f = q.front();
            q.pop();
            for(auto& wd : f){
                if (m.count(wd) == 0) continue; // if word not in graph, skip
                else{
                    for (auto& syno : m[wd]){
                        wd = syno; // replace by new synoymous word
                        string newText = buildSentence(f);
                        if (ans.count(newText) == 0){
                            ans.insert(newText); // insert new text string to ans
                            q.push(f); // push new word vector to que
                        }
                    }
                }
            }   
        }
        
        vector<string> result(ans.begin(), ans.end());
        return result;
        
    }
};