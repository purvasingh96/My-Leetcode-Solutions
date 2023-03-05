class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,k});
        
       unordered_map<int, vector<pair<int, int>>> adj;
        for(auto t:times){
            adj[t[0]].push_back({t[2], t[1]});
        }
        
        vector<bool> visited(n,false);
        vector<int> dist(n+1, 1e9);
        dist[k]=0;
        
        while(!pq.empty()){
            auto f=pq.top(); pq.pop();
            int u = f.second;
            
            visited[u]=true;
            for(auto neigh:adj[u]){
                int v = neigh.second, wt = neigh.first;
                if(!visited[v] && dist[v] > dist[u]+wt){
                    dist[v] = dist[u]+wt;
                    pq.push({dist[v], v});
                }
            }
        }
        
        int ans=0;
        for(int i=1;i<=n;i++) ans=max(ans, dist[i]);
        return ans==1e9?-1:ans;
    }
};