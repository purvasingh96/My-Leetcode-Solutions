class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& nums) {
        vector<int> indegree(n+1, 0);
        int semesters = 0, numz=0;
        map<int, vector<int>> adj;
        
        for(int i=0;i<nums.size();i++){
            
            adj[nums[i][0]].push_back(nums[i][1]);
            indegree[nums[i][1]] += 1;
            
        }
        
        
        
        // {course, semester}
        queue<pair<int, int>> q;
        
        for(int i=1;i<=n;i++){
            if(indegree[i] == 0) {
                q.push({i, 1});
                numz+=1;
            }
        }
        
        if(numz==0) return -1;
        
        while(!q.empty()){
            
            auto f = q.front();
            q.pop();
            
            semesters = f.second;
            
            for(auto c:adj[f.first]) {
                
                indegree[c]-=1;
                
                if(indegree[c] == 0) {
                    q.push({c, f.second+1});
                    numz+=1;
                }
                
            }
            
        }
        
        if(numz!=n) return -1;
        
        return semesters;
    }
};