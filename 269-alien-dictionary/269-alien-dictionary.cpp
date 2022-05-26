class Solution {
public:
    string alienOrder(vector<string>& words) {
        map<char, vector<char>> adj;
        map<char, int> indegree;
        int z=0;
        
        for(auto word:words){
            for(auto c:word){
                indegree[c]=0;
            }
        }
        
        for(int i=0;i<words.size()-1;i++){
            string a = words[i], b = words[i+1];
            
            if(a.length() > b.length()) {
                // searches for last occurance of t in s
                if(a.rfind(b, 0) == 0){
                    // implies t is prefix of s
                    return "";
                }
            }
            
            
            for(int j=0;j<min(a.length(), b.length());j++){
                
                if(a[j]!=b[j]){
                    indegree[b[j]]+=1;
                    adj[a[j]].push_back(b[j]);
                    break;
                }
                
            }
           
            
        }
        
        queue<char> q;
        for(auto x:indegree){
            
            if(x.second==0){
                q.push(x.first);
                z+=1;
            }
        }
        
        if(z==0) return "";
        string ans="";
        
        while(!q.empty()){
            
            auto f = q.front();
            q.pop();
            ans+=f;
            
            for(auto c:adj[f]){
                indegree[c]-=1;
                if(indegree[c]==0){
                    q.push(c);
                    z+=1;
                }
            }
            
        }
        
        if(z!=indegree.size()) return "";
        return ans;
        
    }
};