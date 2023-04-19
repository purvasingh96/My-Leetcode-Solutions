class Solution {
private:
    string build(vector<string>& s){
        string res="";
        for(auto word:s){
            res += word;
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
        
        stringstream ss(text);
        vector<string> res;
        string t;
        while(getline(ss, t, ' ')){
            res.push_back(t);
        }
        
        queue<vector<string>> q;
        q.push(res);
        
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            
            for(auto& word:f){
                if(m.find(word)==m.end()) continue;
                else {
                    for(auto& synonym: m[word]){
                        word = synonym;
                        string temp = build(f);
                        if(ans.count(temp)==0){
                            ans.insert(temp);
                            q.push(f);
                        }
                    }
                }
            }
            
        }
        
        vector<string> answer(ans.begin(), ans.end());
        return answer;
    }
};