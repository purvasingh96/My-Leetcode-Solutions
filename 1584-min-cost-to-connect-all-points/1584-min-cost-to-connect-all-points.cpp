class UnionFind {
private:
    vector<int> rank;
    vector<int> root;
public:
    UnionFind(int n): rank(n), root(n) {
        for(int i=0;i<n;i++) {
            rank[i]=1;
            root[i]=i;
        }
    }
    
    int find(int x) {
        if(root[x] == x) return x;
        return root[x] = find(root[x]);
    }
    
    bool merge(int x, int y) {
        
        int rx = find(x);
        int ry = find(y);
        
        if(rx == ry) {
            return false;
        }        
        
        if(rank[rx] >= rank[ry]) {
            
            root[ry] = rx;
            rank[rx] += 1;
            
        } else{
            
            root[rx] = ry;
            rank[ry] += 1;
            
        }
        
        return true;
        
    }
    
    
};



class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), mstCost=0, edgesUsed=0;
        vector<vector<int>> edges;
        
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                
                int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                
                edges.push_back({weight, i, j});
                
            }
        }
        
        sort(edges.begin(), edges.end());
        
        UnionFind uf(n);
        
        for(int i=0;i<edges.size();i++) {
            
            int weight = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];
            
            if(uf.merge(u, v)){
                mstCost += weight;
                edgesUsed += 1;
            }
            
            if(edgesUsed == n-1) break;
            
        }
        
        return mstCost;
        
    }
};