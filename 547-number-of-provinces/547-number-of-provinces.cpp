class UnionFind{
private:
    vector<int> root;
    vector<int> rank;
public:
    int provinces;
    
    UnionFind(int sz): root(sz), rank(sz) {
        for(int i=0;i<sz;i++) {
            root[i]=i;
            rank[i]=1;
        }
        provinces = sz-1;
    }
    
    int find(int x) {
        if(root[x]==x) {
            return x;
        }
        
        return root[x] = find(root[x]);
    }
    
    void unionSet(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        
        if(rx!=ry) {
            
            if(rank[rx] >= rank[ry]) {
                root[ry]=rx;
                rank[rx]+=1;
            } else {
                root[rx] = ry;
                rank[ry] +=1;
            }
            
            provinces -= 1;
        }
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf(n+1);
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(isConnected[i][j]) {
                    uf.unionSet(i+1, j+1);
                }
            }
        }
        
        
        return uf.provinces;
        
        
    }
};