class dsu{
public:
    vector<int> root;
    vector<int> rank;
    
    dsu(int n){
        root.resize(n);
        rank.resize(n);
        
        for(int i=0;i<n;i++){
            root[i] = i;
            rank[i] = 1;
        }
    }
    
    int find(int x){
        if(root[x] == x){
            return x;
        }
        
        return root[x] = find(root[x]);
    }
    
    void merge(int x, int y){
        int rx = find(x);
        int ry = find(y);
        
        if(rx!=ry){
            if(rank[rx] >= rank[ry]){
                root[ry] = rx;
                rank[rx] += rank[ry];
            } else {
                root[rx] = ry;
                rank[ry] += rank[rx];
            }
        }
    }
    
};
class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    bool isValid(int x, int y, int n){
        return x>=0 && y>=0 && x<n && y<n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        dsu d(n*n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    for(int k=0;k<4;k++){
                        int new_x = i+dx[k];
                        int new_y = j+dy[k];
                        
                        if(isValid(new_x, new_y, n) && grid[new_x][new_y]==1){
                            d.merge(n*i+j, new_x*n+new_y);
                        }
                        
                    }
                }
            }
        }
        
        int maxSize=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j] == 0){
                    unordered_set<int> roots;
                    for(int k=0;k<4;k++){
                        int new_x = i+dx[k];
                        int new_y = j+dy[k];
                        
                        if(isValid(new_x, new_y, n) && grid[new_x][new_y]==1){
                            roots.insert(d.find(n*new_x + new_y));
                        }
                    }
                    
                    int size=1;
                    for(auto x:roots){
                        size += d.rank[x];
                    }
                    maxSize = max(maxSize, size);
                }
            }
        }
        
        return maxSize==INT_MIN ? n*n : maxSize;
        
        
    }
};