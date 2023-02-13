class Solution {
private:
    
    vector<int> bfs(int n,  unordered_map<int, vector<pair<int, int>>>& adj, vector<vector<int>>& visited){
        // red = 1, blue=0
        queue<vector<int>> q;
        q.push({0, 1, 0});
        q.push({0, 0, 0});
        vector<int> ans(n, -1);
        ans[0] =0;
        visited[0][0]=true;
        visited[0][1] = true;
        
        while(!q.empty()){
                auto f = q.front();
                q.pop();

                int parent = f[0], prevColor=f[1], dist=f[2];
                

                for(auto neighbor:adj[parent]){
                    
                    int node = neighbor.first, color = neighbor.second;
                    
                    if(color!=prevColor && !visited[node][color]){
                        visited[node][color] = 1;
                        q.push({node, color, dist+1});
                        if(ans[node]==-1) ans[node] = dist+1;
                    }
                    
                }
                
            
            
           
        }
        
        return ans;
    }
    
    
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        unordered_map<int, vector<pair<int, int>>> adj;
       
        
        for(auto r:redEdges) adj[r[0]].push_back({r[1], 1});
        for(auto b:blueEdges) adj[b[0]].push_back({b[1], 0});
      
        
         vector<vector<int>> visited(n, vector<int>(2, 0));
        
        return bfs(n, adj, visited);
        
    }
};