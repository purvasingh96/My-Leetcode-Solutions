class Solution {
private:
    
    int dia=0;
    
public:
    int dfs(int node, int parent, int& res, map<int, vector<int>>& paths){
        if(paths[node].size()==1 && paths[node][0]==parent) return 1;
        
        int max1=0;
        int max2=0;
        
        for(auto c:paths[node]){
            
            if(c==parent) continue;
            
            int h = dfs(c, node, res, paths);
            
            if(h>max1){
                max2=max1;
                max1=h;
            } 
            
            else if(h>max2){
                max2=h;
            }
            
            res = max(res, (max1+max2));
        }
        return max1+1;
        
    }
    int treeDiameter(vector<vector<int>>& edges) {
        if(edges.size()==0) return 0;
        map<int, vector<int>> adj;
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int res = 0;
        dfs(edges[0][0], INT_MAX, res, adj);
        return res;
    }
};