class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        int n = points.size();
        
        int mstCost =0;
        int edgesUsed = 0;
        vector<bool> seen(n, false);
        
        while(edgesUsed < n){
            
            auto f = pq.top();
            pq.pop();
            
            int weight = f.first;
            int node = f.second;
            
            if(seen[node]) continue;
            
            seen[node] = true;
            
            mstCost += weight;
            edgesUsed += 1;
            
            for(int nextNode=0;nextNode < n;nextNode++){
                
                if(!seen[nextNode]){
                    int w = abs(points[node][0] - points[nextNode][0]) + 
                        abs(points[node][1] - points[nextNode][1]);
                    
                    pq.push({w, nextNode});
                }
                
            }
            
        }
        
        return mstCost;
        
    }
};