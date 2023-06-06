class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<pair<int, int>> q;
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<int> color(n, -1);
        
        
        
        
    while(true){
        bool found=false;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                found=true;
                int curr_color=0;
                q.push({i, curr_color});
                color[i] = curr_color;
                
                while(!q.empty()){
                    auto f = q.front();q.pop();
                    int node = f.first, parent_color = f.second;
                    visited[node] = true;

                    int child_color = !parent_color;
                    for(auto child:graph[node]){
                        if(!visited[child]){
                            if(color[child] == parent_color) return false;
                            color[child] = child_color;
                            q.push({child, child_color});
                        }
                    }
                }
                
            }
        }
        if(!found) break;
    }
        
        
        return true;
        
    }
};