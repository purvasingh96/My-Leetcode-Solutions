class Solution {
private:
    unordered_map<string, int> rank;
    unordered_map<string, string> root;
    unordered_map<string, unordered_set<string>> m;
    
    string find(string x){
        if(root.find(x)!=root.end() && root[x] == x) return x;
        return root[x] = find(root[x]);
    }
    
    void merge(string u, string v){
        m[u].insert(v);
        m[v].insert(u);
        string rx = find(u);
        string ry = find(v);
        
        if(rx!=ry){
            if(rank[rx] >= rank[ry]){
                root[ry]=rx;
                rank[rx]+=rank[ry];
            } else {
                root[rx]=ry;
                rank[ry]+=rank[rx];
            }
        }
    }
    
    void removeWordFromBack(string& s){
        int i=s.length()-1;
        while(i>=0 && s[i--]!=' '){
            s.pop_back();
        }
    }
    
    void formString(int idx, vector<string>& s, string& temp, vector<string>& res){
        if(idx >= s.size()) {
            string t = temp;
            t.pop_back();
            res.push_back(t);
            return;
        }
        
        
          temp += (s[idx] + " ");
            formString(idx+1, s, temp, res);
            temp.pop_back();
            removeWordFromBack(temp);
        
        // take
        
         if(m.find(s[idx])!=m.end()) {
            for(auto word:m[s[idx]]){
                temp += (word + " ");
                formString(idx+1, s, temp, res); 
                temp.pop_back();
                removeWordFromBack(temp);
            }
            
        }
        
    }
    
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        for(auto x:synonyms){
            root[x[0]] = x[0];
            root[x[1]] = x[1];
            rank[x[0]] = 1;
            rank[x[1]] = 1;
        }
        for(auto s:synonyms){
            merge(s[0], s[1]);
        }
        
        
        
        for(auto x:root){
            string u = find(x.second);
            string v = x.first;
            if(u!=v) m[u].insert(v);
        }
        
       
        
        for(auto x:m){
            for(auto y:x.second){
                for(auto z:x.second){
                    if(y!=z){
                        m[y].insert(z);
                        m[z].insert(y);
                    }
                }
            }
            for(auto y:x.second){
                if(y == x.first) x.second.erase(y);
            }
        }
        
        
        stringstream ss(text);
        string temp;
        vector<string> s;
        while(getline(ss, temp, ' ')){
            s.push_back(temp);
        }

        
        string tempStr="";
        vector<string> res;
        formString(0, s, tempStr, res);
        sort(res.begin(), res.end());
        return res;
        
    }
};