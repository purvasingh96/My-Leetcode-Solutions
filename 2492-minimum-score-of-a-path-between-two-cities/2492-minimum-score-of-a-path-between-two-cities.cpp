class Solution {
private:
    vector<int> root;
    vector<int> dist;
    
    int find(int x){
        if(root[x]==x) return x;
        return root[x] = find(root[x]);
    }
    
    void merge(int x, int y, int d){
        int rx = find(x);
        int ry = find(y);
        
        if(rx==ry){
            if(d < dist[rx]){
                dist[rx]= dist[ry] = dist[y] = dist[x] = d;
                root[rx] = root[x] = root[y] = x;
            }
        } else {
            
            if(dist[rx]<=dist[ry]){
                root[ry]=rx;
            } else {
                root[rx]=ry;
            }
            
            dist[rx] = dist[ry] = min({dist[rx], dist[ry], d});
            
        }
    }
    
public:
    int minScore(int n, vector<vector<int>>& roads) {
        root.resize(n+1);
        for(int i=0;i<root.size();i++) root[i]=i;
        dist.resize(n+1, INT_MAX);
        for(auto r:roads) merge(r[0], r[1], r[2]);
        return dist[find(n)];
    }
};