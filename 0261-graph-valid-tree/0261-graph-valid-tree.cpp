class Solution {
private:
    vector<int> rank;
    vector<int> root;
    
    int find(int x){
        if(root[x] == x) return x;
        return root[x] = find(root[x]);
    }
    
    void merge(int x, int y){
        int rx = find(x), ry=find(y);
        if(rx!=ry){
            if(rank[rx] >= rank[ry]){
                root[ry]=rx;
                rank[rx]+=rank[ry];
            } else{
                root[rx]=ry;
                rank[ry]+=rank[rx];
            }
        }
    }
    
    bool isConnected(int x, int y){
        return find(x)==find(y);
    }
    
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // tree: graph should have exactly n-1 edges.
        if(edges.size()!=n-1) return false;
        
        root.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++) root[i]=i;
        
        for(auto e:edges){
            if(isConnected(e[0], e[1])) return false;
            merge(e[0], e[1]);
        }
        
        return true;
    }
};