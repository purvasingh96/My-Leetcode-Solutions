class Solution {
private:
    map<int, vector<int>> adj;
    vector<vector<int>> bridges;
    vector<int> disc, low, parent;
    int time;
public:
    void dfs(int node) {
        disc[node] = low[node] = time++;
        
        for(auto x:adj[node]) {
            
            if(disc[x] == -1) {
                parent[x]=node;
                dfs(x);
                
                low[node] = min(low[node], low[x]);
                
                if(low[x] > disc[node]) {
                    bridges.push_back({node, x});
                }
            } else if(parent[node]!=x) {
                low[node] = min(low[node], disc[x]);
            }
            
        }
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        disc.resize(n, -1);
        time=0;
        parent.resize(n, -1);
        low.resize(n, -1);
        
        for(auto x:connections) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        dfs(0);
        return bridges;
    }
};