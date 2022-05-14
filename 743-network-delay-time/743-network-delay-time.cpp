class MyCompare {
public:
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a.back() > b.back();
    }
    
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // single source + traverse all nodes => Dijkstra template
        
        map<int, vector<pair<int, int>>> adj;
        priority_queue<vector<int>, vector<vector<int>>, MyCompare> pq;
        pq.push({k, 0});
        
        
        for(auto x:times) {
            int u = x[0];
            int v = x[1];
            int dist = x[2];
            
            adj[u].push_back({v, dist});
        }
        
        vector<int> dist(n+1, INT_MAX);
        dist[k]=0;
        
        while(!pq.empty()) {
            
            auto parent_info = pq.top();
            pq.pop();
            
            int parent = parent_info[0];
            int dp = parent_info[1];
            
            
            for(auto c:adj[parent]){
                int child = c.first;
                int dc = c.second;
                
                if(dist[child] > dp + dc) {
                    dist[child] = dp + dc;
                    pq.push({child, dist[child]});
                }
                
            }
            
        }
        
        int res = INT_MIN;
        for(int i=1;i<=n;i++) {
            res = max(res, dist[i]);
        }
        
        return  res == INT_MAX ? -1: res;
    }
};