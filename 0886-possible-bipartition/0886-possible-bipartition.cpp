
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // bipartition!!!!
        vector<int> color(n+1, 0);
        vector<vector<int>> adj(n+1);
        vector<bool> explored(n+1, false);
        
        for(int i=0;i<dislikes.size();i++){
            int x = dislikes[i][0], y=dislikes[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        queue<int> q;
        
        for(int i=1;i<=n;i++){
            if(!explored[i]){
                color[i] = 1;
                q.push(i);
                
                while(!q.empty()){
                    int u = q.front();
                    q.pop();
                    if(explored[u]) continue;
                    explored[u] = true;
                    
                    for(auto v:adj[u]){
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