class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        unordered_map<int, vector<int>> m;
        vector<int> indegree(n, 0);
        
        for(auto x:p){
            int u = x[1], v = x[0];
            m[u].push_back(v);
            indegree[v]+=1;
        }
        
        int c=0;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
                c+=1;
            }
        }
        
        if(q.size()==0) return false;
        
        while(!q.empty()){
            int node = q.front();q.pop();
            for(auto y:m[node]){
                indegree[y]-=1;
                if(indegree[y] == 0){
                    q.push(y);
                    c+=1;
                }
            } 
        }
        
        return c == n;
        
    }
};