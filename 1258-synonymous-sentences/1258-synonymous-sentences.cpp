class Solution {

private:
    unordered_map<string, unordered_set<string>> m;
    unordered_map<string, string> root;
    unordered_map<string, int> rank;
    
    string find(string x){
        if(root.find(x)!=root.end() && root[x] == x) return x;
        return root[x] = find(root[x]);
    }
    
    void merge(string x, string y){
        m[x].insert(y);
        m[y].insert(x);
        
        string rx = find(x);
        string ry = find(y);
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
    
    void removeWordFromBack(string& s){
        int i=s.length()-1;
        while(i>=0 && s[i--]!=' '){
            s.pop_back();
        }
    }
    
    void dfs(int idx, string& temp, vector<string>& s, unordered_map<string, unordered_set<string>>& m, vector<string>& res){
        
        if(idx >= s.size()) {
            string t = temp;
            t.pop_back();
            res.push_back(t);
            return;
        }
        
        
          temp += (s[idx] + " ");
            dfs(idx+1, temp, s, m, res);
            temp.pop_back();
            removeWordFromBack(temp);
        
        // take
        
         if(m.find(s[idx])!=m.end()) {
            for(auto word:m[s[idx]]){
                temp += (word + " ");
                dfs(idx+1, temp, s, m, res); 
                temp.pop_back();
                removeWordFromBack(temp);
            }
            
        }
        
        // not take
            
        
        
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
        
        
        for(auto it:root){
            if(find(it.second)!=it.first) m[find(it.second)].insert(it.first);
        }
        // cout<<"working";
        // for(auto x:m){
        //     cout<<x.first<<"->";
        //     for(auto y:x.second) cout<<y<<" ";
        //     cout<<"\n";
        // }
        
        for(auto x:m){
          for(auto y:x.second){
              for(auto z:x.second){
                  if(y!=z) {
                      m[y].insert(z);
                      m[z].insert(y);
                  }
              }
          }
        for(auto y:x.second){
            if(y==x.first) x.second.erase(y);
        }
      }
        
        // for(auto x:m){
        //     cout<<x.first<<"=>";
        //     for(auto y:x.second) cout<<y<<" ";
        //     cout<<"\n";
        // }
        
      
        
        vector<string> res;
        string temp="";
        stringstream ss(text);
        string t;
        vector<string> s;
        while(getline(ss, t, ' ')){
            s.push_back(t);
        }
        
        dfs(0, temp, s, m, res);
        sort(res.begin(), res.end());
        
        return res;
    }
};