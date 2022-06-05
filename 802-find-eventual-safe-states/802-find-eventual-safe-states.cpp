class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        map<int, vector<int>> adj;
        map<int, int> outdegree;
        int n = graph.size();
        queue<int> q;
        vector<int> res;
        
        for(int i=0;i<n;i++){
            outdegree[i] += graph[i].size();
            
            for(int j=0;j<graph[i].size();j++){
                
                adj[graph[i][j]].push_back(i);
                
                
            }
        }
        
        for(int i=0;i<n;i++){
         if(outdegree[i]==0){
             q.push(i);
         }   
        }
        
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            
            res.push_back(f);
            
            for(auto c:adj[f]){
                outdegree[c]-=1;
                if(outdegree[c]==0){
                    q.push(c);
                }
            }
        }
        
        sort(res.begin(), res.end());
        return res;
    }
};