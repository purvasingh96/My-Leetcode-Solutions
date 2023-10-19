class MyComp{
public:
    bool operator()(const vector<int>& a, const vector<int>& b){
        // course, time, indegree
        return a[1] > b[1];
    }
};

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        //course, time, indegree
         int total=0;
        vector<int> indegree(n+1, 0);
        vector<int> maxTime(n+1, 0);
        unordered_map<int, vector<int>> adj;
        
        for(int i=0;i<relations.size();i++){
            indegree[relations[i][1]]+=1;
            adj[relations[i][0]].push_back(relations[i][1]);
        }
        
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                maxTime[i] = max(maxTime[i], time[i-1]);
                q.push(i);
            }
        }
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            for(auto x:adj[node]){
                indegree[x]-=1;
                maxTime[x] = max(maxTime[x], maxTime[node]+time[x-1]);
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }
        
        
        
        return *max_element(maxTime.begin(), maxTime.end());
    }
};