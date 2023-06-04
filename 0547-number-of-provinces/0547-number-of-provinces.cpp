class Solution {
private:
    vector<int> root;
    vector<int> rank;
    int provinces;
    
    int find(int x){
        if(root[x] == x) return x;
        return root[x] = find(root[x]);
    }
    
    void merge(int x, int y){
        int rx = find(x);
        int ry = find(y);
        
        if(rx!=ry){
            if(rank[rx] >= rank[ry]){
                root[ry]=rx;
                rank[rx]+=rank[ry];
            } else {
                root[rx]=ry;
                rank[ry]+=rank[rx];
            }
            provinces-=1;
        }
    }
    
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        root.resize(n, 0);
        for(int i=0;i<n;i++) root[i] = i;
        rank.resize(n, 1);
        provinces = n;
        
        
        for(int u=0;u<n;u++){
            for(int v=0;v<n;v++){
                if(isConnected[u][v]){
                    merge(u,v);
                    //cout<<"u: "<<u<<" v: "<<v<<" provinces: "<<provinces<<"\n";
                }
            }
        }
        
        return provinces;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};