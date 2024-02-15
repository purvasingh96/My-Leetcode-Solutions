class UnionFind{
public:
    vector<int> root;
    vector<int> size;
    UnionFind(int n){
        root.resize(n);
        size.resize(n, 1);
        for(int i=0;i<n;i++){
            root[i]=i;
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
            if(size[rx] >= size[ry]){
                root[ry]=rx;
                size[rx]+=size[ry];
            } else {
                root[rx] = ry;
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
        UnionFind uf(n*n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int new_x = i+dx[k];
                        int new_y = j+dy[k];
                        
                        if(isValid(new_x, new_y, n) && grid[new_x][new_y]==1){
                            uf.merge(n*i+j, new_x*n+new_y);
                        }
                    }
                }
            }
        }
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j] == 0){
                    set<int> st;
                    for(int k=0;k<4;k++){
                        int new_x = i+dx[k];
                        int new_y = j+dy[k];
                        
                        if(isValid(new_x, new_y, n) && grid[new_x][new_y]==1){
                            st.insert(uf.find(new_x*n+new_y));
                        }
                    }
                    int sum=1;
                
                    for(auto x:st){
                        sum += uf.size[x];
                    }
                    //cout<<sum<<"\n";
                    ans = max(ans, sum);
                }
                
                
            }
        }
        
        return ans==INT_MIN? n*n : ans;
        
    }
};