class UnionFind{
 private:
    
public:
    vector<int> root;
    vector<int> rank;
    UnionFind(int n): root(n), rank(n) {
        for(int i=0;i<n;i++) {
            root[i]=i;
            rank[i]=1;
        }
    }
    
    int find(int x) {
        if(root[x]==x) return x;
        return root[x] = find(root[x]);
    }
    
    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        
        if(rx!=ry) {
            
            if(rank[rx] >= rank[ry]) {
                
                root[ry] = rx;
                rank[rx] += rank[ry];
                
            } else {
                
                root[rx] = ry;
                rank[ry] += rank[rx];
                
            }
            
        }
    }
    
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
    
    int returnSize(int x) {
        return rank[find(x)];
    }
    
     
};
class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    bool isValid(vector<vector<int>> grid, int x, int y){
        return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
   }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        UnionFind uf(m*n);
        int max_area=INT_MIN;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                
                if(grid[i][j]) {
                    int p0 = i*n+j;
                
                for(int k=0;k<4;k++) {
                    
                    int new_x = i+dx[k];
                    int new_y = j + dy[k];
                    
                    int p1 = new_x*n + new_y;
                    
                    if(isValid(grid, new_x, new_y) && grid[new_x][new_y]==1 && !uf.isConnected(p0, p1)) {
                        
                        
                        uf.merge(p0, p1);
                        
                    }
                    
                }
                
                max_area = max(max_area, uf.returnSize(p0));
                }
                
            }
        }
        
        
        return max_area==INT_MIN?0:max_area;
        
        
        
    }
};