class Solution {
private:
    vector<int> rank;
    vector<int> root;
    
    int find(int x){
        if(root[x] == x) return x;
        return root[x] = find(root[x]);
    }
    
    bool merge(int x, int y){
        int rx = find(x);
        int ry = find(y);
        
        
        if(rx!=ry){
            if(rank[rx] >= rank[ry]){
                root[ry]=rx;
                rank[rx]+=rank[ry];
            } else{
                root[rx] = ry;
                rank[ry]+= rank[rx];
            }
            
            return true;
        }
        
        return false;
    }
    
    
    int cycleLength(int start, int end, int n, vector<vector<int>>& adj){
        queue<int> q;
        q.push(start);
        int level=0;
        vector<bool> visited(n, false);
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int f = q.front();q.pop();
                visited[f]=true;
                
                if(f==end) return level+1;
                
                for(auto x:adj[f]){
                    if(!visited[x]) q.push(x);
                }
            }
            level+=1;
        }
        
        return level+1;
    }
    
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        root.resize(n);
        rank.resize(n, 1);
        
        for(int i=0;i<n;i++) root[i]=i;
        
        int minLength=INT_MAX;
        vector<int> targets;
        vector<vector<int>> adj(n);
        
        for(auto e:edges){
            int u = e[0], v = e[1];
            
            
            if(!merge(u, v)){
//                 cout<<"u: "<<u<<" cycleLength: "<<cycleLength(u, v, n, adj)<<"\n";
//                 for(int i=0;i<adj.size();i++){
                    
//                     cout<<i<<"->";
//                     for(auto y:adj[i]) cout<<y<<" ";
//                     cout<<"\n";
//                 }
                minLength = min(minLength, cycleLength(u, v, n, adj));
            }
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        return minLength==INT_MAX?-1:minLength;
    }
};