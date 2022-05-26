class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // topological sort
        map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        
        for(int i=0;i<prerequisites.size();i++){
            indegree[prerequisites[i][0]]+=1;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        queue<int> q;
        int z=0;
        
        for(int i=0;i<indegree.size();i++){
            if(indegree[i] == 0){
                q.push(i);
                z+=1;
            }
        }
        
        if(z==0) return false;
        
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            
            for(auto c:adj[f]){
                
                indegree[c]-=1;
                if(indegree[c]==0){
                    q.push(c);
                    z+=1;
                }
                
            }
            
        }
        
        if(z!=numCourses) return false;
        return true;
    }
};