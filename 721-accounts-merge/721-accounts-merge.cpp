class UnionFind {
private:
    vector<int> root;
    vector<int> sz;
public:
    UnionFind(int n): root(n), sz(n) {
        for(int i=0;i<n;i++){
            root[i] = i;
            sz[i]=1;
        }
    }
    
    int find(int x){
        if(root[x] == x) return x;
        return root[x] = find(root[x]);
    }
    
    void union_(int x, int y){
        int rx = find(x);
        int ry = find(y);
        
        if(rx!=ry){
            if(sz[rx] >= sz[ry]) {
                sz[rx] += sz[ry];
                root[ry] = rx;
            } else{
                root[rx] = ry;
                sz[ry] += rx;
            }
        }
    }
    
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailGroup;
        int n = accounts.size();
        UnionFind uf(n);
        
        for(int i=0;i<accounts.size();i++){
            
            string name = accounts[i][0];
            int m = accounts[i].size();
            
            for(int j=1;j<m;j++){
                string email = accounts[i][j];
                if(emailGroup.find(email) == emailGroup.end()) emailGroup[email] = i;
                else {
                    uf.union_(i, emailGroup[email]);
                }
            }
            
        }
        
        unordered_map<int, vector<string>> components;
        
        for(auto x:emailGroup){
            string email = x.first;
            int group = x.second;
            components[uf.find(group)].push_back(email);
        }
        
        vector<vector<string>> mergedAccounts;
        
        for(auto it:components){
            int group = it.first;
            vector<string> emails = it.second;
            vector<string> temp = {accounts[group][0]};
            temp.insert(temp.end(), emails.begin(), emails.end());
            sort(temp.begin()+1, temp.end());
            
            mergedAccounts.push_back(temp);
        }
        
        return mergedAccounts;
    }
};