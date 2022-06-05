class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> indegree(n+1, 0);
        map<int, vector<int>> adj;
        queue<pair<int, int>> q;
        int ans=0;
        vector<int> ttc(n+1);
        
        for(auto r:relations){
            adj[r[0]].push_back(r[1]);
            indegree[r[1]]+=1;
        }
        
        for(int i=1;i<indegree.size();i++){
            if(indegree[i] == 0){
                q.push({i,0});
            }
        }
        
        while(!q.empty()){
            
            int s = q.size();
            
            auto f = q.front();
            q.pop();
            
            int totalTime = f.second + time[f.first-1];
            ttc[f.first] = totalTime;
            
            for(auto c:adj[f.first]){
                
                ttc[c] = max(ttc[c], totalTime);
                indegree[c]-=1;
                
                if(indegree[c]==0){
                    q.push({c, ttc[c]});
                }
                
            }
            
        }
        
        return *max_element(ttc.begin(), ttc.end());
        
    }
};