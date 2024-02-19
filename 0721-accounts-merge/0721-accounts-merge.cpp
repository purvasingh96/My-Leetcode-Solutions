class UnionFind{
 public:
    vector<int> root;
    vector<int> size;
    
    UnionFind(int n){
        root.resize(n);
        size.resize(n);
        
        for(int i=0;i<n;i++){
            root[i]=i;
            size[i]=1;
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
                root[ry] = rx;
                size[rx] += size[ry];
            } else {
                root[rx] = ry;
                size[ry] += size[rx];
            }
        }
    }
};
class Solution {
    
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> m;
        vector<vector<string>> ans;
        int n = accounts.size();
        UnionFind uf(n);
        
        
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                string email = accounts[i][j];
                
                if(m.find(email)==m.end()){
                    m[email] = i;
                } else {
                    uf.merge(i, m[email]);
                }
            }
        }
        
        
        vector<vector<string>> res(n);
        for(auto x:m){
            int idx = uf.find(x.second);
            //cout<<"idx:: "<<idx<<" "<<x.first<<"\n";
            res[idx].push_back(x.first);
        }
        
        for(int i=0;i<res.size();i++){
            vector<string> temp;
            if(res[i].size()!=0){
                string account = accounts[i][0];
                temp.push_back(account);
                sort(res[i].begin(), res[i].end());
                temp.insert(temp.end(), res[i].begin(), res[i].end());
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};