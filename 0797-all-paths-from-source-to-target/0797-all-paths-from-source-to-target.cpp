class Solution {
private:
    void dfs(int node, int end, vector<vector<int>>& graph, vector<int>& temp, vector<vector<int>>& res){
    
        if(node == end){
            res.push_back(temp);
            return;
        }
        
        for(auto x:graph[node]){
            temp.push_back(x);
            dfs(x, end, graph, temp, res);
            temp.pop_back();
        }
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp = {0};
        vector<vector<int>> res;
        int n = graph.size();
        dfs(0, n-1, graph, temp, res);
        return res;
    }
};