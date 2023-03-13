class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> dp(n, INT_MAX);
        unordered_map<int, vector<vector<int>>> adj;
        for(auto f:flights){
            int u = f[0], v=f[1], d=f[2];
            adj[u].push_back({v,d});
        }
        // dist, node, stops
        
        pq.push({0, src, 0});
        
        while(!pq.empty()){
            auto f = pq.top();pq.pop();
            int dist=f[0], u=f[1], stops=f[2];
            
            if(dp[u] < stops || stops>k+1) continue;
            dp[u]=stops;
            if(u == dst) return dist;
            
            for(auto v:adj[u]){
                int neigh = v[0], price = v[1];
                int total = dist+price;
                pq.push({total, neigh, stops+1});
            }
            
        }
        
        return -1;
        
    }
};