class DSU{
public:
    vector<int> root;
    vector<int> rank;
    
    DSU(int n){
        root.resize(n);
        rank.resize(n, 1);
        
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
            if(rank[rx] >= rank[ry]){
                root[ry] = rx;
                rank[rx]+=rank[ry];
            } else {
                root[rx]  = ry;
                rank[ry] += rank[rx];
            }
        }
        
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& nums) {
        
        int n = nums.size();
        DSU dsu(n);
        
        unordered_map<string, int> m;
        
        for(int i=0;i<n;i++){
            
            for(int j=1;j<nums[i].size();j++){
                if(m.find(nums[i][j]) != m.end()){
                    dsu.merge(m[nums[i][j]], i);
                } else {
                    m[nums[i][j]] = i;
                }
            }
        }
        
        unordered_map<int, vector<string>> res;
        
        for(auto x:m){
            res[dsu.find(x.second)].push_back(x.first);
        }
        
        vector<vector<string>> ans;
        for(auto x:res){
            vector<string> temp;
            temp.push_back(nums[x.first][0]);
            sort(x.second.begin(), x.second.end());
            temp.insert(temp.end(), x.second.begin(), x.second.end());
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};