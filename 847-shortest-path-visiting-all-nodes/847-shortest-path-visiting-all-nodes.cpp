class NodeDetails{
public:
    int node;
    int dist;
    int mask;
    NodeDetails(int node, int dist, int mask) {
        this->node = node;
        this->dist = dist;
        this->mask = mask;
    }
};

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if(graph.size()==1) return 0;
        
        int n = graph.size();
        int end_mask = (1 << n) - 1;
        int steps=0;
            
        vector<vector<bool>> visited(n, vector<bool>(end_mask, false));
        
        queue<NodeDetails> q;
        
        for(int i=0;i<n;i++) {
            
            int node = i;
            int dist = 1;
            int mask = (1<<i);
            
            NodeDetails nd(node, dist, mask);
            
            q.push(nd);
            
            visited[node][mask] = true;
            
        }
        
        while(!q.empty()) {
            
            
                
                auto info = q.front();
                q.pop();
                
                int node = info.node;
                int dist = info.dist;
                int mask = info.mask;
                
                for(auto neighbour:graph[node]) {
                    
                    int next_mask = (mask | (1<<neighbour));
                    
                    if(next_mask == end_mask) return (dist);
                    
                    if(!visited[neighbour][next_mask]) {
                        
                        visited[neighbour][next_mask] = true;
                        NodeDetails next_nd(neighbour, dist+1, next_mask);
                        q.push(next_nd);
                        
                    }
                }
                
            
            
            
        }
        
        return -1;
    }
};