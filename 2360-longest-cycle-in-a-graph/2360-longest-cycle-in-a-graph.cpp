class Solution {
private:
    int max_;
    void dfs(int node, vector<int>& edges, vector<int>& dist_from_node, vector<bool>& visited, int len){
        
        if(!visited[node]){
            
            visited[node]=true;
            dist_from_node[node] = len;
            
            if(edges[node]!=-1){
                dfs(edges[node], edges, dist_from_node, visited, len+1);
            }
            
            dist_from_node[node] = -1;
        } else{
            
            if(dist_from_node[node]!=-1){
                max_ = max(max_, len-dist_from_node[node]);
            }
            
        }
        
    }
public:
    int longestCycle(vector<int>& edges) {
        max_=-1;
        int n = edges.size();
        
        vector<bool> visited(n, false);
        vector<int> dist_from_node(n, -1);
        
        for(int i=0;i<edges.size();i++){
            if(!visited[i]){
                dfs(i, edges, dist_from_node, visited, 0);
            }
        }
        
        return max_;
    }
};