class UnionFind {
public:
    vector<int> root;
    vector<int> size;
    
    UnionFind(int sz) : root(sz), size(sz) {
        for(int i=0;i<sz;i++) {
            root[i]=i;
            size[i]=1;
        }
    }
    
    int find(int x) {
        if(x == root[x]) return x;
        return root[x] = find(root[x]);
    }
    
    void unionFind(int x, int y) {
        
        int rx = find(x);
        int ry = find(y);
        
        if(rx!=ry) {
            
            if(size[rx] >= size[ry]) {
                size[rx] += size[ry];
                root[ry] = rx;
            } else {
                size[ry] += size[rx];
                root[rx] = ry;
            }
            
        }
        
    }
};
    


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n = accounts.size();
        UnionFind uf(n);
        map<string, int> emailGroup;
        
        for(int i=0;i<n;i++) {
            
            int m = accounts[i].size();
            
            for(int j=1;j<m;j++) {
                
                string email = accounts[i][j];
                
                if(emailGroup.find(email) == emailGroup.end()) emailGroup[email] = i;
                else {
                    uf.unionFind(i, emailGroup[email]);
                }
                
            }
            
        }
        
        
        map<int, vector<string>> components;
        
        for(auto it:emailGroup) {
            
            string email = it.first;
            int group = it.second;
            
            components[uf.find(group)].push_back(email);
            
        }
        
        vector<vector<string>> mergedAccounts;
        for(auto it:components) {
            int group = it.first;
            vector<string> acc = it.second;
            
            vector<string> mergedAcc = {accounts[group][0]};
            
            mergedAcc.insert(mergedAcc.end(), acc.begin(), acc.end());
            
            sort(mergedAcc.begin()+1, mergedAcc.end());
            mergedAccounts.push_back(mergedAcc);
            
            
        }
        
        return mergedAccounts;
    }
};