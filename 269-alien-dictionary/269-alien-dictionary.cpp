class Solution {
public:
    string alienOrder(vector<string>& words) {
        map<char, vector<char>> adj;
        map<char, int> indegree;
        int numzero=0;
        string res="";
        queue<char> q;
        
        for(int i=0;i<words.size();i++){
            for(auto c:words[i]){
                indegree[c] = 0;
            }
        }
        
        for(int i=0;i<words.size()-1;i++) {
            
            string s = words[i];
            string t = words[i+1];
            
            if(s.length() > t.length()) {
                // if prefix comes later, no valid ordering can be generated
                if(s.rfind(t, 0) == 0){
                    return "";
                }
            }
                
                for(int j=0;j<min(s.length(), t.length());j++) {
                    if(s[j]!=t[j]) {
                        indegree[t[j]]+=1;
                        adj[s[j]].push_back(t[j]);
                        break;
                    }
                }
                
            
        }
            
            for(auto x:indegree) {
                if(x.second == 0){
                    q.push(x.first);
                    numzero+=1;
                }    
            }
            
            if(numzero == 0) return "";
            
            while(!q.empty()){
                
                char f = q.front();
                q.pop();
                
                res += f;
                
                for(auto c:adj[f]){
                    
                    indegree[c] -= 1;
                    
                    if(indegree[c] == 0) {
                        q.push(c);
                        numzero+=1;
                    }
                    
                }
                
            }
        
        if(numzero!=indegree.size()) return "";
            
            return res;
            
        
    }
};