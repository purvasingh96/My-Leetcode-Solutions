class DSU{
 public:
    vector<int> root;
    vector<int> size;
    DSU(int n){
        root.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            root[i]=i;
            size[i]=1;
        }
    }
    
    int find(int x){
        if(root[x] == x) {
            return x;
        }
        return root[x] = find(root[x]);
    }
    
    void merge(int x, int y){
        int rx = find(x);
        int ry = find(y);
        
        if(rx!=ry){
            if(size[rx] >= size[ry]){
                root[ry] = rx;
                size[rx] += size[ry];
            } else {
                root[rx] = ry;
                size[ry]+=size[rx];
            }
        }
    }
        
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);
        
        
        unordered_map<string, int> m;
        
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(m.find(accounts[i][j]) == m.end()){
                    m[accounts[i][j]] = i;
                } else {
                    dsu.merge(i, m[accounts[i][j]]);
                }
            }
        }
        
        cout<<"working";
        
        vector<vector<string>> ans(n);
        
        for(auto x:m){
            int idx = dsu.find(x.second);
            ans[idx].push_back(x.first);
        }
        vector<vector<string>> res;
        for(int i=0;i<ans.size();i++){
            if(ans[i].size()!=0){
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                sort(ans[i].begin(), ans[i].end());
                temp.insert(temp.end(), ans[i].begin(), ans[i].end());
                res.push_back(temp);
            }
            
        }
        return res;
    }
};