class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if(graph.size()==1) return 0;
        int n = graph.size();
        
        queue<vector<int>> q;
        int endingmask = (1<<n) - 1;
        
        vector<vector<int>> seen(n, vector<int>(endingmask, false));
        
        for(int i=0;i<n;i++){
            int mask = 1<<i;
            q.push({i, mask});
            seen[i][mask] = true;
        }
        
        int level=0;
        
        while(!q.empty()){
            
            int s = q.size();
            
            for(int i=0;i<s;i++){
                
                auto f = q.front();
                q.pop();
                
                int node = f[0], mask = f[1];
                
                for(auto child:graph[node]){
                    int newmask = mask | (1<<child);
                    if(newmask == endingmask){
                        return 1+level;
                    }
                    
                    
                    if(!seen[child][newmask]){
                        seen[child][newmask] = true;
                        q.push({child, newmask});
                    }
                    
                }
                
                
            }
            
            level+=1;
            
            
        }
        
        return -1;
        
    }
};