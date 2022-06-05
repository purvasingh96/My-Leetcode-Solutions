class UnionFind{
 public:
    vector<int> rank;
    vector<int> root;
    
    UnionFind(int n): rank(n), root(n){
        for(int i=0;i<n;i++){
            rank[i]=1;
            root[i]=i;
        }
    }
    
    int find(int x){
        if(x==root[x]) return x;
        return root[x]=find(root[x]);
    }
    
    void merge(int x, int y){
        int rx = find(x);
        int ry = find(y);
        
        if(rx!=ry){
            if(rank[rx]>=rank[ry]){
                rank[rx]+=rank[ry];
                root[ry]=rx;
            } else{
                rank[ry]+=rank[rx];
                root[rx]=ry;
            }
        }
        
    }
};
class Solution {
public:
    int maximumInvitations(vector<int>& f) {
        int n = f.size();
        vector<int> ans(n, 1);
        
        vector<int> indegree(n,0);
        
        for(int i=0;i<n;i++){
            indegree[f[i]]+=1;
        }
        
        
        queue<int> q;
        
        // not part of cycle
        for(int i=0;i<n;i++){
            if(indegree[i]==0) {
                q.push(i);
            }
        }
        
        while(!q.empty()){
            
            auto v = q.front();
            q.pop();
            
            int c = f[v];
            
            ans[c] = max(ans[c], ans[v]+1);
            indegree[c]-=1;
            
            if(indegree[c]==0) {
                q.push(c);
            }
            
        }
        
        UnionFind* uf = new UnionFind(n);
        
        for(int i=0;i<n;i++){
            if(indegree[i]){
                uf->merge(i, f[i]);
            }
        }
        
        int res=0, joinable=0;
        
        for(int i=0;i<n;i++){
            
            if(!indegree[i]) continue;
            
            int len = uf->rank[uf->find(i)];
            
            if(len==2){
                
                int v = i;
                int c = f[i];
                indegree[c]-=1;
                
                len = ans[c] + ans[v];
                
                joinable+= len;
                
            } else{
                
                res = max(res, len);
                
            }
            
            
        }
        
        return max(res, joinable);
        
    }
};