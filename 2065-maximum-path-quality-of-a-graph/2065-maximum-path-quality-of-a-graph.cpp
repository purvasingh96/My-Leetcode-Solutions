class Solution {
private:
    void dfs(int time, int maxTime, int node, int score, int& maxScore, vector<int>& seen, vector<int>& values, vector<vector<pair<int, int>>>& graph) {
        
        if(time > maxTime) return;
        
        if(seen[node] == 0){
            score += values[node];
        }
        
        seen[node] += 1;
        
        if(node == 0) {
            maxScore = max(maxScore, score);
        }
        
        for(auto it:graph[node]){
            int new_time = time + it.second;
            int neighbor = it.first;
            dfs(new_time, maxTime, neighbor, score, maxScore, seen, values, graph);
        
        }
        
        seen[node]-=1;
    }
    
    
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<vector<pair<int, int>>> graph(n);
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        vector<int> seen(n, 0);
        
        int maxScore=INT_MIN;
       dfs(0, maxTime, 0, 0, maxScore, seen, values, graph);
        return maxScore;
    }
};