class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        /*
            1. do bfs from both nodes/
            2. create 2 visited arrays and 1 map(max(dist1, dist2) -> priority_queue<nodes>).
            3. if(visited1[node] && visited2[node]) 
        */
        
        int n = edges.size();
        vector<int> visited1(n, -1);
        vector<int> visited2(n, -1);
        
        // node, q_number, dist
        queue<vector<int>> q;
        
        unordered_map<int, vector<int>> adj;
        map<int, priority_queue<int, vector<int>, greater<int>>> m;
        
        for(int i=0;i<n;i++){
            if(edges[i]!=-1) adj[i].push_back(edges[i]);
        }
        
        q.push({node1, 1, 0});
        q.push({node2, 2, 0});
        
        while(!q.empty()){
            
            int sz = q.size();
            
            while(sz--){
                auto f = q.front();
                q.pop();
                int node = f[0], qv = f[1], dist = f[2];
                
                if(qv == 1){
                    visited1[node] = dist;
                    if(visited2[node]!=-1){
                        m[max(visited1[node], visited2[node])].push(node);
                    }
                    
                    for(auto next:adj[node]){
                        if(visited1[next]==-1){
                            q.push({next, 1, dist+1});
                        }
                    }
                    
                    
                } else if(qv == 2){
                    visited2[node] = dist;
                    if(visited1[node]!=-1){
                        m[max(visited1[node], visited2[node])].push(node);
                    }
                    
                    for(auto next:adj[node]){
                        if(visited2[next]==-1){
                            q.push({next, 2, dist+1});
                        }
                    }
                }
            }
            
            
        }
        return m.size()==0 ? -1 : m.begin()->second.top();
        
        
        
    }
};