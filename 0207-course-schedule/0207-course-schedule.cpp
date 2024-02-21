class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& nums) {
        vector<int> indegree(n, 0);
        queue<int> q;
        unordered_map<int, vector<int>> next;
        int totalCourses = 0;
        
        for(int i=0;i<nums.size();i++){
            indegree[nums[i][0]] +=1;
            next[nums[i][1]].push_back(nums[i][0]);
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                totalCourses+=1;
            }
        }
        
        if(q.size()==0){
            return false;
        }
        
        while(!q.empty()){
            auto course = q.front();
            q.pop();
            for(auto nextCourse:next[course]){
                indegree[nextCourse]-=1;
                if(indegree[nextCourse]==0){
                    totalCourses+=1;
                    q.push(nextCourse);
                }
            }
            
        }
        
        return totalCourses == n;
        
    }
};