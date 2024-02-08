class DisjointSet{
public:
    vector<int> root, size;
    DisjointSet(int n){
        root.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<=n;i++){
            root[i]=i;
        }
    }
    
    int find(int i){
        if(root[i] == i) return i;
        return root[i] = find(root[i]);
    }
    
    void union_(int x, int y){
        int rx = find(x);
        int ry = find(y);
        
        
        if(rx!=ry){
            if(size[rx] >= size[ry]){
                root[ry]=rx;
                size[rx]+=size[ry];
            } else {
                root[rx]=ry;
                size[ry]+=size[rx];
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
        DisjointSet ds(n*n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    for(int d=0;d<4;d++){
                        int r = dx[d]+i;
                        int c = dy[d]+j;
                        
                        if(isValid(r, c, n) && grid[r][c]){
                            ds.union_(n*r+c, n*i+j);
                        }
                    }
                }
            }
        }
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    set<int> st;
                    for(int d=0;d<4;d++){
                        int r = dx[d]+i;
                        int c = dy[d]+j;
                        
                        if(isValid(r, c, n) && grid[r][c]){
                            st.insert(ds.find(n*r+c));
                        }
                    }
                    
                    int temp=1;
                    for(auto x:st){
                        temp += ds.size[x];
                    }
                    
                    ans = max(ans, temp);
                }
            }
        }
        
        
        return ans==INT_MIN ? n*n : ans;
    }
};