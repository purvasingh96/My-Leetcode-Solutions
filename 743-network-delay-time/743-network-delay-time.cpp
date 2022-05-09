class MyCompare{
public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int totalTime = INT_MIN;
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        map<int, vector<pair<int, int>>> adj;
        
        for(auto x:times) {
            adj[x[0]].push_back({x[1], x[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, MyCompare> pq;
        
        pq.push({k, 0});
        
        while(!pq.empty()) {
            
            auto top = pq.top();
            pq.pop();
            
            int parent = top.first, time = top.second;
            
            for(auto x:adj[parent]) {
                int child = x.first;
                int newTime = x.second;
                
                if(dist[child] > time + newTime) {
                    dist[child] = time + newTime;
                    pq.push({child, dist[child]});
                }
            }
            
        }
        
        for(int i=1;i<dist.size();i++) {
            totalTime = max(totalTime, dist[i]);
        }
        return totalTime==INT_MAX?-1:totalTime;
        
    }
};