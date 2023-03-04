class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // topological sort
        unordered_map<int, vector<int>> m;
        vector<int> indegree(n, 0);
        
        for(auto p:prerequisites){
            m[p[1]].push_back(p[0]);
            indegree[p[0]]+=1;
        }
        
        queue<int> q;
        int completed=0;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) {
                completed+=1;
                q.push(i);
            }
        }
        
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            for(auto v:m[u]){
                indegree[v]-=1;
                if(indegree[v]==0){
                    completed+=1;
                    q.push(v);
                }
            }
        }
        
        return completed==n;
    }
};