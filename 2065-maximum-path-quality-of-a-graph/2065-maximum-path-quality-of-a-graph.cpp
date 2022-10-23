class Solution {
private:
    void dfs(vector<vector<pair<int, int>>>& graph, vector<int>& values, vector<int>& visited, int& maxScore, int node, int score, int time, int& maxTime){
        
        if(time > maxTime) return;
        
        if(visited[node] == 0){
            score += values[node];
        }
        
        visited[node]+=1;
        
        if(node == 0) {
            maxScore = max(maxScore, score);
        }
        
        for(auto it: graph[node]){
            int new_time = time + it.second;
            int neighbor = it.first;
            dfs(graph, values, visited, maxScore, neighbor, score, new_time, maxTime);
        }
        
        visited[node] -=1;
        
    }
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<vector<pair<int, int>>> graph(n); 
        
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        
        vector<int> visited(n, 0);
        int maxScore = values[0];
        dfs(graph, values, visited, maxScore,0, 0, 0, maxTime);
        return maxScore;
        
    }
};