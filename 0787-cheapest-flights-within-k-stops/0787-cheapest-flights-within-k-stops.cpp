class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> dp(n, INT_MAX);
        vector<vector<pair<int, int>>> adj(n);
        for(auto e:flights){
            adj[e[0]].push_back({e[1], e[2]});
        }
        // dist, node, stops
        pq.push({0, src, 0});
        
        while(!pq.empty()){
            auto f = pq.top(); pq.pop();
            int dist = f[0], node=f[1], stops=f[2];
            
            if(dp[node] < stops || stops > k+1) continue;
            dp[node]=stops;
            if(node == dst) return dist;
            
            for(auto neigh:adj[node]){
                int v = neigh.first, price=neigh.second;
                pq.push({dist+price, v, stops+1});
            }
            
        }
        
        return -1;
    }
};