class Solution {
private:
    
    int dia=0;
    
public:
     int dfs(int node, int parent, unordered_map<int, vector<int>>& paths, int& ret) {
        if (paths[node].size() == 1 && paths[node][0] == parent) return 1;
        
        int first_max = 0, second_max = 0;
        for (const auto& it : paths[node]) {
            if (it == parent) continue;
            
            int child_res = dfs(it, node, paths, ret);
            
            if (child_res > first_max) {
                second_max = first_max;
                first_max = child_res;
            } else if (child_res > second_max) {
                second_max = child_res;
            }
            ret = max(ret, first_max + second_max);
        }
        return first_max + 1;
    }
    
    int treeDiameter(vector<vector<int>>& edges) {
        if(edges.size()==0) return 0;
        unordered_map<int, vector<int>> adj;
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int res = 0;
        dfs(edges[0][0], INT_MAX, adj, res);
        return res;
    }
};