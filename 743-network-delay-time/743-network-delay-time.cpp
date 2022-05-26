class MyCompare{
 public:
    bool operator()(const vector<int>& a, const vector<int>& b){
        return a.back() < b.back();
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int, vector<pair<int, int>>> adj;
        
        priority_queue<vector<int>, vector<vector<int>>, MyCompare> pq;
        
        pq.push({k, 0});
        
        vector<int> dist(n+1, INT_MAX);
        dist[k]=0;
        
        for(auto x:times){
            adj[x[0]].push_back({x[1], x[2]});
        }
        
        while(!pq.empty()){
            
            auto f = pq.top();
            pq.pop();
            
            int dU = f[1];
            int parent = f[0];
            
            for(auto child_info:adj[parent]){
                int child = child_info.first;
                int dV = child_info.second;
                
                if(dist[child] > dU + dV){
                    dist[child] = dU + dV;
                    pq.push({child, dist[child]});
                }
            }
            
        }
        
        int ans = INT_MIN;
        for(int i=1;i<=n;i++){
            ans = max(ans, dist[i]);
        }
        
        return ans==INT_MAX?-1:ans;
    }
};