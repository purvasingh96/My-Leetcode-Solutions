class Edge{
public:
    int u;
    int v;
    int w;
    Edge(int u, int v, int w): u(u), v(v), w(w) {
        
    }
};

class MyCompare{
public:
    bool operator()(const Edge& a, const Edge& b){
        return a.w > b.w;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<Edge, vector<Edge>, MyCompare> pq;
        vector<bool> visited(n, false);
        
        int res=0, count=0;
        
        for(int j=0;j<n;j++) {
            
            int weight = abs(points[0][0] - points[j][0]) + abs(points[0][1] - points[j][1]);
            
            Edge edge(0, j, weight);
            
            pq.push(edge);
            
        }
        
        visited[0] = true;
        
        while(!pq.empty() && count!=n-1) {
            
            auto f = pq.top();
            pq.pop();
            
            if(!visited[f.v]){
                
                visited[f.v] = true;
                res += f.w;
                
                for(int j=0;j<n;j++) {
                    
                    if(!visited[j]) {
                        
                        int dist = abs(points[f.v][0] - points[j][0]) + abs(points[f.v][1] - points[j][1]);
                        Edge edge(f.v, j, dist);
                        pq.push(edge);
                        
                    }
                    
                }
                
                count += 1;
                
            }
            
            
        }
        
        return res;
        
    }
};