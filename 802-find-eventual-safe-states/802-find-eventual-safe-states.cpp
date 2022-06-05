class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        map<int, vector<int>> adj;
        map<int, int> outdegree;
        int n = graph.size();
        queue<int> q;
        vector<bool> isSafe(n, false);
        
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
            
            isSafe[f]=true;
            
            for(auto c:adj[f]){
                outdegree[c]-=1;
                if(outdegree[c]==0){
                    q.push(c);
                }
            }
        }
        
        // VlogV + O(V+E), O(V+E)
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(isSafe[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};