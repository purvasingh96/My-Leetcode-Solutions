class Solution {
private:
    vector<int> root;
    vector<int> rank;
    
    int find(int x){
        if(root[x]==x) return x;
        return root[x]=find(root[x]);
    }
    
    void merge(int x, int y, int& dist, int d, int& e){
        int rx = find(x);
        int ry = find(y);
        
        if(rx!=ry){
            e+=1;
            dist+=d;
            if(rank[rx]>=rank[ry]){
                root[ry]=rx;
                rank[rx]+=rank[ry];
            } else{
                root[rx]=ry;
                rank[ry]+=rank[rx];
            }
        }
    }
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        root.resize(n+1);
        rank.resize(n+1, 1);
        for(int i=0;i<n;i++) root[i]=i;
        
        for(auto c:connections){
            pq.push({c[2], c[0], c[1]});
        }
        
        int e=0, dist=0;
        while(!pq.empty() && e!=(n-1)){
            auto f = pq.top();pq.pop();
            int d = f[0], u=f[1], v=f[2];
            merge(u, v, dist, d, e);
        }
        
        return e==(n-1)?dist:-1;
    }
};