class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        map<int, vector<pair<int, int>>> adj;
        
        for(auto x:flights) {
            adj[x[0]].push_back({x[1], x[2]});
        }
        
        vector<int> dist(n, INT_MAX);
        k+=1;
        
        dist[src] = 0;
        
        queue<pair<int, int>> q;
        
        q.push({0, src});
        
        while(!q.empty() && k--) {
            
            int n = q.size();
            
            for(int i=0;i<n;i++) {
                
                auto f = q.front();
                q.pop();
                
                int dU = f.first;
                int p = f.second;
                
                for(auto c:adj[p]) {
                    
                    int ch = c.first;
                    int dV = c.second;
                    
                    if(dist[ch] > dU + dV) {
                        
                        dist[ch] = dU + dV;
                        q.push({dist[ch], ch});
                        
                    }
                    
                    
                }
                
                
            }
            
        }
        
        return dist[dst] ==INT_MAX?-1:dist[dst];
        
    }
};