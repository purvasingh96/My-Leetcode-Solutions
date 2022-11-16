class UnionFind{
public:
    vector<int> root;
    vector<int> rank;
    int comp;
    
    UnionFind(int n): root(n), rank(n) {
        for(int i=0;i<n;i++){
            root[i] = i;
            rank[i] = 1;
        }
        comp=n;
    }
    
    int find(int x){
        if(root[x] == x) return x;
        return root[x] = find(root[x]);
    }
    
    void merge(int x, int y){
        int rx = find(x);
        int ry = find(y);
        
        if(rx!=ry){
            
            if(rank[rx] > rank[ry]){
                rank[rx] += rank[ry];
                root[ry] = rx;
            } else{
                rank[ry] += rank[rx];
                root[rx] = ry;
            }
            
            comp-=1;
        }
        
    }
    
    int components(){
        return comp;
    }
    
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UnionFind uf(n);
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                int ax = stones[i][0], ay = stones[i][1];
                int bx = stones[j][0], by = stones[j][1];
                
                if(ax==bx || ay==by){
                    uf.merge(i, j);
                }
                
            }
        }
        
        return n - uf.components();
        
    }
};