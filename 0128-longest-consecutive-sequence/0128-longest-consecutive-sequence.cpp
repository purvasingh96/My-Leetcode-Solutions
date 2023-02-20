class UnionFind{
public:
    unordered_map<int, int> root;
    unordered_map<int, int> rank;
    UnionFind(unordered_map<int, int> m){
        for(auto x:m){
            int val = x.first;
            root[val]=val;
            rank[val]=1;
        }
    }
    
    int find(int a){
        if(root.find(a)!=root.end() && root[a]==a) return a;
        return root[a] = find(root[a]);
    }
    
    void merge(int a, int b){
        int rx = find(a);
        int ry = find(b);
        
        if(rx!=ry){
            if(rank[rx]>=rank[ry]){
                root[ry]=rx;
                rank[rx]+=rank[ry];
            } else{
                root[rx]=ry;
                rank[ry]+=rank[rx];
            }
        }
    }
    
    bool isConnected(int a, int b){
        return find(a) == find(b);
    }
    
    unordered_map<int, int> returnRank(){
        return rank;
    }
    
};

class Solution {

public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int, int> m;
        for(auto num:nums) m[num]+=1;
        int n = m.size();
        UnionFind* uf = new UnionFind(m);
        
        for(auto x:m){
            int num = x.first;
            //cout<<num<<"\n";
            if(m.find(num+1)!=m.end()) {
                if(!uf->isConnected(num, num+1)) uf->merge(num, num+1);
            }
            if(m.find(num-1)!=m.end()) {
                if(!uf->isConnected(num, num-1)) uf->merge(num, num-1);
            }
        }
    
        int ans=0;
        // for(auto x:uf->returnRank()){
        //     cout<<x.first<<" "<<x.second<<"\n";
        // }
       for(auto x:uf->returnRank()) ans=max(ans, x.second);
        return ans;
        
        
    }
};