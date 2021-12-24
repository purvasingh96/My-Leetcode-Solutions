class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        /*  Hint: Pre-requisite graph => topological sort
            Pseudo Code:
                - build the indegree, adj list
                - use queue to keep track of courses with indegree 0
                - indegree-1 for neighbouring courses
                    - if indegree == 0:
                        - q.pop(), order.push(course)
                - return order
            TC:
            SC:
         */
        
        map<int, vector<int>> adj_list;
        vector<int> empty_array = {};
        map<int, int> indegree;
        vector<int> res;
        
        int zeros=0;
        queue<int> q;
        
        for(int i=0;i<numCourses;i++) {
            indegree[i]=0;
        }
        
        for(int i=0;i<prerequisites.size();i++) {
            
            indegree[prerequisites[i][0]]+=1;
            adj_list[prerequisites[i][1]].push_back(prerequisites[i][0]);
            
        }
        
        for(auto i:indegree) {
            if(i.second == 0){
                zeros+=1;
                q.push(i.first);
            }
        }
        
        // no course exissts which doesnot have a pre-requisite
        if(zeros==0) return empty_array;
        
        while(!q.empty()) {
            
            auto top = q.front();
            q.pop();
            
            res.push_back(top);
            
            for(auto child:adj_list[top]) {
                
                indegree[child]-=1;
                
                if(indegree[child] == 0) {
                    q.push(child);
                    zeros+=1;
                }
            }
            
        }
        
        
        if(zeros!=numCourses) return empty_array;
        return res;
        
        
        
    }
};