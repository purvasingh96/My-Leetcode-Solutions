class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n+1, 0);
        vector<vector<int>> graph(n+1);
        vector<bool> explored(n+1, false);
        
        for(int i=0;i<dislikes.size();i++){
            int u = dislikes[i][0], v=dislikes[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        queue<int> q;
        
        for(int i=1;i<=n;i++){
            if(!explored[i]){
                color[i] = 1;
                q.push(i);
                
                while(!q.empty()){
                    
                    auto u = q.front();
                    q.pop();
                    
                    if(explored[u]) continue;
                    explored[u] = true;
                    
                    for(auto v:graph[u]){
                        if(color[u] == color[v]){
                            return false;
                        }
                        color[v] = color[u]*-1;
                        q.push(v);
                    }
                    
                }
                
            }
        }
        return true;
    }
};