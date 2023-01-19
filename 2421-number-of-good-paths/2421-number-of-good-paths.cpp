class UnionFind{
private:
    vector<int> root;
public:
    UnionFind(int n){
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
        
        if(rx==ry) return;
        
        root[ry]=rx;
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        map<int, vector<int>> adj;
        map<int, vector<int>> val2idx;
        int n = vals.size();
        UnionFind* uf = new UnionFind(n);
        int res=0;
        
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        for(int i=0;i<vals.size();i++){
            val2idx[vals[i]].push_back(i);
        }
        
        for(auto it:val2idx){
            for(auto node:it.second){
                for(auto neigh:adj[node]){
                    
                    if(vals[neigh]<=vals[node]){
                        uf->merge(node, neigh);
                    }
                    
                }
            }
            
            unordered_map<int, int> count;
            for(auto node:it.second){
                count[uf->find(node)] +=1;
                res += count[uf->find(node)];
            }
        }
        
        //for(auto x:uf->rr()) cout<<x<<" ";
        
        return res;
    }
};