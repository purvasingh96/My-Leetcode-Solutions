class UnionFind{
 public:
    vector<int> rank;
    vector<int> root;
    
    UnionFind(int n){
        rank.resize(n, 1);
        root.resize(n);
        for(int i=0;i<n;i++){
            root[i]=i;
        }
        
    }
    
    int find(int x){
        if(root[x] == x) return x;
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
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int sz = queries.size();
        vector<bool> res(sz);
        map<int, vector<pair<int, int>>> m;
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        
        sort(queries.begin(), queries.end(), [](const vector<int>& a, const vector<int>& b){
            return a[2] < b[2];
        });
        
        for(auto e:edgeList){
            int u = e[0], v=e[1], w=e[2];
            m[w].push_back({u,v});
        }
        
        UnionFind* uf = new UnionFind(n);
        auto it = m.begin();
        for(auto q:queries){
            
            int u = q[0], v=q[1], target=q[2], idx=q[3];
            
            while(it!=m.end() && it->first < target){
                    for(auto nodes:it->second){
                        uf->merge(nodes.first, nodes.second);
                    }
                it = next(it);
            }
            
            if(uf->root[uf->find(u)] == uf->root[uf->find(v)]){
                res[idx] = true;
            } else res[idx] = false;
        }
        
        return res;
    }
};