class Solution {
private:
    bool startsWith(string a, string prefix){
        for(int i=0;i<prefix.length();i++){
            if(a[i]!=prefix[i]){
                return false;
            }
        }
        
        return true;
    }
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        
        for(auto word:words){
            for(auto c:word){
                adj[c] = {};
                indegree[c]=0;
            }
        }
        
        for(int i=0;i<words.size()-1;i++){
            string a = words[i];
            string b = words[i+1];
            
            if(b.length() < a.length() && startsWith(a, b)){
                return "";
            }
            
            int j=0, k=0;
            while(j<a.length() && k<b.length() && a[j]==b[k]){
                j+=1;
                k+=1;
            }
            
            if(j<a.length() && k<b.length()){
                if(adj[a[j]].count(b[k]) == 0){
                adj[a[j]].insert(b[k]);
                indegree[b[k]]+=1;
            }
    
            }
                        
        }
        
        
        string order="";
        queue<char> q;
        for(auto x:indegree){
            if(x.second==0){
                q.push(x.first);
            }
        }
        
        if(q.size()==0){
            return "";
        }
        
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            order+=f;
            for(auto x:adj[f]){
                indegree[x]-=1;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
            
        }
        cout<<"order: "<<order<<" "<<adj.size();
        return order.length() == adj.size() ? order : "";
        
        
        
    }
};