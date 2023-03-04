class Solution {
private:
    vector<int> root;
    vector<int> rank;
    int count;
    int find(int x){
        if(root[x]==x) return x;
        return root[x]=find(root[x]);
    }
    
    void merge(int x, int y){
        int rx = find(x);
        int ry = find(y);
        
        if(rx!=ry){
            count-=1;
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
    int findCircleNum(vector<vector<int>>& res) {
        int n = res.size();
        root.resize(n);
        rank.resize(n, 1);
        count=n;
        for(int i=0;i<n;i++) root[i]=i;
        
        unordered_map<int, vector<int>> adj;
        
        for(int u=0;u<res.size();u++){
            for(int v=0;v<res[0].size();v++){
                if(res[u][v]){
                    merge(u, v);
                }
            }
        }
        
        return count;
    }
};