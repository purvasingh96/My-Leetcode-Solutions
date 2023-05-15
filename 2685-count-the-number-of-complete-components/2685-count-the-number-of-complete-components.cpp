class Solution {
private:
    vector<int> root;
    vector<int> rank;
    
    int find(int x){
        if(root[x] == x) return x;
        return root[x] = find(root[x]);
    }
    
    bool merge(int x, int y){
        int rx = find(x);
        int ry = find(y);
        
        if(rx!=ry){
            if(rank[rx] >= rank[ry]){
                root[ry] = rx;
                rank[rx]+=rank[ry];
            } else {
                root[rx]=ry;
                rank[ry]+=rank[rx];
            }
            return true;
        }
        
        return false;
        
    }
    
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        unordered_map<int, int> edge;
        unordered_map<int, int> node;
        
        
        root.resize(n, 0);
        rank.resize(n, 0);
        
        for(int i=0;i<n;i++) root[i]=i;
        
        for(auto e:edges){
            int u=e[0], v=e[1];
            merge(u, v);
        }
        
        for(int i=0;i<n;i++){
            node[find(root[i])]+=1;
        }
        
        for(auto e:edges){
            edge[find(e[0])]+=1;
        }
            
        int ans=0;
        for(auto x:node){
            int root = x.first;
            int vertices = x.second;
            int connections = edge[root];
            if(connections == (vertices)*(vertices-1)/2) ans+=1;
        }
        
        return ans;
    }
};