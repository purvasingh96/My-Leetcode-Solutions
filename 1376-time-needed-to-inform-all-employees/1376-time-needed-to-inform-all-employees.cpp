class Solution {
public:
    int numOfMinutes(int n, int head, vector<int>& manager, vector<int>& informTime) {
        queue<pair<int, int>> q;
        q.push({head, 0});
        int ans=INT_MIN;
        
        unordered_map<int,vector<int>> m;
        for(int i=0;i<n;i++){
            m[manager[i]].push_back(i);
        }
        
        
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            
            int parent = f.first, time = f.second;
            
            ans = max(ans, time);
            
            for(auto child:m[parent]){
                q.push({child, time+informTime[parent]});
            }
            
            
        }
        
        return ans;
    }
};