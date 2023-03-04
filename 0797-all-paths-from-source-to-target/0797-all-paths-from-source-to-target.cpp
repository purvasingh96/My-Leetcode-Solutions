class Solution {
private:
    vector<vector<int>> bfs(vector<vector<int>>& adj, int src, int dst){
        queue<pair<int,vector<int>>> q;
        vector<vector<int>> res;
        q.push({src, {src}});
        
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            
            int node = f.first;
            vector<int> temp=f.second;
            
            if(node == dst) res.push_back(temp);
            
            for(auto neigh:adj[node]){
                
                    vector<int> t = temp;
                    t.push_back(neigh);
                    q.push({neigh, t});
                
            }
            
        }
        return res;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        return bfs(graph, 0, n-1);
    }
};