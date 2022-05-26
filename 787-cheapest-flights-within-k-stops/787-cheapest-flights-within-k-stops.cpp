class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // we know source, and asked to find cheapest route = BFS + dijkstra
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        queue<pair<int, int>> q;
        q.push({0, src});
        
        map<int, vector<pair<int, int>>> adj;
        
        for(auto f:flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }
        
        k+=1;
        
        while(!q.empty() && k--){
            int sz = q.size();
            
            for(int i=0;i<sz;i++){
                
                auto f = q.front();
                q.pop();
                
                int dU = f.first;
                
                for(auto ch:adj[f.second]){
                    
                    int child = ch.first;
                    int dV = ch.second;
                    
                    if(dist[child] > dU + dV) {
                        dist[child] = dU + dV;
                        q.push({dist[child], child});
                    }
                    
                }
            }
        }
        
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};