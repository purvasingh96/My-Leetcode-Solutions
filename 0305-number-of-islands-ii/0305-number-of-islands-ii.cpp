class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    vector<int> root;
    int count;
    
    int find(int x){
        if(root[x]==x) return x;
        return root[x]=find(root[x]);
    }
    
    void merge(int x, int y){
        int rx = find(x);
        int ry = find(y);
        
        if(rx!=ry){
            root[ry]=rx;
            count-=1;
        }
    }
    
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        root.resize(m*n, -1);
        count=0;
        vector<int> res;
        for(auto p:positions){
            
            int x = p[0], y = p[1];
            int coord = x*n+y;
            if(root[coord] == -1){
                root[coord]=coord;
                count+=1;
            } else {
                res.push_back(count);
                continue;
            }
            
            for(int i=0;i<4;i++){
                int new_x = x+dx[i];
                int new_y = y+dy[i];
                int new_coord = new_x*n+new_y;
                if(new_x>=0 && new_x<m && new_y>=0 && new_y<n && root[new_coord]!=-1){
                    merge(coord, new_coord);
                }
            }
            
            res.push_back(count);
        }
        
        return res;
        
    }
};