class Solution {
private:
    bool startsWith(string& a, string& prefix){
        for(int i=0;i<prefix.length();i++){
            if(a[i]!=prefix[i]) return false;
        }
        return true;
    }
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> st;
        int unq=0;
        int n = words.size();
        unordered_map<char, int> indegree;
        
        for(auto word:words){
            for(auto c:word){
                st[c]={};
            }
        }
        
        for(int i=0;i<n-1;i++){
            string a = words[i], b = words[i+1];
            int j=0, k=0;
            if(b.length() < a.length() && startsWith(a, b)) return "";
            
            while(j<a.length() && k<b.length() && a[j] == b[k]){
                j+=1;
                k+=1;
            }
            if(j<a.length() && k<b.length()){
                if(st[a[j]].count(b[k])==0){
                    st[a[j]].insert(b[k]);
                    indegree[b[k]]+=1;     
                }
               
            }
        }
        
        queue<char> q;
        
        for(auto it:st){
            if(indegree[it.first]==0){
                q.push(it.first);
            }
        }
        
        cout<<q.size();
        string res="";
        while(!q.empty()){
            auto f = q.front();q.pop();
            string t(1, f);
            res+=t;
            
            for(auto x:st[f]){
                
                indegree[x]-=1;
                if(indegree[x]==0) q.push(x);
            }
        }
        return res.length()!=st.size() ? "":res;
        
    }
};