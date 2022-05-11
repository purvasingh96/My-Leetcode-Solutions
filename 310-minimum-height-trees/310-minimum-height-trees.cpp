class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        queue<int> q;
        
        if(n<2){
            for(int i=0;i<n;i++){
                res.push_back(i);
            }
            return res;
        }
        
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]+=1;
            indegree[e[1]]+=1;
        }
        
        vector<int> leaves;
        
        for(int i=0;i<indegree.size();i++){
            if(indegree[i] == 1){
                q.push(i);
            }
        }
        
        int remainNodes = n;
        
        while(!q.empty()){
            
           int n = q.size();
            res.clear();
            
            while(n--){
                
                auto f = q.front();
                q.pop();
                
                res.push_back(f);
                
                for(auto c:adj[f]){
                    
                    indegree[c]-=1;
                    
                    if(indegree[c] == 1){
                        q.push(c);
                        
                    }
                    
                }
                
            }
            
        }
        
        
      
        return res;
        
    }
};