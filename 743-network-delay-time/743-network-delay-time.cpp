struct Compare{
  public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // single source + 
        // weighted edges + 
        // shortest path +
        // +ve weights => dijkstra template
        
        vector<int> recieveTime(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        pq.push(make_pair(k, 0));
        recieveTime[k]=0;
        
        map<int, vector<pair<int, int>>> adj;
        
        for(auto x:times) {
            adj[x[0]].push_back(make_pair(x[1], x[2]));
        }
        
        while(!pq.empty()) {
            
            auto f = pq.top();
            pq.pop();
            
            int parent = f.first;
            int time = f.second;
            
            for(auto c:adj[parent]) {
                
                int child = c.first;
                int new_time = c.second;
                
                if(recieveTime[child] > time + new_time) {
                    
                    recieveTime[child] = time + new_time;
                    pq.push(make_pair(child, recieveTime[child]));
                }
                
            }
            
        }
        
        int ans = INT_MIN;
        for(int i=1;i<=n;i++) {
            ans = max(ans, recieveTime[i]);
        }
        
        return ans ==INT_MAX?-1:ans;
        
    }
};