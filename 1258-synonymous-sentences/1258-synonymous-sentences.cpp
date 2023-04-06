class Solution {
private:
    unordered_map<string, string> root;
    unordered_map<string, int> rank;
    unordered_map<string, unordered_set<string>> m;
    
    string find(string s){
        if(root[s] == s) return s;
        return root[s] = find(root[s]);
    }
    
    void merge(string u, string v){
        m[u].insert(v);
        m[v].insert(u);
        string rx = find(u);
        string ry = find(v);
        
        if(rx!=ry){
            if(rank[rx]>=rank[ry]){
            root[ry]=rx;
            rank[rx]+=rank[ry];
        } else {
            root[rx]=ry;
            rank[ry]+=rank[rx];
        }
        }
        
        
    }
    
    void removeLastWord(string& s){
        int i=s.length()-1;
        while(i>=0 && s[i]!=' '){
            s.pop_back();
            i-=1;
        }
    }
    
    void dfs(int idx, vector<string>& s, string& temp, vector<string>& res){
        if(idx >= s.size()){
            string t = temp;
            t.pop_back();
            res.push_back(t);
            return;
        }
        
        // dont take neigbors
        temp += (s[idx] + " ");
        dfs(idx+1, s, temp, res);
        temp.pop_back();
        removeLastWord(temp);
        
        // take neighbors
        for(auto next:m[s[idx]]){
            temp += (next+ " ");
            dfs(idx+1, s, temp, res);
            temp.pop_back();
            removeLastWord(temp);
        }
    }
    
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        for(auto x:synonyms){
            root[x[0]]=x[0];
            root[x[1]] = x[1];
            rank[x[0]]=1;
            rank[x[1]]=1;
        }
        
        for(auto x:synonyms){
            merge(x[0], x[1]);
        }
        
        // [a, b], [c, d] 
        // adj[a]=>{a, b}
        for(auto x:root){
            string u = find(x.second);
            string v = x.first;
            if(u!=v) m[u].insert(v);
        }
        
        // [a, b], [b, c], [c, d], [d, e]
        /*
          
            adj[a] -> {b, c, d, e}
            adj[b] -> {a, c}
            adj[c] -> {b, d}
            adj[d] -> {c, e}
            adj[e] -> {d}
          
            
        */
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
                if(y==x.first) x.second.erase(y);
            }
        }
        
        stringstream ss(text);
        string t;
        vector<string> s;
        while(getline(ss, t, ' ')){
            s.push_back(t);
        }
        
        vector<string> res;
        string temp="";
        dfs(0, s, temp, res);
        sort(res.begin(), res.end());
        return res;
        
    }
};