class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        map<int, vector<int>> adj;
        vector<int> res;
        int num_zeros=0;
        queue<int> q;
        vector<int> indegree(numCourses, 0);
        
        for(auto p:prerequisites) {
            
            indegree[p[0]] +=1;
            adj[p[1]].push_back(p[0]);
            
        }
        
        for(int i=0;i<indegree.size();i++) {
            if(indegree[i]==0) {
                num_zeros += 1;
                q.push(i);
            }
        }
        
        if(num_zeros == 0) return res;
        
        while(!q.empty()) {
            
            int f = q.front();
            q.pop();
            res.push_back(f);
            
            for(auto c:adj[f]){
                
                indegree[c]-=1;
                
                if(indegree[c] == 0){
                    q.push(c);
                    num_zeros += 1;
                }
                
            }
            
        }
       
        if(num_zeros != numCourses){
            return {};
        }
        return res;
    }
};