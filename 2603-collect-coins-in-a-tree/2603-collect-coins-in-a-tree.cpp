class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<int> degree(n, 0);
        vector<unordered_set<int>> m(n, unordered_set<int>());
        
        for(auto e:edges){
            m[e[0]].insert(e[1]);
            m[e[1]].insert(e[0]);
            degree[e[0]]+=1;
            degree[e[1]]+=1;
        }
        
        queue<int> q;
        
        for(int i=0;i<n;i++){
            if(degree[i]==1 && coins[i]==0){
                q.push(i);
            }
        }
        
        // remove useless leaves
        while(!q.empty()){
            int node = q.front(); q.pop();
            for(auto child:m[node]){
                if(--degree[child]==1 && coins[child]==0){
                    q.push(child);
                }
                m[child].erase(node);
            }
            m[node].clear();
            degree[node]=n;
        }
        
        for(int i=0;i<n;i++){
            if(degree[i]==1){
                q.push(i);
            }
        }
        
        // remove parent of coin nodes
        for(int level=0;level<2;level++){
            
            int sz = q.size();
            while(sz--){
                auto node = q.front();
                q.pop();
                for(auto child:m[node]){
                    if(--degree[child]==1){
                        q.push(child);
                    }
                    m[child].erase(node);
                }
                m[node].clear();
                degree[node]=n;
            }
            
        }
        
        int ans=0;
       for(int i=0;i<m.size();i++){
           if(m[i].size()>0) ans+=1;
       }
        
        return max(0, ans-1)*2;
        
    }
};