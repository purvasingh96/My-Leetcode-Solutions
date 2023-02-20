class UnionFind{
public:
    vector<int> rank;
    vector<int> root;
    
    UnionFind(int n){    
        rank.resize(n, 1);
        root.resize(n);
        for(int i=0;i<n;i++) root[i]=i;
    }
    
    int find(int x){
        if(root[x]==x) return x;
        return root[x] = find(root[x]);
    }
    
    void merge(int x, int y){
        int rx = find(x);
        int ry = find(y);
        if(rx!=ry){
            if(rank[rx]>=rank[ry]){
                root[ry]=rx;
                rank[rx]+=rank[ry];
            } else{
                root[rx]=ry;
                rank[ry]+=rank[rx];
            }
            
        }
    }
    
    bool connected(int x, int y){
        return find(x)==find(y);
    }
    
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        UnionFind* uf = new UnionFind(n);
        int components = n;
        sort(logs.begin(), logs.end());
        int ans;
        //cout<<uf->components();
        for(auto log:logs){
            
            int t=log[0], x=log[1], y=log[2];
            
            if(!uf->connected(x,y)){
                ans=t;
                uf->merge(x, y);
                components-=1;
                if(components==1) return ans;
            }
            
        }
        
        return -1;
    }
};